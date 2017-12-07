#pragma once
#include <time.h>
#include <cstring>
#include <iostream>

struct Date
{
public:
	Date();
	Date(const Date& date);
	Date& operator=(const Date& date);
	void Print() const;
	void UpdateTime();
	char* getDate() const;
	~Date();
private : 
	char* date;

	void copyFunc(const Date& date);
};
