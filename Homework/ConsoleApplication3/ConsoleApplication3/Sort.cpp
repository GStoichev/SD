#include "stdafx.h"
#include "Sort.h"


void Sort::Execute(CustomList<Tab>& listTab, const char* argument)
{
	Node<Tab>* temp;;
	int length = listTab.getSize() - 1;
	if (!strcmp(argument,"URL"))
	{
		for (size_t i = 0; i < listTab.getSize() - 1; i++)
		{
			temp = listTab.getFirst();
			for (size_t j = 0; j < length; j++)
			{
				int cmp = strcmp(temp->value.getURL(), temp->next->value.getURL());
				if (cmp > 0)
				{
					Tab container = temp->value;
					temp->value = temp->next->value;
					temp->next->value = container;
				}
				else if (cmp == 0)
				{
					if (strcmp(temp->value.getDate(), temp->next->value.getDate()) > 0)
					{
						Tab container = temp->value;
						temp->value = temp->next->value;
						temp->next->value = container;
					}
				}
				temp = temp->next;
			}
			length--;
		}
	}
	else if (!strcmp(argument,"TIME"))
	{
		for (size_t i = 0; i < listTab.getSize() - 1; i++)
		{
			temp = listTab.getFirst();
			for (size_t j = 0; j < length; j++)
			{
				int cmp = strcmp(temp->value.getDate(), temp->next->value.getDate());
				if (cmp > 0)
				{
					Tab container = temp->value;
					temp->value = temp->next->value;
					temp->next->value = container;
				}
				else if (cmp == 0)
				{
					if (strcmp(temp->value.getURL(), temp->next->value.getURL()) > 0)
					{
						Tab container = temp->value;
						temp->value = temp->next->value;
						temp->next->value = container;
					}
				}
				temp = temp->next;
			}
			length--;
		}
	}
}