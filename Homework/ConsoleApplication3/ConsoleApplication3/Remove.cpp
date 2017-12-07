#include "stdafx.h"
#include "Remove.h"


void Remove::Execute(CustomList<Tab>& listTab, const char* argument)
{
	listTab.pop_current();
}