#include "stdafx.h"
#include "Capitol.h"

Capitol::Capitol()
{
	this->lengthOfCountry = 0;
	this->country = nullptr;
}
void Capitol::load(char* name, int population, double area, char* country)
{
	this->Settlement::load(name, population, area);
	if (country != nullptr)
	{
		this->lengthOfCountry = 0;
		delete[] this->country;
	}
	while (country[this->lengthOfCountry++] != '\0');
	this->country = new char[this->lengthOfCountry];
	for (size_t i = 0; i < this->lengthOfCountry; i++)
	{
		this->country[i] = country[i];
	}
}
void Capitol::save()
{
	char* temp = new char[this->getLengthOfName() + 4];
	for (size_t i = 0; i < this->getLengthOfName(); i++)
	{
		temp[i] = this->name[i];
	}
	temp[this->getLengthOfName() - 1] = '.';
	temp[this->getLengthOfName() + 0] = 'b';
	temp[this->getLengthOfName() + 1] = 'i';
	temp[this->getLengthOfName() + 2] = 'n';
	temp[this->getLengthOfName() + 3] = '\0';
	std::ofstream stream(temp, std::ios::out | std::ios::binary);
	if (!stream)
	{
		std::cout << "file " << temp << " can't be created" << std::endl;
		delete[] temp;
		return;
	}
	stream.write((char*)&this->header, sizeof(this->header));
	this->Settlement::save(stream);
	stream.write((char*)&this->lengthOfCountry, sizeof(this->lengthOfCountry));
	stream.write(this->country, this->lengthOfCountry);
	stream.close();
	delete[] temp;
}
void Capitol::read(const char* file)
{
	std::ifstream stream(file, std::ios::in | std::ios::binary);
	if (!stream)
	{
		std::cout << "file " << file << " can't be loaded" << std::endl;
		return;
	}
	char temp;
	stream.read((char*)&temp, sizeof(temp));
	if (temp != this->header)
	{
		std::cout << "File is not type Capitol" << std::endl;
		stream.close();
		return;
	}
	this->Settlement::read(stream);
	if (this->country != nullptr)
	{
		this->lengthOfCountry = 0;
		delete[] this->country;
	}
	stream.read((char*)&this->lengthOfCountry, sizeof(this->lengthOfCountry));
	this->country = new char[this->lengthOfCountry];
	stream.read(this->country, this->lengthOfCountry);
	stream.close();
}
void Capitol::print()
{
	this->Settlement::print();
	std::cout << "Country : " << this->country << std::endl;
}
Capitol::~Capitol()
{
	delete[] this->country;
}