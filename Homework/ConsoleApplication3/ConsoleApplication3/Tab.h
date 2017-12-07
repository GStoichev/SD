#pragma once
#include "Date.h"

class Tab
{
public:
	Tab();
	Tab(const char* URL);
	Tab(const Tab& tab);
	Tab& operator=(const Tab& tab);
	char* getURL() const;
	char* getDate() const;
	void load(const char* URL);
	void printURL();
	void printDate();
	~Tab();
	friend std::ostream& operator<<(std::ostream& os, Tab& tab);


private:
	char* URL;
	Date date;
	int loadingTime;
	
	void copyFunc(const Tab& tab);
};

