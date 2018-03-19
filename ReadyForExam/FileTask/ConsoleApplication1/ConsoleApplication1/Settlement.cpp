#include "stdafx.h"
#include "Settlement.h"

//Constructor
Settlement::Settlement()
{
	this->name = nullptr;
	this->area = 0;
	this->population = 0;
	this->lenthOfName = 0;
}
void Settlement::load(char* name, int population, double area)
{
	if (this->name != nullptr)
	{
		this->lenthOfName = 0;
		delete[] this->name;
	}
	while (name[this->lenthOfName++] != '\0');
	this->name = new char[this->lenthOfName];
	for (size_t i = 0; i < this->lenthOfName; i++)
	{
		this->name[i] = name[i];
	}
	this->population = population;
	this->area = area;	
}
void Settlement::save(std::ofstream& stream)
{
	stream.write((char*)&this->lenthOfName, sizeof(this->lenthOfName));
	stream.write(this->name, this->lenthOfName);
	stream.write((char*)&this->population, sizeof(this->population));
	stream.write((char*)&this->area, sizeof(this->area));
}
void Settlement::read(std::ifstream& stream)
{
	stream.read((char*)&this->lenthOfName, sizeof(this->lenthOfName));
	if (this->name != nullptr)
	{
		this->lenthOfName = 0;
		delete[] this->name;
	}
	this->name = new char[this->lenthOfName];
	stream.read(this->name, this->lenthOfName);
	stream.read((char*)&this->population, sizeof(this->population));
	stream.read((char*)&this->area, sizeof(this->area));
}
void Settlement::print()
{
	std::cout << "name : " << this->name << std::endl;
	std::cout << "population : " << this->population << std::endl;
	std::cout << "area : " << this->area << std::endl;
}
//Pretected Methods
int Settlement::getLengthOfName() const
{
	return this->lenthOfName;
}

//Destructor
Settlement::~Settlement()
{
	delete[] this->name;
}