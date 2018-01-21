// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BinaryTree.h"

int main()
{
	BinaryTree<int> tree;
	tree.insert(2);
	tree.insert(3);
	std::cout << tree.search(2) << std::endl;
	tree.destroy();
	std::cout << tree.search(2) << std::endl;
	return 0;
}

