#pragma once

#include <iostream>
#include <fstream>

class BitmapFileHeader
{
public:
	BitmapFileHeader();
	BitmapFileHeader(char* name);
	void Load(char* name);
	int getSize();
	int getPositionPixelArray();
	bool CheckIdetifyer();
private:
	char identifyer[2];  //to identify type of file
	int size; // size of file in bytes
	short reserved1; //Value depends on what program is file create 
	short reserved2; //Value depends on what program is file create
	int positionPixelArray; // show starting position of pixel array
};
