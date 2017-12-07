#pragma once
#include "Node.h"
#include <iostream>

template <typename T> class CustomList
{
public:
	CustomList();
	bool empty();
	size_t getSize();
	void push_after(const T& element);
	void pop_current();
	void moveBack();
	void moveNext();
	T& getCurrent() const;
	void print();
	Node<T>* getFirst();
	~CustomList();

private:
	Node<T>* block;
	Node<T>* first;
	size_t size;
};

//Constructors
template <typename T> CustomList<T>::CustomList()
{
	this->size = 0;
	this->block = nullptr;
}

//Methods
template <typename T> size_t CustomList<T>::getSize()
{
	return this->size;
}
template <typename T> bool CustomList<T>::empty()
{
	if (this->size == 0)
	{
		return true;
	}
	return false;
}
template <typename T > void CustomList<T>::push_after(const T& element)
{
	Node<T>* temp;
	try
	{
		temp = new Node<T>;
	}
	catch (const std::bad_alloc&)
	{
		std::cout << "Error : Bad allocating memory at CustomList::push_after" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
		std::cout << "Error : Unknown at CustomList::push_after" << std::endl;
		return;
	}
	temp->value = element;
	if (this->empty())
	{
		temp->next = temp;
		temp->prev = temp;
		this->block = temp;
		this->first = temp;
	}
	else
	{
		temp->prev = this->block;
		temp->next = this->block->next;
		this->block->next->prev = temp;
		this->block->next = temp;
		this->block = temp;
	}
	this->size++;
	
}
template <typename T> void CustomList<T>::pop_current()
{
	if (this->empty())
	{
		std::cout << "List is already empty!" << std::endl;
		return;
	}
	else
	{
		Node<T>* temp = this->block;
		this->block->prev->next = this->block->next;
		this->block->next->prev = this->block->prev;
		if (this->block == this->first)
		{
			this->first = this->block->next;
			this->moveNext();
		}
		else if (this->block->next == this->first)
		{
			this->moveBack();
		}
		else
		{
			this->moveNext();
		}
		
		delete temp;
		this->size--;
	}
	
}
template <typename T> void CustomList<T>::moveBack()
{
	this->block = this->block->prev;
}
template <typename T> void CustomList<T>::moveNext()
{
	this->block = this->block->next;
}
template <typename T> void CustomList<T>::print()
{
	Node<T>* temp = this->first;
	for (size_t i = 0; i < this->size; i++)
	{
		if (temp == this->block)
		{
			std::cout << ">";
		}
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}
}
template <typename T> T& CustomList<T>::getCurrent() const
{
	return this->block->value;
}
template <typename T> Node<T>* CustomList<T>::getFirst()
{
	return this->first;
}

//Destructor
template <typename T> CustomList<T>::~CustomList()
{
	while (this->size != 0 )
	{
		this->pop_current();
	}
}


