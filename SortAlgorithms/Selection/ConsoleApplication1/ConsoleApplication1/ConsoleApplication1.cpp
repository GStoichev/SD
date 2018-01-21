// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

const int length = 10;

int main()
{
	int* arr = new int[length];
	arr[0] = 5;
	arr[1] = 2;
	arr[2] = 10;
	arr[3] = 20;
	arr[4] = 1;
	arr[5] = 28;
	arr[6] = 56;
	arr[7] = 86;
	arr[8] = 42;
	arr[9] = 0;

	//Selection sort
	for (size_t i = 0; i < length - 1; i++)
	{
		int min = arr[i];
		int index = i;
		for (size_t j = i + 1; j < length; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				index = j;
			}
		}
		if (index != i)
		{
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}

	for (size_t i = 0; i < length; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
    return 0;
}

