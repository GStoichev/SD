#include "stdafx.h"
#include "Johnny.h"

//Constructors
Johnny::Johnny()
{
	this->nameSize = 0;
	this->name = nullptr;
	this->age = 0;
	this->isAlien = false;
	this->money = 0;
}
Johnny::Johnny(const Johnny& john)
{
	this->copyFunc(john);
}
//Methods
void Johnny::load(char* name, int age, double money, bool isAlien)
{
	this->nameSize = 0;
	while (name[this->nameSize++] != '\0');
	if (this->name != nullptr)
	{
		delete[] this->name;
	}
	this->name = new char[this->nameSize];
	for (size_t i = 0; i < this->nameSize; i++)
	{
		this->name[i] = name[i];
	}
	this->age = age;
	this->money = money;
	this->isAlien = isAlien;
}
void Johnny::save()
{
	char* temp = new char[this->nameSize + 4];
	for (size_t i = 0; i < this->nameSize; i++)
	{
		temp[i] = this->name[i];
	}
	temp[this->nameSize - 1] = '.';
	temp[this->nameSize] = 'b';
	temp[this->nameSize + 1] = 'i';
	temp[this->nameSize + 2] = 'n';
	temp[this->nameSize + 3] = '\0';

	std::ofstream stream(temp, std::ios::out | std::ios::binary);
	if (!stream)
	{
		std::cout << "File " << temp << " can't be created!" << std::endl;
		delete[] temp;
		return;
	}

	stream.write((char*)&this->nameSize, sizeof(nameSize));
	stream.write(this->name, this->nameSize);
	stream.write((char*)&this->age, sizeof(age));
	stream.write((char*)&this->money, sizeof(money));
	stream.write((char*)&this->isAlien, sizeof(isAlien));
	delete[] temp;
	stream.close();
}
void Johnny::read(char* file)
{
	std::ifstream stream(file, std::ios::in | std::ios::binary);
	if (!stream)
	{
		std::cout << "File " << file << " can't load!" << std::endl;
		return;
	}
	stream.read((char*)&this->nameSize, sizeof(this->nameSize));
	if (this->name == nullptr)
	{
		delete[] this->name;
	}
	this->name = new char[this->nameSize];
	stream.read(this->name, this->nameSize);
	stream.read((char*)&this->age, sizeof(this->age));
	stream.read((char*)&this->money, sizeof(this->money));
	stream.read((char*)&this->isAlien, sizeof(this->isAlien));

	stream.close();

}
//Operators
Johnny& Johnny::operator=(const Johnny& john)
{
	if (this != &john)
	{
		delete[] this->name;
		this->copyFunc(john);
	}
	return *this;
}
bool Johnny::operator<=(const Johnny& john)
{
	if (this->age <= john.age)
	{
		return true;
	}
	return false;
}
//frindly
std::ostream& operator<<(std::ostream& stream, Johnny& john)
{
	stream << "Name : " << john.name << '\n';
	stream << "Age : " << john.age << '\n';
	stream << "Money : $" << john.money << '\n';
	stream << "Alien : ";
	john.isAlien ? stream << "I'm ALIEN!!!!!!\n" : stream << "false\n";
	return stream;
}
//Private Methods
void Johnny::copyFunc(const Johnny& john)
{
	this->age = john.age;
	this->nameSize = john.nameSize;
	this->isAlien = john.isAlien;
	this->money = john.money;
	this->name = new char[this->nameSize];
	for (size_t i = 0; i < this->nameSize; i++)
	{
		this->name[i] = john.name[i];
	}
}
//Destructor
Johnny::~Johnny()
{
	delete[] this->name;
}