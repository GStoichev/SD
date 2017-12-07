#pragma once
#include "Command.h"

class Insert : public Command
{
public:
	void Execute(CustomList<Tab>& listTab, const char* argument);
private:

};
