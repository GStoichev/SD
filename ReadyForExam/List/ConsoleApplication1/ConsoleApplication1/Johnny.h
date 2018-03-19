#pragma once
#include <iostream>
#include <fstream>

class Johnny
{
public:
	Johnny();
	Johnny(const Johnny& john);
	Johnny& operator=(const Johnny& john);
	bool operator<=(const Johnny& john);
	void load(char* name, int age, double money, bool isAlian);
	void save();
	void read(char* file);
	friend std::ostream& operator<<(std::ostream& stream, Johnny& john);
	~Johnny();

private:
	void copyFunc(const Johnny& john);

	int nameSize;
	char* name;
	int age;
	double money;
	bool isAlien;
};
