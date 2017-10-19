// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	int length = 20;
	std::ifstream tester;
	if (argc == 1)
	{
		tester.open(argv[1], std::ios::in);
	}
	else
	{
		tester.open("in.txt", std::ios::in);
	}
	if (!tester.is_open())
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	char** arr = new char*[length];
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = new char[length];
	}
	for (size_t i = 0; i < length; i++)
	{
		
			tester.getline(arr[i], length);
			std::cout << arr[i] << std::endl;
		
	}
		

		
	

    return 0;
}

