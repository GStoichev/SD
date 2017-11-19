// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Decompressor.h"
#include "Queue.h"

int main(int arvc,char* args[])
{
	if (arvc == 3)
	{
		Decompressor test(args[1],args[2]);
		test.Decompress();
		test.Save();
	}
	else
	{
		std::cout << "Error : Entered data is invalid, please give as first argument source file and for second argument destiantion." << std::endl;
		return 0;
	}
	    return 0;
}

