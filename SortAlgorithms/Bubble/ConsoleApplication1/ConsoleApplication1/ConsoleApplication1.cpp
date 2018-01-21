// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

const int length = 10;

int main()
{
	int* arr = new int[length];
	arr[0] = 8;
	arr[1] = 2;
	arr[2] = 65;
	arr[3] = 56;
	arr[4] = 42;
	arr[5] = 1;
	arr[6] = 18;
	arr[7] = 0;
	arr[8] = 8000;
	arr[9] = 7;


	//Bubble sort
	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (size_t i = 0; i < length; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
    return 0;
}

