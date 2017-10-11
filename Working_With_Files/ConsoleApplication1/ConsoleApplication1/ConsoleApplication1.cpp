// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IOFile.h"

int main()
{
	IOFile file;
	file.TransferData("name.txt","newFile.txt");
	
    return 0;
}

