// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>

int main()
{
	//creating streams for input and output from files
	std::ifstream streamForReading("name.txt", std::ios::in | std::ios::app);
	std::ofstream stramForWrithing("WriteHere.txt", std::ios::out | std::ios::app);
	std::string line;
	if (streamForReading.is_open() && stramForWrithing.is_open())
	{
		streamForReading.seekg(2, std::ios::beg); // reading from 2 char in sequence
		while (std::getline(streamForReading,line)) //reading a line from file
		{
			stramForWrithing << line << "\n"; // writhing a line in file
		}
		streamForReading.close();
	}
    return 0;
}

