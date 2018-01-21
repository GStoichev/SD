#include "stdafx.h"
#include "Pair.h"

//Constructors
Pair::Pair()
{
	this->hash = nullptr;
	this->path = nullptr;
	this->hashSize = 0;
	this->pathSize = 0;
}
Pair::Pair(const char* path, const char* hash)
{
	this->path = nullptr;
	this->hash = nullptr;
	this->hashSize = 0;
	this->pathSize = 0;
	this->load(path, hash);
}
Pair::Pair(const Pair& pair)
{
	this->copyFunc(pair);
}
//Methods
void Pair::load(const char* path, const char* hash)
{
	if (this->path != nullptr)
	{
		delete[] this->path;
	}
	if (this->hash != nullptr)
	{
		delete[] this->hash;
	}
	int length = 0;
	while (path[length++] != '\0');
	this->path = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->path[i] = path[i];
	}
	this->pathSize = length;
	length = 0;
	while (hash[length++] != '\0');
	this->hash = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->hash[i] = hash[i];
	}
	this->hashSize = length;
}
//Getters
int Pair::getSizeHash() const
{
	return this->hashSize;
}
int Pair::getSizePath() const
{
	return this->pathSize;
}
char* Pair::getPath() const
{
	return this->path;
}
char* Pair::getHash() const
{
	return this->hash;
}
//operators
Pair& Pair::operator=(const Pair& pair)
{
	if (this != &pair)
	{
		delete[] this->hash;
		delete[] this->path;
		this->copyFunc(pair);
	}
	return *this;
}
std::ostream& operator<<(std::ostream& os,const Pair& pair)
{
	os << pair.getPath() << " - " << pair.getHash() << std::endl;
	return os;
}
//private methods
void Pair::copyFunc(const Pair& pair)
{
	this->hashSize = pair.hashSize;
	this->pathSize = pair.pathSize;
	int length = 0;
	while (pair.path[length++] != '\0');
	this->path = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->path[i] = pair.path[i];
	}
	length = 0;
	while (pair.hash[length++] != '\0');
	this->hash = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->hash[i] = pair.hash[i];
	}
}

//Destructor
Pair::~Pair()
{
	delete[] this->path;
	delete[] this->hash;
}