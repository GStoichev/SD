#include "stdafx.h"
#include "IOFile.h"

IOFile::IOFile()
{
	char* name = nullptr;
	
}
IOFile::IOFile(const char* name)
{

	//Finding length of name with determinanting symbol
	int length = 0;
	while (name[length++] != '\0');

	//copy name to this->name with determining zero
	this->name = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->name[i] = name[i];
	}


}
char* IOFile::ReadFile() const
{
	std::ifstream ifstream(this->name, std::ios::in | std::ios::app);
	int sizeOfBuffer = 4;
	int bufferCurrentPlace = 0;
	//std::cout << ifstream.gcount() << std::endl;
	char* buffer = new char[sizeOfBuffer];
	
	if (ifstream.is_open()) // checking is stream open
	{
		char c;
		while (ifstream.get(c))//Checking is character not null
		{
			
			if (bufferCurrentPlace >= sizeOfBuffer)
			{
				sizeOfBuffer *= 2;
				char* temp = new char[sizeOfBuffer];
				for (size_t i = 0; i < bufferCurrentPlace; i++)
				{
					temp[i] = buffer[i];
				}
				delete[] buffer;
				buffer = temp;
			}
				buffer[bufferCurrentPlace++] = c;	
		}
		buffer[bufferCurrentPlace] = '\0';
	}
	else
	{
		std::cout << "Input stream in file \"" << this->name << "\" is not open!";
	}	
	ifstream.close();
	return buffer;
}
char* IOFile::ReadFile(const char* name)
{
	if (this->name != nullptr || this->name != name)
	{
		delete[] this->name;
	}
	//Finding length of name with determinanting symbol
	int length = 0;
	while (name[length++] != '\0');

	//copy name to this->name with determining zero
	this->name = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->name[i] = name[i];
	}


	std::ifstream ifstream(this->name, std::ios::in | std::ios::app);
	int sizeOfBuffer = 4;
	int bufferCurrentPlace = 0;
	//std::cout << ifstream.gcount() << std::endl;
	char* buffer = new char[sizeOfBuffer];

	if (ifstream.is_open()) // checking is stream open
	{
		char c;
		while (ifstream.get(c))//Checking is character not null
		{

			if (bufferCurrentPlace >= sizeOfBuffer)
			{
				sizeOfBuffer *= 2;
				char* temp = new char[sizeOfBuffer];
				for (size_t i = 0; i < bufferCurrentPlace; i++)
				{
					temp[i] = buffer[i];
				}
				delete[] buffer;
				buffer = temp;
			}
			buffer[bufferCurrentPlace++] = c;
		}
		buffer[bufferCurrentPlace] = '\0';
	}
	else
	{
		std::cout << "Input stream at file \"" << this->name << "\" is not open!";
	}
	ifstream.close();
	return buffer;
}
void IOFile::WriteInFile(const char* data)
{
	std::ofstream ofstream(this->name, std::ios::out | std::ios::app);
	if (ofstream.is_open())
	{
		ofstream << data;

		ofstream.close();
	}
	else
	{
		std::cout << "Output stream at file \"" << this->name << "\" is not open!";
	}
}
void IOFile::WriteInFile(const char* name, const char* data)
{
	if (this->name != nullptr || this->name != name)
	{
		delete[] this->name;
	}
	//Finding length of name with determinanting symbol
	int length = 0;
	while (name[length++] != '\0');

	//copy name to this->name with determining zero
	this->name = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->name[i] = name[i];
	}

	std::ofstream ofstream(this->name, std::ios::out | std::ios::app);
	if (ofstream.is_open())
	{
		ofstream << data;

		ofstream.close();
	}
	else
	{
		std::cout << "Output stream in file \"" << this->name << "\" is not open!";
	}

}
void IOFile::TransferData(const char* to)
{
	std::ifstream ifstream(this->name, std::ios::in | std::ios::app);
	int sizeOfBuffer = 4;
	int currentSize = 0;
	char* buffer = new char[sizeOfBuffer];
	buffer[0] = '\0';
	char c;
	if (ifstream.is_open())
	{
		while (ifstream.get(c))
		{
			if (sizeOfBuffer <= currentSize)
			{
				sizeOfBuffer *= 2;
				char* temp = new char[sizeOfBuffer];
				for (size_t i = 0; i < currentSize; i++)
				{
					temp[i] = buffer[i];
				}
				delete[] buffer;
				buffer = temp;

			}

			buffer[currentSize++] = c;
		}
		buffer[currentSize] = '\0';
	}
	else
	{
		std::cout << "Input stream at file \"" << this->name << "\" is not open!";
	}
	ifstream.close();

	std::ofstream ofstream(to, std::ios::out | std::ios::app);
	if (ofstream.is_open())
	{
		ofstream << buffer;

		ofstream.close();
	}
	else
	{
		std::cout << "Output stream at file \"" << to << "\" is not open!";
	}
	

}
void IOFile::TransferData(const char* from, const char* to)
{
	if (this->name != nullptr || this->name != from)
	{
		delete[] this->name;
	}
	//Finding length of name with determinanting symbol
	int length = 0;
	while (from[length++] != '\0');

	//copy name to this->name with determining zero
	this->name = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->name[i] = from[i];
	}

	std::ifstream ifstream(this->name, std::ios::in | std::ios::app);
	int sizeOfBuffer = 4;
	int currentSize = 0;
	char* buffer = new char[sizeOfBuffer];
	buffer[0] = '\0';
	char c;
	if (ifstream.is_open())
	{
		while (ifstream.get(c))
		{
			if (sizeOfBuffer <= currentSize)
			{
				sizeOfBuffer *= 2;
				char* temp = new char[sizeOfBuffer];
				for (size_t i = 0; i < currentSize; i++)
				{
					temp[i] = buffer[i];
				}
				delete[] buffer;
				buffer = temp;

			}

			buffer[currentSize++] = c;
		}
		buffer[currentSize] = '\0';
	}
	else
	{
		std::cout << "Input stream at file \"" << this->name << "\" is not open!";
	}
	ifstream.close();

	std::ofstream ofstream(to, std::ios::out | std::ios::app);
	if (ofstream.is_open())
	{
		ofstream << buffer;
		ofstream.close();
	}
	else
	{
		std::cout << "Output stream at file \"" << to << "\" is not open!";
	}

}
IOFile::~IOFile()
{
	delete[] this->name;
}
