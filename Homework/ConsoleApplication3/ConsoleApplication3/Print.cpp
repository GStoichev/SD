#include "stdafx.h"
#include "Print.h"

void Print::Execute(CustomList<Tab>& tab,const char* argument)
{
	tab.print();
}