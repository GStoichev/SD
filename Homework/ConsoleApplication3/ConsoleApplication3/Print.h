#pragma once
#include "Command.h"

class Print : public Command
{
public:
	void Execute(CustomList<Tab>& listTab, const char* argument = nullptr);

private:

};
