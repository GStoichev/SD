#pragma once
#include <cstring>

class Pair
{
public:
	Pair();
	Pair(const int key,const char* data);
	Pair& operator=(const Pair& pair);
	bool operator<(const Pair& pair);
	bool operator==(const Pair& pair);
	Pair(const Pair& pair);
	~Pair();

private:
	void copyFunc(const Pair& pair);
	int key;
	char* data;
};
