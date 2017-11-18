#include "stdafx.h"
#include "PixelArray.h"


//Constructors
PixelArray::PixelArray()
{
	this->sizeOfBuffer = 0;
	this->buffer = nullptr;
}
PixelArray::PixelArray(std::ifstream& istream,const size_t size)
{
	this->sizeOfBuffer = size;
	try
	{
		this->buffer = new char[this->sizeOfBuffer];
		istream.read(this->buffer, this->sizeOfBuffer);
	}
	catch (const std::exception&)
	{
		std::cout << "Error at loading buffer or reading data" << std::endl;
	}
}
PixelArray::PixelArray(const PixelArray& arr)
{
	this->CopyFunc(arr);
}

//Methods
void PixelArray::Save(std::ostream& ostream)
{
	try
	{
		ostream.write(this->buffer, this->sizeOfBuffer);
	}
	catch (const std::exception&)
	{
		std::cout << "Error at writhing in file!" << std::endl;
		return;
	}
	
}
PixelArray& PixelArray::Update(char* buffer,int sizeOfBuffer)
{
	

	this->sizeOfBuffer = sizeOfBuffer;
	delete[] this->buffer;
	this->buffer = new char[this->sizeOfBuffer];
	for (size_t i = 0; i < this->sizeOfBuffer; i++)
	{
		this->buffer[i] = buffer[i];
	}
	return *this;
}

//Operators
PixelArray& PixelArray::operator=(const PixelArray& arr)
{
	if (this != &arr)
	{
		delete[] this->buffer;
		this->CopyFunc(arr);
	}
	return *this;
}

//Getgers
char* PixelArray::GetBuffer() const
{
	return this->buffer;
}
int PixelArray::GetSize() const
{
	return this->sizeOfBuffer;
}

//Private methods
void PixelArray::CopyFunc(const PixelArray& arr)
{
	try
	{
		this->sizeOfBuffer = arr.sizeOfBuffer;
		this->buffer = new char[this->sizeOfBuffer];
		for (size_t i = 0; i < this->sizeOfBuffer; i++)
		{
			this->buffer[i] = arr.buffer[i];
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Problem at copy constructor, maybe not enoght RAM" << std::endl;
		return;
	}
	
}

//Destructor
PixelArray::~PixelArray()
{
	delete[] this->buffer;
}
