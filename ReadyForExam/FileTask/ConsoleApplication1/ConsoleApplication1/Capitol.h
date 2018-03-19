#pragma once
#include "Settlement.h"

class Capitol : public Settlement
{
public:
	Capitol();
	void load(char* name, int population, double area, char* country);
	void print();
	void save();
	void read(const char* file);
	~Capitol();

private:
	char* country;
	int lengthOfCountry;
	static const char header = 'C';
};
