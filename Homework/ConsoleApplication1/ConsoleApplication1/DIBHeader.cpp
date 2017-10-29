#include "stdafx.h"
#include "DIBHeader.h"


//Constructors
DIBHeader::DIBHeader()
{
	this->size = NULL;
	this->width = NULL;
	this->heigth = NULL;
	this->plates = NULL;
	this->pixels = NULL;
	this->comperession = NULL;
	this->sizeRaw = NULL;
	this->horizontalResolution = NULL;
	this->verticalResolution = NULL;
	this->colorsInPlate = NULL;
	this->imporatantColors = NULL;
}
DIBHeader::DIBHeader(std::ifstream& istream)
{
	this->Load(istream);
}

//Methods
void DIBHeader::Load(std::ifstream& istream)
{
	try
	{
		istream.read((char*)&this->size, sizeof(this->size));
		istream.read((char*)&this->width, sizeof(this->width));
		istream.read((char*)&this->heigth, sizeof(this->heigth));
		istream.read((char*)&this->plates, sizeof(this->plates));
		istream.read((char*)&this->pixels, sizeof(this->pixels));
		istream.read((char*)&this->comperession, sizeof(this->comperession));
		istream.read((char*)&this->sizeRaw, sizeof(this->sizeRaw));
		istream.read((char*)&this->horizontalResolution, sizeof(this->horizontalResolution));
		istream.read((char*)&this->verticalResolution, sizeof(this->verticalResolution));
		istream.read((char*)&this->colorsInPlate, sizeof(this->colorsInPlate));
		istream.read((char*)&this->imporatantColors, sizeof(this->imporatantColors));
	}
	catch (const std::exception&)
	{
		std::cout << "Error at reading data from file !" << std::endl;
		return;
	}
	
}
void DIBHeader::Update(const int width,const int heigth)
{
	this->width = width;
	this->heigth = heigth;
}
void DIBHeader::Save(std::ostream& ostream)
{
	try
	{
		ostream.write((char*)&this->size, sizeof(this->size));
		ostream.write((char*)&this->width, sizeof(this->width));
		ostream.write((char*)&this->heigth, sizeof(this->heigth));
		ostream.write((char*)&this->plates, sizeof(this->plates));
		ostream.write((char*)&this->pixels, sizeof(this->pixels));
		ostream.write((char*)&this->comperession, sizeof(this->comperession));
		ostream.write((char*)&this->sizeRaw, sizeof(this->sizeRaw));
		ostream.write((char*)&this->horizontalResolution, sizeof(this->horizontalResolution));
		ostream.write((char*)&this->verticalResolution, sizeof(this->verticalResolution));
		ostream.write((char*)&this->colorsInPlate, sizeof(this->colorsInPlate));
		ostream.write((char*)&this->imporatantColors, sizeof(this->imporatantColors));
	}
	catch (const std::exception&)
	{
		std::cout << "Error at writing data " << std::endl;
		return;
	}
	
}

//Getters
int DIBHeader::GetSize() const
{
	return this->size;
}
int DIBHeader::GetWidth() const
{
	return this->width;
}
int DIBHeader::GetHeigth() const
{
	return this->heigth;
}
int DIBHeader::GetSPlates() const
{
	return this->plates;
}
int DIBHeader::GetPixels() const
{
	return this->pixels;
}
int DIBHeader::GetCompression() const
{
	return this->comperession;
}
int DIBHeader::GetSizeRaw() const
{
	return this->sizeRaw;
}
int DIBHeader::GetHorizontalResolution() const
{
	return this->horizontalResolution;
}
int DIBHeader::GetVerticalResolution() const
{
	return this->verticalResolution;
}
int DIBHeader::GetColorInPlate() const
{
	return this->colorsInPlate;
}
int DIBHeader::GetImportantColor() const
{
	return this->imporatantColors;
}

