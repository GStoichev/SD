// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Thumbnail.h"

int main(int argc,char* argv[])
{

	if (argc == 1)
	{
		std::cout << "Please run program from terminal and give as an arguments names of .tdf files!" << std::endl;
	}
	else
	{
		for (size_t i = 1; i < argc; i++)
		{
			Thumbnail tdf(argv[i]);
		}
	}


	return 0;
}

