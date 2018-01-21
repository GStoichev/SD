#pragma once

#include <fstream>
#include <iostream>
#include "Pair.h"
#include "BinaryTree.h"
#include "Vector.h"

class Reader
{
public:
	Reader(const char* location, BinaryTree<Pair>& BT);
	

private:
	BinaryTree<Pair> BT;
	Reader();
	void addToBT(Vector<Pair> holder,int start, int end);
};
