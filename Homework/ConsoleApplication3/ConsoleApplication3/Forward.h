#pragma once
#include "Command.h"

class Forward : public Command
{
public:
	void Execute(CustomList<Tab>& listTab, const char* argument = nullptr);
private:

};
