#pragma once
#include <iostream>
#include "CustomList.h"
#include "Tab.h"
#include <cstring>


class Command
{
public:
	virtual void Execute(CustomList<Tab>& listTab,const char* argument = nullptr) = 0;
};