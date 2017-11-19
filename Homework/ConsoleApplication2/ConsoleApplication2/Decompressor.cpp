#include "stdafx.h"
#include "Decompressor.h"

//Constructors
Decompressor::Decompressor()
{
	this->destination = nullptr;
	this->source = nullptr;
	this->compressed = nullptr;
}
Decompressor::Decompressor(const char* source)
{
	this->LoadFile(source);
}
Decompressor::Decompressor(const char* source, const char* destination)
{
	this->LoadFile(source, destination);
}
//Methods
void Decompressor::LoadFile(const char* source)
{
	if (this->source != nullptr)
	{
		delete[] this->source;
	}
	this->CopyString(this->source,source);
	this->GetCompressed(this->source, this->compressed);
	this->destination = nullptr;
}
void Decompressor::LoadFile(const char* source, const char* destination)
{
	if (this->source != nullptr)
	{
		delete[] this->source;
	}
	this->CopyString(this->source, source);
	if (this->destination != nullptr)
	{
		delete[] this->destination;
	}
	this->CopyString(this->destination, destination);
	this->GetCompressed(this->source, this->compressed);
}
void Decompressor::Decompress() //Yea I know, too long function, but now I don't have time to devide her to separate functions. Better to work fine and look poor, then look great and work bad! 
{
	if (!(this->decompressed.Empty()))
	{
		this->decompressed.Clear();
	}
	if (this->compressed == nullptr)
	{
		std::cout << "Compressed date is not load" << std::endl;
		return;
	}
	if (!this->CorrectBrackets())
	{
		std::cout << "Brakets are incorrect" << std::endl;
		return;
	}
	size_t curPos = 0;
	Stack<int> operators;
	Stack<int> positions;
	Queue<char> number;
	bool flag = false;
	int zeroes = 0; //used for  multy zeros handler
	while (this->compressed[curPos] != '\0')
	{
		if (this->compressed[curPos] == '\\') //Ignoring special symbols by using '\'
		{
			if (this->compressed[curPos + 1] != '\0')
			{
				this->decompressed.PushBack(this->compressed[curPos + 1]);
				curPos += 2;
				continue;
			}
		}
		if (this->compressed[curPos] == '(') 
		{
			if (curPos != 0)
			{
				if (this->compressed[curPos - 1] == '\\')
				{
					curPos++;
					continue;
				}
			}
				std::cout << "Didn't have operator before bracket" << std::endl;
				return;	
		}
		if (this->compressed[curPos] >= '0' && this->compressed[curPos] <= '9')
		{
			while (this->compressed[curPos] >= '0' && this->compressed[curPos] <= '9') //Find and save numbers
			{
				number.PushBack(this->compressed[curPos]);
				curPos++;
			}
			if (this->compressed[curPos] != '(')
			{
				if (this->compressed[curPos] == '\\')
				{
					continue;
				}
				std::cout << "Error : Didn't have bracket after operator!" << std::endl;
				return;
			}

			int num = 0;
			while (!number.Empty()) // Convert char number to integer number
			{
				num *= 10;
				num += number.Front() - '0';
				number.PopFront();
			}
			if (num == 0) 
			{
				if (flag) // if already we have number 0 in stack
				{
					zeroes++;
					curPos++;
					continue;
				}
				flag = true;
				operators.Push(--num);
				curPos++;
				int FakeCopy = 0;
				positions.Push(FakeCopy);
				if (this->compressed[curPos] >= '0' && this->compressed[curPos] <= '9')
				{
					continue;
				}
				if (this->compressed[curPos] == '\\')
				{
					continue;
				}
			}
			else
			{
				operators.Push(--num);
				curPos++;
				int CopyOfCurrentPosition = curPos;
				positions.Push(CopyOfCurrentPosition);
				if (this->compressed[curPos] >= '0' && this->compressed[curPos] <= '9')
				{
					continue;
				}
				if (this->compressed[curPos] == '\\')
				{
					continue;
				}
			}
		}
		if (this->compressed[curPos] == ')')
		{	
			bool flag_2 = false; // Used to ensure when to run second if
			if (flag) //If in operators have value which is equal to -1
			{
				if (operators.Top() == -1) 
				{
					if (zeroes != 0) // multy zero handler
					{
						zeroes--;
						curPos++;
						continue;
					}

					flag = false; //remove -1 value from operators
					flag_2 = true; // dissable second if
					curPos++;
					operators.Pop();
					positions.Pop();
					if (this->compressed[curPos] == ')')
					{
						continue;
					}
					if (this->compressed[curPos] >= '0' && this->compressed[curPos] <= '9')
					{
						continue;
					}
					if (this->compressed[curPos] == '\\')
					{
						continue;
					}
				}
			}
			if (!flag_2)
			{
				if (operators.Top() == 0) // Removing top elements from stacks
				{
					curPos++;
					operators.Pop();
					positions.Pop();
					if (this->compressed[curPos] == ')')
					{
						continue;
					}
					if (this->compressed[curPos] >= '0' && this->compressed[curPos] <= '9')
					{
						continue;
					}
					if (this->compressed[curPos] == '\\')
					{
						continue;
					}
				}
				else //Decrease value on top of operators with one and returns interator at rigth position(top of stack positions) 
				{
					--operators.Top();
					curPos = positions.Top();
					if (this->compressed[curPos] == ')')
					{
						continue;
					}
					if (this->compressed[curPos] >= '0' && this->compressed[curPos] <= '9')
					{
						continue;
					}
					if (this->compressed[curPos] == '\\')
					{
						continue;
					}
				}
			}
			
		}
		if (flag) //If in operators have value which is equal to -1 then did't add symbols to decompressed queue
		{
			curPos++;
		}
		else //Add current symbol to decompressed queue
		{
			this->decompressed.PushBack(this->compressed[curPos]);
			curPos++;
		}
	}
	number.Clear(); //Clear number queue for savety
	while (!operators.Empty()) //Clearing stacks for safety
	{
		operators.Pop();
		positions.Pop();
	}
}
void Decompressor::Decompress(const char* destination)
{
	if (this->destination != nullptr)
	{
		delete[] this->destination;
	}
	this->CopyString(this->destination, destination);
	this->Decompress();
}
void Decompressor::Save()
{
	if (this->destination == nullptr)
	{
		std::cout << "Error : Plese choise destination where to save file" << std::endl;
		return;
	}
	std::ofstream stream(this->destination, std::ios::out);
	if (!stream)
	{
		std::cout << "Error : Problem at saving file " << this->destination << std::endl;
		return;
	}
	while (!this->decompressed.Empty()) //Writhing data in file
	{
		stream.put(this->decompressed.Front());
		this->decompressed.PopFront();
	}
	stream.close();
}
void Decompressor::Save(const char* destination)
{
	if (this->destination != nullptr)
	{
		delete[] this->destination;
	}
	this->CopyString(this->destination, destination);
	this->Save();
}
//Private methods
void Decompressor::GetCompressed(const char* file,char*& buffer)
{

	std::ifstream stream(file, std::ios::in);
	if (!stream)
	{
		std::cout << "Error : Can't load file " << file << std::endl;
		buffer = nullptr;
		return;
	}
	int length = 0;
	char c;
	while (stream.get(c)) //Find length of first line
	{

		length++;
		if (c == '\n')
		{
			break;
		}
		if ((int)stream.tellg() == -1)
		{
			break;
		}
	}
	if ((int)stream.tellg() == -1)
	{
		stream.clear();
		stream.seekg(0);
		length++;

	}
	stream.seekg(0);
	try // get first line and save it in buffer
	{
		buffer = new char[length + 1];
		stream.getline(buffer, length);
		buffer[length] = '\0';
	}
	catch (const std::bad_alloc&)
	{
		buffer = nullptr;
		std::cout << "Error : Can't allocate memory " << std::endl;
		stream.close();
		return;
	}
	catch (const std::exception&)
	{
		buffer = nullptr;
		std::cout << "Error : Unknown at Decompressor at function GetCompressed(const char* file,char*& buffer) " << std::endl;
		stream.close();
		return;
	}
	stream.close();

}
void Decompressor::CopyString(char*& str,const char* source)
{

	int length = 0;
	while (source[length++] != '\0'); // Find length of string
	try // Copy string to buffer(str)
	{
		str = new char[length];
		for (size_t i = 0; i < length; i++)
		{
			str[i] = source[i];
		}
	}
	catch (const std::bad_alloc&)
	{
		str = nullptr;
		std::cout << "Error :  Can't allocate memory " << std::endl;
		return;
	}
	catch (const std::exception&)
	{
		str = nullptr;
		std::cout << "Error :  Unknown at Decompressor at function CopyString" << std::endl;
		return;
	}
	
}
bool Decompressor::CorrectBrackets()
{
	int bracketCounter = 0;
	int curPos = 0;
	while (this->compressed[curPos] != '\0')
	{
		if (bracketCounter < 0)
		{
			return false;
		}
		if (this->compressed[curPos] == '(')
		{
			if (curPos != 0)
			{
				if (this->compressed[curPos - 1] == '\\')
				{
					curPos++;
					continue;
				}
			}
			bracketCounter++;
		}
		else if (this->compressed[curPos] == ')')
		{
			if (curPos != 0)
			{
				if (this->compressed[curPos - 1] == '\\')
				{
					curPos++;
					continue;
				}
			}
			bracketCounter--;
		}
		curPos++;
	}
	if (bracketCounter != 0)
	{
		return false;
	}
	return true;
}
//Destructor
Decompressor::~Decompressor()
{
	delete[] this->source;
	delete[] this->destination;
	delete[] this->compressed;
	this->decompressed.Clear();
}
