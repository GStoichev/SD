#include "stdafx.h"
#include "Controler.h"

Controler::Controler()
{
	this->start();
}
void Controler::start()
{
	char fileName[256];
	std::cin >> fileName;
	Reader read(fileName,BT);


	char command[256];
	int key;
	char data[256];
	while (true)
	{
		std::cin >> command;
		std::cin >> key;
		if (!strcmp(command,"removeall"))
		{
			Pair temp(key,nullptr);
			int couter = 0;
			while (BT.remove(temp))
			{
				couter++;
			}
			std::cout << "Deleted elements : " << couter << std::endl;
			continue;
		}
		std::cin >> data;
		Pair temp(key, data);
		if (!strcmp(command,"remove"))
		{
			BT.remove(temp) ? std::cout << "true" : std::cout << "false";
			continue;
		}
		if (!strcmp(command, "add"))
		{
			BT.insert(temp);
			continue;
		}
		if (!strcmp(command, "search"))
		{
			BT.search(temp) ? std::cout << "true" : std::cout << "false";
			continue;
		}
		std::cout << "Entered command is invalid" << std::endl;
	}
}
