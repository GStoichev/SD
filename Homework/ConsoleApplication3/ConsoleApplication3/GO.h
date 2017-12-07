#pragma once
#include "Command.h"

class GO : public Command
{
public:
	void Execute(CustomList<Tab>& listTab,const char* argument);
private:

};
