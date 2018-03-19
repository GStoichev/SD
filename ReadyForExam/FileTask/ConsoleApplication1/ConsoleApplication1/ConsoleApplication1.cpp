// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SettlementManager.h"
int main()
{
	SettlemanteManager manager;
	//manager.create("Sofia", 125125, 12345.56, "Bulgaria");
	//manager.create("Dimitrovgrad", 15637, 2156.56, 1, true);
	//manager.create("Vulcaneshi", 126, 589.48, 57, false);
	manager.load("Sofia.bin");
	manager.print();
	std::cout << std::endl;
	manager.load("Dimitrovgrad.bin");
	manager.print();
	std::cout << std::endl;
	manager.load("Vulcaneshi.bin");
	manager.print();

    return 0;
}

