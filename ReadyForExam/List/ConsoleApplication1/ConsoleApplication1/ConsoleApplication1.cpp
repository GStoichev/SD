// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Johnny.h"
#include "List.h"

void merge(int* arr, int begin, int mid, int end)
{
	int leftSize = mid - begin + 1;
	int rightSize = end - mid;

	int* left = new int[leftSize];
	int* right = new int[rightSize];

	for (size_t i = 0; i < leftSize; i++)
	{
		left[i] = arr[begin + i];
	}
	for (size_t i = 0; i < rightSize; i++)
	{
		right[i] = arr[mid + i + 1];
	}

	int leftCount = 0;
	int rightCount = 0;
	int arrCount = begin;
	while (leftCount < leftSize && rightCount < rightSize)
	{
		if (left[leftCount] <= right[rightCount])
		{
			arr[arrCount++] = left[leftCount++];
		}
		else
		{
			arr[arrCount++] = right[rightCount++];
		}
	}

	while (leftCount < leftSize)
	{
		arr[arrCount++] = left[leftCount++];
	}
	while (rightCount < rightSize)
	{
		arr[arrCount++] = right[rightCount++];
	}
	delete[] left;
	delete[] right;
}
void mergeSort(int* arr, int begin, int end)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;

		mergeSort(arr,begin, mid);
		mergeSort(arr, mid + 1, end);

		merge(arr, begin, mid , end);
	}
}



int main()
{

	int arr[] = { 1,8,2,8,17,26,42,7,3,9 };
	mergeSort(arr, 0, 9);
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;



	//const int length = 5;
	//Johnny johnnys[length];
	//johnnys[0].load("Beizi", 20, 400.15, true);
	//johnnys[1].load("Georgi", 20, 0.0, false);
	//johnnys[2].load("Pesho", 42, 3000.0, true);
	//johnnys[3].load("Ivan", 52, 700.0, false);
	//johnnys[4].load("Tina", 12, 300.0, false);
	//List<Johnny> list;
	//for (size_t i = 0; i < length; i++)
	//{
	//	list.push_front(johnnys[i]);
	//}
	//list.sort();
	//list.print();

    return 0;
}

