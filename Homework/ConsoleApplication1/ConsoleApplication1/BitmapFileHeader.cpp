
#include "stdafx.h"
#include "BitmapFileHeader.h"

//Constructors
BitmapFileHeader::BitmapFileHeader()
{
	this->identifyer[0] = NULL;
	this->identifyer[1] = NULL;
	this->offset = NULL;
	this->reserved1 = NULL;
	this->reserved2 = NULL;
	this->size = NULL;
}
BitmapFileHeader::BitmapFileHeader(std::ifstream& istream)
{
	this->Load(istream);
}

//Methods
void BitmapFileHeader::Update(const int size)
{
	this->size = size;
}
void BitmapFileHeader::Load(std::ifstream& istream)
{
	try
	{
		istream.read(this->identifyer, sizeof(this->identifyer));
		istream.read((char*)&this->size, sizeof(this->size));
		istream.read((char*)&this->reserved1, sizeof(this->reserved1));
		istream.read((char*)&this->reserved2, sizeof(this->reserved2));
		istream.read((char*)&this->offset, sizeof(this->offset));
	}
	catch (const std::exception&)
	{
		std::cout << "Error at reading data from file !" << std::endl;
		return;
	}
	
}
void BitmapFileHeader::Save(std::ofstream& ostream)
{
	try
	{
		ostream.write(this->identifyer, sizeof(this->identifyer));
		ostream.write((char*)&this->size, sizeof(this->size));
		ostream.write((char*)&this->reserved1, sizeof(this->reserved1));
		ostream.write((char*)&this->reserved2, sizeof(this->reserved2));
		ostream.write((char*)&this->offset, sizeof(this->offset));

	}
	catch (const std::exception&)
	{
		std::cout << "Error at writhing data " <<std::endl;
		return;
	}

}
bool BitmapFileHeader::CheckFormat()
{
	//Check did first 2 symbols are BM, BA, CI, CP, IC, PT (BM windows format)
	switch (this->identifyer[0])
	{
	case 'B':
		if (this->identifyer[1] == 'M' || this->identifyer[1] == 'A')
			return true;
		break;
	case 'C':
		if (this->identifyer[1] == 'I' || this->identifyer[1] == 'P')
			return true;
		break;
	case 'I':
		if (this->identifyer[1] == 'C')
			return true;
		break;
	case 'P':
		if (this->identifyer[1] == 'T')
			return true;
		break;
	default:
		return false;
		break;
	}
	return false;

}

//Getters
int BitmapFileHeader::GetSize() const
{
	return this->size;
}
int BitmapFileHeader::GetOffSet() const
{
	return this->offset;
}
