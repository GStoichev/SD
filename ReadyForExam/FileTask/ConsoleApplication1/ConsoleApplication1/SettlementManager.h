#pragma once
#include "Village.h"
#include "City.h"
#include "Capitol.h"

class SettlemanteManager
{
public:
	SettlemanteManager();
	void load(Settlement* settlement);
	void load(const char* file);
	void create(char* name, int population, double area, int factoriesOrFarmers, bool city);
	void create(char* name, int population, double area, char* country);
	void removeFile(const char* name);
	void print();
	~SettlemanteManager();
private:
	Settlement* settlement;
};
