// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

struct Header
{
	int width;
	int heigth;
	char* descriotion;
	double pixelPerHSize;
};

int main()
{
	Header header;
	header.width = 15;
	header.heigth = 15;
	header.pixelPerHSize = 3.5;
	header.descriotion = "Semerdjiev e bog i Armqnov e negoviq pastir";

	Header header1;

	std::ofstream wFile("file.bin", std::ios::out | std::ios::binary);

	std::ifstream rFile("file.bin", std::ios::in | std::ios::binary);

	//std::fstream w_rFile("file.bin",std::ios::in | std::ios::out | std::ios::binary);

	wFile.write((char*)&header, sizeof(Header));

	rFile.read((char*)&header1, sizeof(Header));
    return 0;
}

