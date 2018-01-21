#include "stdafx.h"
#include "CommandLine.h"




//Singleton attributes
bool CommandLine::instanceFlag = false;
CommandLine* CommandLine::instance = nullptr;
CommandLine* CommandLine::getInstance()
{
	if (!instanceFlag)
	{
		try
		{
			instance = new CommandLine();
			instanceFlag = true;
			
		}
		catch (const std::bad_alloc&)
		{
			std::cout << "Error at locating memory for CommandLine!" << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "Error : Unknown at CommandLine::getInstance" << std::endl;
		}
		return instance;
	}
	else
	{
		return instance;
	}
}
Command* cmd[7];

//Constructor, beacuse this class is sigleton constructor is private
CommandLine::CommandLine()
{
	GO go;
	Insert ins;
	Back back;
	Forward forward;
	Remove re;
	Print print;
	Sort sort;
	cmd[0] = &go;
	cmd[1] = &ins;
	cmd[2] = &back;
	cmd[3] = &forward;
	cmd[4] = &re;
	cmd[5] = &print;
	cmd[6] = &sort;
	this->Start();
}

//Private methods
void CommandLine::Start()
{
	bool listener = true;
	char* command;
	char argument[256];
	while (listener)
	{
		if (this->listTab.empty())
		{
			Tab blank("about:blank");
			this->listTab.push_after(blank);
		}
		char c;
		int length = 0;
		while (std::cin.get(c))
		{
			length++;
			if (c == ' ' || '\n')
			{
				break;
			}
		}
		std::cin.seekg(-length,std::ios::cur);
		command = new char[length + 1];
		std::cin >> command;
		
		
		//int indexCommand =  CheckCommand(command);
		int indexCommand = FindIndexCommand(command);
		if (indexCommand == -2)
		{
			std::cout << "Enterd command whas too long!" << std::endl;
			continue;
		}
		else if (indexCommand == -1)
		{
			std::cout << "Invalide command" << std::endl;
			continue;
		}
		else if (indexCommand == 7)
		{
			return;
		}
		if (indexCommand == 0 || indexCommand == 1 || indexCommand == 6)
		{
			std::cin >> argument;
			this->ExecuteCommand(indexCommand, argument);
		}
		else
		{
			this->ExecuteCommand(indexCommand);
		}

		delete[] command;

	}
}
int CommandLine::CheckCommand(const char* command)
{
	for (size_t i = 0; i < 10; i++)
	{
		if (command[i] == '\0')
		{
			return this->FindIndexCommand(command);
		}
	}
	return -2;
}
int CommandLine::FindIndexCommand(const char* command)
{
	if (!strcmp(command,"GO"))
	{
		return 0;
	}
	else if(!strcmp(command,"INSERT"))
	{
		return 1;
	}
	else if (!strcmp(command, "BACK"))
	{
		return 2;
	}
	else if (!strcmp(command, "FORWARD"))
	{
		return 3;
	}
	else if (!strcmp(command, "REMOVE"))
	{
		return 4;
	}
	else if (!strcmp(command, "PRINT"))
	{
		return 5;
	}
	else if (!strcmp(command, "SORT"))
	{
		return 6;
	}
	else if (!strcmp(command, "EXIT"))
	{
		return 7;
	}
	return -1;
}
int CommandLine::ExecuteCommand(const int command, const char* argument)
{
	cmd[command]->Execute(this->listTab,argument);
	return 0;
}
int CommandLine::ExecuteCommand(const int command)
{
	cmd[command]->Execute(this->listTab);
	return 0;
}
//Destructor
CommandLine::~CommandLine()
{
	this->instanceFlag = false;
	delete instance;
	delete getInstance();
	delete[] cmd;
}