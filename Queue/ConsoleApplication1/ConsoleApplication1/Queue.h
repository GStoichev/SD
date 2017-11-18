#pragma once
//#define NULL = 0;
#include <iostream>
template <typename T> struct Node
{
	T value;
	Node<T>* next;
};

template <typename T> class Queue
{
public:
	Queue();
	~Queue();
	T& Front();
	T& Back();
	size_t Size();
	void PopFront();
	void PushBack(T& element);
	bool Empty();
private:
	
	Node<T>* first;
	Node<T>* last;
	size_t size;
};

//Constructors
template <typename T> Queue<T>::Queue()
{
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}
//Methods
template <typename T> void Queue<T>::PopFront()
{
	try
	{
		this->size--;
		Node<T>* temp = new Node<T>;
		temp = this->first->next;
		delete this->first;
		this->first = temp;
	}
	catch (const std::bad_alloc&)
	{
		std::cout << "Error : Out of memory!" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
		std::cout << "Error : Unknown at Queue<T>::Pop" << std::endl;
		return;
	}
	
}
template <typename T> void Queue<T>::PushBack(T& element)
{
	try
	{
		Node<T>* temp = new Node<T>;
		if (this->Empty())
		{

			this->size++;
			temp->value = element;
			temp->next = nullptr;
			this->first = temp;
			this->last = this->first;
		}
		else
		{
			this->size++;
			temp->value = element;
			temp->next = nullptr;
			this->last->next = temp;
			this->last = temp;

		}
	}
	catch (const std::bad_alloc&)
	{
		std::cout << "Error : Out of memory!" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
		std::cout << "Error : Unknown at Queue<T>::Push" << std::endl;
		return;
	}
	

}
template <typename T> T& Queue<T>::Front()
{
	if (this->Empty())
	{
		T returnME = NULL;
		return returnME;
	}
	return this->first->value;
}
template <typename T> T& Queue<T>::Back()
{
	if (this->Empty())
	{
		T returnMe = NULL;
		return returnMe;
	}
	return this->last->value;
}
template <typename T> bool Queue<T>::Empty()
{
	if (!(this->size))
	{
		return true;
	}
	return false;
}
template <typename T> size_t Queue<T>::Size()
{
	return this->size;
}
//Destructor
template <typename T> Queue<T>::~Queue()
{
	if (this->first == this->last)
	{
		delete this->first;
	}
	else
	{
		delete this->first;
		delete this->last;
	}
}