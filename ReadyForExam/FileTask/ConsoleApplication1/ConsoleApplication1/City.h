#pragma once
#include "Settlement.h"

class City : public Settlement
{
public:
	City();
	void load(char* name, int population, double area, int factories);
	void print();
	void save();
	void read(const char* file);
	~City() = default;

private:
	int factories;
	static const char header = 'c';
};
