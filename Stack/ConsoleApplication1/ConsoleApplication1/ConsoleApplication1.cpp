// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"

int main()
{
	Stack<char> staky;
	char test = 'A';
	staky.Push(test);
	std::cout << staky.Top() << std::endl;
	staky.Push(++test);
	std::cout << staky.Top() << std::endl;
	staky.Push(++test);
	std::cout << staky.Top() << std::endl;
	staky.Pop();
	std::cout << staky.Top() << std::endl;
	staky.Pop();
	std::cout << staky.Top() << std::endl;
	staky.Pop();
	std::cout << staky.Top() << std::endl;

    return 0;
}

