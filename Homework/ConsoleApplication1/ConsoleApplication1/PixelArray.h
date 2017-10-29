#pragma once
#include <iostream>
#include <fstream>
#include <cstring>

class PixelArray
{

public:
	PixelArray();
	PixelArray(std::ifstream& istream,const size_t size);
	PixelArray(const PixelArray& arr);
	PixelArray& operator=(const PixelArray& arr);
	~PixelArray();
	void Save(std::ostream& ostream);
	char* GetBuffer() const;
	PixelArray& Update(char* buffer,int sizeOfBuffer);
	int GetSize() const;

private:
	char* buffer;
	void CopyFunc(const PixelArray& arr);
	size_t sizeOfBuffer;
	
};

