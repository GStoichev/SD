#include "stdafx.h"
#include "City.h"

City::City()
{
	this->factories = 0;
}
void City::load(char* name, int population, double area, int farmers)
{
	this->Settlement::load(name, population, area);
	this->factories = farmers;
}
void City::save()
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
	stream.write((char*)&this->factories, sizeof(this->factories));
	stream.close();
	delete[] temp;
}
void City::read(const char* file)
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
		std::cout << "File is not type City" << std::endl;
		stream.close();
		return;
	}
	this->Settlement::read(stream);
	stream.read((char*)&this->factories, sizeof(this->factories));
	stream.close();
}
void City::print()
{
	this->Settlement::print();
	std::cout << "City : " << this->factories << std::endl;
}