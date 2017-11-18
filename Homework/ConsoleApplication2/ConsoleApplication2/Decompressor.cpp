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
void Decompressor::Decompress()
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
	while (this->compressed[curPos] != '\0')
	{
		if (this->compressed[curPos] == '\\')
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
				std::cout << "Didn't have operator before bracket" << std::endl;
				return;	
		}
		if (this->compressed[curPos] >= '0' && this->compressed[curPos] <= '9')
		{
			while (this->compressed[curPos] >= '0' && this->compressed[curPos] <= '9')
			{
				number.PushBack(this->compressed[curPos]);
				curPos++;
			}
			if (this->compressed[curPos] != '(')
			{
				std::cout << "Error : Didn't have bracket after operator!" << std::endl;
				return;
			}

			int num = 0;
			while (!number.Empty())
			{
				num *= 10;
				num += number.Front() - '0';
				number.PopFront();
			}
			if (num == 0)
			{
				flag = true;
				curPos++;
			}
			else
			{
				operators.Push(--num);
				curPos++;
				int CopyOfCurrentPosition = curPos;
				positions.Push(CopyOfCurrentPosition);
			}
		}
		if (this->compressed[curPos] == ')')
		{	
			if (flag)
			{
				flag = false;
				curPos++;
			}
			else
			{
				if (operators.Top() == 0)
				{
					curPos++;
					operators.Pop();
					positions.Pop();
				}
				else
				{
					--operators.Top();
					curPos = positions.Top();
				}
			}
			
		}
		if (flag)
		{
			curPos++;
		}
		else
		{
			this->decompressed.PushBack(this->compressed[curPos]);
			curPos++;
		}
	}
	number.Clear();
	while (!operators.Empty())
	{
		operators.Pop();
		positions.Pop();
	}
	this->decompressed.Print();
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
//Getters & Setters
char* Decompressor::GetCompressed() const
{
	return this->compressed;
}
//Private methods
void Decompressor::GetCompressed(const char* file,char*& buffer)
{

	std::ifstream stream(file, std::ios::in);
	if (!stream)
	{
		std::cout << "Error : Can't load file " << file << std::endl;
		return;
	}
	int length = 0;
	char c;
	while (stream.get(c))
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
	buffer = new char[length + 1];
	stream.getline(buffer, length);
	buffer[length] = '\0';
	stream.close();

}
void Decompressor::CopyString(char*& str,const char* source)
{
	int length = 0;
	while (source[length++] != '\0');
	str = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		str[i] = source[i];
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
			bracketCounter++;
		}
		else if (this->compressed[curPos] == ')')
		{
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
