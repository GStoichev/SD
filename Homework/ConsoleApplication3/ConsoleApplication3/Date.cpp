#include "stdafx.h"
#include "Date.h"


void Date::UpdateTime()
{
	if (this->date != nullptr)
	{
		delete[] this->date;
	}
	try
	{
		this->date = new char[20];
		time_t t = time(NULL);
		struct tm tm;
		localtime_s(&tm, &t);
		strftime(this->date, sizeof(this->date) * 20, "%Y-%m-%d %H:%M:%S", &tm);
	}
	catch (const std::bad_alloc)
	{
		this->date = nullptr;
		std::cout << "Error : Bad allocating memory at Date::UpdateTime" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
		this->date = nullptr;
		std::cout << "Error : Uknown at Date::UpdateTime" << std::endl;
		return;
	}


}
Date::Date(const Date& date)
{
	this->copyFunc(date);
}
void Date::copyFunc(const Date& date)
{
	try
	{
		this->date = new char[20];
		for (size_t i = 0; i < 20; i++)
		{
			this->date[i] = date.date[i];
		}
	}
	catch (const std::bad_alloc)
	{
		this->date = nullptr;
		std::cout << "Error : Bad allocating memory at Date::copyFunc" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
		this->date = nullptr;
		std::cout << "Error : Uknown at Date::copyFunc" << std::endl;
		return;
	}
}
Date& Date::operator=(const Date& date)
{
	if (this != &date)
	{
		delete[] this->date;
		this->copyFunc(date);
	}
	return *this;
}
Date::Date()
{
	this->date = nullptr;
	this->UpdateTime();
}
void Date::Print() const
{
	std::cout << this->date << std::endl;
}
char* Date::getDate() const
{
	return this->date;
}
Date::~Date()
{
		delete[] this->date;
}