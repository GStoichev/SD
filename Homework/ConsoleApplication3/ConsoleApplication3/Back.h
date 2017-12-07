#pragma once
#include "Command.h"

class Back : public Command
{
public:
	void Execute(CustomList<Tab>& listTab,const char* argument = nullptr);
private:

};
