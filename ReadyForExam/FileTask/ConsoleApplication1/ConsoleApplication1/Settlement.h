#pragma once
#include <iostream>
#include <fstream>

class Settlement
{
public:
	Settlement();
	~Settlement();
	virtual void load(char* name, int population, double area);
	virtual void print() = 0;
	virtual void save(std::ofstream& stream);
	virtual void read(std::ifstream& stream);
	char* getName() const;
	int getPopulation() const;
	double getArea() const;
	
protected:
	int getLengthOfName() const;
	char* name;
	int population;
	double area;
private:
	int lenthOfName;
};
