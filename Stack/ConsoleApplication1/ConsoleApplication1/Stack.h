#pragma once
#include <iostream>

template <typename T> struct Node
{
	T value;
	Node<T>* next;
};
template <typename T> class Stack
{
public:
	Stack();
	void Push(T& element);
	void Pop();
	T& Top();
	bool Empty();
	~Stack();
private:
	Node<T>* block;
	size_t size;
};

//Constructors
template <typename T> Stack<T>::Stack()
{
	this->block = nullptr;
}
//Methods
template <typename T> void Stack<T>::Push(T& element)
{
	try
	{
		this->size++;
		Node<T>* newBlock = new Node<T>;
		newBlock->next = this->block;
		newBlock->value = element;
		this->block = newBlock;
	}
	catch (const std::bad_alloc&)
	{
		std::cout << "Error : Out of memory!" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
		std::cout << "Error : Unknown at Stack<T>::Push" << std::endl;
		return;
	}
	

}
template <typename T> void Stack<T>::Pop()
{
	if (!this->Empty())
	{
		this->size--;
		if (this->Empty())
		{
			delete this->block;
			this->block = nullptr;
		}
		else
		{
			try
			{
				Node<T>* temp = this->block->next;
				delete this->block;
				this->block = temp;
			}
			catch (const std::bad_alloc&)
			{
				std::cout << "Error : Out of memory!" << std::endl;
				return;
			}
			catch (const std::exception&)
			{
				std::cout << "Error : Unknown at Stack<T>::Pop" << std::endl;
			}
			
		}
	}
	else
	{
		std::cout << "Stack is empty, so you can't pop!" << std::endl;
	}
}
template <typename T> bool Stack<T>::Empty()
{
	if (!this->size)
	{
		return true;
	}
	return false;
}
template <typename T> T& Stack<T>::Top()
{
	if (this->Empty())
	{
		std::cout << "Stack is empty!" << std::endl;
		T empty = NULL; // I'm using this because my methods return reference to top item and I can't return a constant value
		return empty;
	}
	return this->block->value;
}
//Destructor
template <typename T>Stack<T>::~Stack()
{
	delete this->block;
}