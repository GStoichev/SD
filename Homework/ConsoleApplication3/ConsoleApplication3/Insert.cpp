#include "stdafx.h"
#include "Insert.h"


void Insert::Execute(CustomList<Tab>& listTab, const char* argument)
{
	Tab hello(argument);
	listTab.push_after(hello);
}