// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Decompressor.h"
#include "Queue.h"

int main(int arvc,char* args[])
{
	Decompressor test("source.txt");
	std::cout << test.GetCompressed() << std::endl;
	test.Decompress();
	std::cout << std::endl;

    return 0;
}

