#pragma once
#include "Command.h"

class Remove : public Command
{
public:
	void Execute(CustomList<Tab>& listTab, const char* argument = nullptr);
private:

};
