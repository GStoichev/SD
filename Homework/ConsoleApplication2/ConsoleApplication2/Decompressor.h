#pragma once
#include "Stack.h"
#include <iostream>
#include <fstream>
#include "Stack.h"
#include "Queue.h"

class Decompressor
{
public:
	Decompressor();
	Decompressor(const char* source);
	Decompressor(const char* source, const char* destination);
	void LoadFile(const char* source);
	void LoadFile(const char* source, const char* destination);
	char* GetCompressed() const;
	void Decompress();
	void Decompress(const char* destination);
	~Decompressor();

private:
	void CopyString(char*& str,const char* source);
	void GetCompressed(const char* file, char*& buffer);
	bool CorrectBrackets();
	char* source;
	char* destination;
	char* compressed;
	Queue<char> decompressed;
};
