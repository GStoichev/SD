#include "stdafx.h"
#include "BitmapFileHeader.h"

BitmapFileHeader::BitmapFileHeader()
{
	this->identifyer[0] = NULL;
	this->identifyer[1] = NULL;
	this->size = NULL;
	this->reserved1 = NULL;
	this->reserved2 = NULL;
	this->positionPixelArray = NULL;
}
BitmapFileHeader::BitmapFileHeader(char* name)
{
	this->Load(name);
}
void BitmapFileHeader::Load(char* name)
{
	std::ifstream file(name, std::ios::in | std::ios::binary);
	if (!file)
	{
		std::cout << "File didn't load" << std::endl;
	}
	else
	{
		file.read(this->identifyer, sizeof(this->identifyer));
		file.read((char*)&this->size, sizeof(this->size));
		file.read((char*)&this->reserved1, sizeof(this->reserved1));
		file.read((char*)&this->reserved2, sizeof(this->reserved2));
		file.read((char*)&this->positionPixelArray, sizeof(this->positionPixelArray));
	}
	
}
int BitmapFileHeader::getSize()
{
		return this->size;
}
int BitmapFileHeader::getPositionPixelArray()
{
	return this->positionPixelArray;
}
bool BitmapFileHeader::CheckIdetifyer()
{
	if (this->identifyer[0] == 'B')
	{
		if (this->identifyer[1] == 'M' || this->identifyer[1] == 'A')
		{
			return true;
		}
		return false;
	}
	else if (this->identifyer[0] == 'C')
	{
		if (this->identifyer[1] == 'I' || this->identifyer[1] == 'P')
		{
			return true;
		}
		return false;
	}
	else if (this->identifyer[0] == 'I')
	{
		if (this->identifyer[1] == 'C')
		{
			return true;
		}
		return false;
	}
	else if (this->identifyer[0] == 'P')
	{
		if (this->identifyer[1] == 'T')
		{
			return true;
		}
		return false;
	}
}