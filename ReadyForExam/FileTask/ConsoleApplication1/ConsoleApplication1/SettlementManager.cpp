#include "stdafx.h"
#include "SettlementManager.h"


SettlemanteManager::SettlemanteManager()
{
	this->settlement = nullptr;
}
//Methods
void SettlemanteManager::load(Settlement* settlement)
{
	if (this->settlement != nullptr)
	{
		delete this->settlement;
	}
	this->settlement = settlement;
}
void SettlemanteManager::load(const char* file)
{
	std::ifstream stream(file, std::ios::in | std::ios::binary);
	if (!stream)
	{
		std::cout << "File " << file << " can't be open";
		return;
	}
	char id;
	stream.read((char*)&id, sizeof(id));
	stream.close();
	this->settlement;
	switch (id)
	{
	case 'v':
	{
		Village* village = new Village();
		village->read(file);
		settlement = village;
		break;
	}
	case 'c':
	{
		City* city = new City();
		city->read(file);
		settlement = city;
		break;
	}
	case 'C':
	{
		Capitol* capitol = new Capitol();
		capitol->read(file);
		settlement = capitol;
		break;
	}
	default:
		std::cout << "File " << file << " can't be readed" << std::endl;
		delete settlement;
		return;
		break;
	}
}
void SettlemanteManager::removeFile(const char* file)
{
	delete this->settlement;
	this->settlement = nullptr;
	remove(file);
}
void SettlemanteManager::print()
{
	this->settlement->print();
}
void SettlemanteManager::create(char* name, int population, double area, int factoriesOrFarmers, bool city)
{
	if (city)
	{
		City city;
		city.load(name, population, area, factoriesOrFarmers);
		city.save();
	}
	else
	{
		Village village;
		village.load(name, population, area, factoriesOrFarmers);
		village.save();
	}
}
void SettlemanteManager::create(char* name, int population, double area, char* country)
{
	Capitol capitol;
	capitol.load(name, population, area, country);
	capitol.save();
}
SettlemanteManager::~SettlemanteManager()
{
	delete this->settlement;
}

