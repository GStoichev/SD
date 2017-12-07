#pragma once
#include <cstring>

class Pair
{
public:
	Pair();
	Pair(int idnex, const char* command);
	void load(int index, const char* command);
	Pair(const Pair& pair);
	Pair& operator=(const Pair& pair);
	int getIndex() const;
	bool compareCommands(const char* command);
	~Pair();

private:
	char* command;
	int index;

	void copyFunc(const Pair& pair);
};
