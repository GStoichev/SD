#pragma once
#include "Settlement.h"
class Village : public Settlement
{
public:
	Village();
	void load(char* name, int population, double area, int farmer);
	void print();
	void save();
	void read(const char* file);
	~Village() = default;

private:
	static const char header = 'v';
	int farmers;
};
