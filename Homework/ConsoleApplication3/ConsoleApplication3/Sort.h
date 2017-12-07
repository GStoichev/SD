#pragma once
#include "Command.h"

class Sort : public Command
{
public:
	void Execute(CustomList<Tab>& listTab, const char* argument = nullptr);
private:
	
};
