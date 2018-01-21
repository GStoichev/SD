#pragma once
#include <iostream>
#include <cstring>
#include "BinaryTree.h"
#include "Pair.h"
#include "Reader.h"

class Controler
{
public:
	Controler();
private:
	void start();
	BinaryTree<Pair> BT;
};

