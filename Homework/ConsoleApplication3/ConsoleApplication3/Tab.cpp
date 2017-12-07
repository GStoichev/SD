#include "stdafx.h"
#include "Tab.h"

//Constructors
Tab::Tab()
{
	this->URL = nullptr;
}
Tab::Tab(const char* URL)
{
	this->load(URL);
}
Tab::Tab(const Tab& tab)
{
	this->copyFunc(tab);
}

//Operators
Tab& Tab::operator=(const Tab& tab)
{
	if (this != &tab)
	{
		delete[] this->URL;
		this->copyFunc(tab);
	}
	return *this;
}
std::ostream& operator<<(std::ostream& os, Tab& tab)
{
	os << tab.URL << " ";
	os << tab.date.getDate();
	return os;
}
//Methods
void Tab::load(const char* URL)
{
	if (this->URL != nullptr)
	{
		delete[] this->URL;
	}
	int length = 0;
	while (URL[length++] != '\0');
	try
	{
		this->URL = new char[length];
		for (size_t i = 0; i < length; i++)
		{
			this->URL[i] = URL[i];
		}
		this->date.UpdateTime();
	}
	catch (const std::bad_alloc)
	{
		this->URL = nullptr;
		std::cout << "Error : Bad allocating memory at Tab::load" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
		this->URL = nullptr;
		std::cout << "Error : Uknown at Tab::load" << std::endl;
		return;
	}
}
void Tab::printURL()
{
	std::cout << this->URL << std::endl;
}
void Tab::printDate()
{
	this->date.Print();
}
char* Tab::getURL() const
{
	return this->URL;
}
char* Tab::getDate() const
{
	return this->date.getDate();
}

//Private Functions
void Tab::copyFunc(const Tab& tab)
{
	this->date = tab.date;
	this->loadingTime = tab.loadingTime;
	int length = 0;
	while (tab.URL[length++] != '\0');
	try
	{
		this->URL = new char[length];
		for (size_t i = 0; i < length; i++)
		{
			this->URL[i] = tab.URL[i];
		}
	}
	catch (const std::bad_alloc)
	{
		this->URL = nullptr;
		std::cout << "Error : Bad allocating memory at Tab::copyFunc" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
		this->URL = nullptr;
		std::cout << "Error : Uknown at Tab::copyFunc" << std::endl;
		return;
	}
	
}

//Destuctor
Tab::~Tab()
{
	delete[] this->URL;
}
