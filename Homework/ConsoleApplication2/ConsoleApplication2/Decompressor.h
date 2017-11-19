#pragma once
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
	void Decompress(); //Decompress data in destination
	void Decompress(const char* destination); //Decompres data and add destination
	void Save(); // Save decompressed data at destination if exist
	void Save(const char* destination); // Save decompresed data at destination
	~Decompressor();

private:
	void CopyString(char*& str,const char* source);
	void GetCompressed(const char* file, char*& buffer); // Get data from file and save it at buffer
	bool CorrectBrackets(); //Check did brackets are correct
	char* source;
	char* destination;
	char* compressed;
	Queue<char> decompressed;
};
