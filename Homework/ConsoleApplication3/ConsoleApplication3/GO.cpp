#include "stdafx.h"
#include "GO.h"


void GO::Execute(CustomList<Tab>& listTab, const char* argument)
{
	listTab.getCurrent().load(argument);
}