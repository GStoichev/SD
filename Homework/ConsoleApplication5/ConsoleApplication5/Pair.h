#pragma once
#include <iostream>

class Pair
{
public:
	Pair();
	void load(const char* path, const char* hash);
	Pair(const char* path,const char* hash);
	Pair& operator=(const Pair& pair);
	Pair(const Pair& pair);
	~Pair();
	char* getPath() const;
	char* getHash() const;
	int getSizePath() const;
	int getSizeHash() const;
	friend std::ostream& operator<<(std::ostream&, const Pair& pair);
	
private:
	void copyFunc(const Pair& pair);
	int pathSize;
	int hashSize;
	char* path;
	char* hash;
};
