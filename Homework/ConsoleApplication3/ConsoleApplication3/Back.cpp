#include "stdafx.h"
#include "Back.h"


void Back::Execute(CustomList<Tab>& listTab,const char* argument)
{
	listTab.moveBack();
}