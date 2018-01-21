#include "stdafx.h"
#include "Pair.h"


//Constructors
Pair::Pair()
{
	this->key = NULL;
	this->data = nullptr;
}
Pair::Pair(const int key, const char* data)
{
	this->key = key;
	int length = 0;
	if (data != nullptr)
	{
		while (data[length++] != '\0');
		this->data = new char[length];
		for (size_t i = 0; i < length; i++)
		{
			this->data[i] = data[i];
		}
	}
	
}
Pair::Pair(const Pair& pair)
{
	this->copyFunc(pair);
}

//Operators
Pair& Pair::operator=(const Pair& pair)
{
	if (this != &pair)
	{
		delete[] this->data;
		this->copyFunc(pair);
	}
	return *this;
}
bool Pair::operator<(const Pair& pair)
{
	if (pair.key && pair.data == nullptr)
	{
		if (this->key < pair.key)
		{
			return true;
		}
		return false;
	}
	else
	{
		if (this->key < pair.key && (strcmp(this->data, pair.data) < 0))
		{
			return true;
		}
		return false;
	}

}
bool Pair::operator==(const Pair& pair)
{
	if (pair.key && pair.data == nullptr)
	{
		if (this->key == pair.key)
		{
			return true;
		}
		return false;
	}
	else
	{
		if (this->key == pair.key && !strcmp(this->data, pair.data))
		{
			return true;
		}
		return false;
	}

}
//Private methods
void Pair::copyFunc(const Pair& pair)
{
	this->key = pair.key;
	int length = 0;
	while (pair.data[length++] != '\0');
	this->data = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->data[i] = pair.data[i];
	}
}

//Destructor
Pair::~Pair()
{
	delete[] this->data;
}