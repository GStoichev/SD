#pragma once
#include <iostream>
#include <cstring>
#include "GO.h"
#include "Insert.h"
#include "Back.h"
#include "Forward.h"
#include "Remove.h"
#include "Print.h"
#include "Sort.h"


//Singleton
class CommandLine
{
public:
	static CommandLine* getInstance(); // getting intance of "CommandLine" and ensure that instance is only one
	~CommandLine();

private:
	static bool instanceFlag;
	static CommandLine* instance;
	void Start();
	int CheckCommand(const char* command);
	int FindIndexCommand(const char*& command);
	int ExecuteCommand(const int command, const char* argument);
	int ExecuteCommand(const int command);
	CommandLine();
	CustomList<Tab> listTab;
};
