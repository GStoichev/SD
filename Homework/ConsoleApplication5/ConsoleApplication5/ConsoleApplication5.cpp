// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <iostream>
//
//int main(int argc, char* argv[])
//{
//
//	//if (argc == 3)
//	//{
//	//	//syncronize
//	//}
//	//if (argc == 4)
//	//{
//	//	//restore
//	//}
//
//    return 0;
//}
#include <sys/stat.h>
#include "Pair.h"
#include <string>
#include <vector>
#include <iostream>
#include "md5.h"
#include "Backup.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		Backup backup(argv[1], argv[2]);
		backup.synchronize();
	}
	else if (argc == 4)
	{
		if (strcmp(argv[2],"-restore"))
		{
			Backup backup(argv[2], argv[3]);
			backup.restore();
		}
	}
	else
	{
		std::cout << "Please enter arguments" << std::endl;
	}
	return 0;

}
