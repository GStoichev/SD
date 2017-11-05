// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"

int main()
{
	Stack<int> staky;
	int test = 5;
	staky.Push(test);
	staky.Push(++test);
	staky.Push(++test);
	staky.Pop();
	staky.Pop();
	staky.Pop();

    return 0;
}

