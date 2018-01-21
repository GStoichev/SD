// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	const int length = 10;
	int* arr = new int[length];
	arr[0] = 5;
	arr[1] = 2;
	arr[2] = 10;
	arr[3] = 20;
	arr[4] = 1;
	arr[5] = 19;
	arr[6] = 28;
	arr[7] = 86;
	arr[8] = 42;
	arr[9] = 0;

	//Insertion
	for (size_t i = 1; i < length; i++)
	{
		int num = arr[i];
		int j = i;
		while (j > 0)
		{
			if (num >= arr[j - 1])
			{
				break;
			}
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = num;


	}

	for (size_t i = 0; i < length; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;


    return 0;
}

