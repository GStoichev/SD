#pragma once
#include <iostream>

template <typename T> struct Node
{
	T value;
	Node* prev;
	Node* next;
};


template <typename T> class List
{
public:
	List();
	void push_front(const T& element);
	void pop_front();
	void push_back(const T& element);
	void pop_back();
	void insert(const size_t position, const T& element);
	void remove(const size_t position);
	bool empty();
	void print();
private:
	Node<T>* first;
	Node<T>* last;
	size_t size;
};

template <typename T> List<T>::List()
{
	this->size = 0;
	this->first = this->last = nullptr;
}
template <typename T> bool List<T>::empty()
{
	return !(this->size);
}
template <typename T> void List<T>::push_front(const T& element)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = element;
	if (this->empty())
	{
		this->first = newNode;
		this->first->next = nullptr;
		this->first->next = nullptr;
		this->last = this->first;
	}
	else
	{
		newNode->next = this->first;
		newNode->prev = nullptr;
		this->first = newNode;
		this->first->next->prev = this->first;	
	}
	this->size++;
}
template <typename T> void List<T>::pop_front()
{
	if (this->empty())
	{
		std::cout << "List is already empty!" << std::endl;
		return;
	}
	Node<T>* temp = this->first;
	if (this->first->next)
	{
		this->first = this->first->next;
		this->first->prev = nullptr;
	}
	delete temp;
	this->size--;
}
template <typename T> void List<T>::push_back(const T& element)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = element;
	if (this->empty())
	{
		this->last = newNode;
		this->last->next = nullptr;
		this->last->prev = nullptr;
		this->first = this->last;
	}
	else
	{
		newNode->next = nullptr;
		newNode->prev = this->last;
		this->last = newNode;
		this->last->prev->next = this->last;
	}
	size++;
}
template <typename T> void List<T>::pop_back()
{
	if (this->empty())
	{
		std::cout << "List is already empty!" << std::endl;
		return;
	}
	Node<T>* temp = this->last;
	if (this->last->prev)
	{
		this->last = this->last->prev;
		this->last->next = nullptr;
	}
	delete temp;
	this->size--;
}
template <typename T> void List<T>::print()
{
	if (!this->empty())
	{
		Node<T>* temp = this->first;
		for (size_t i = 0; i < this->size; i++)
		{
			std::cout << temp->value << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
}
template <typename T> void List<T>::insert(const size_t position, const T& element)
{
	if (position > size)
	{
		std::cout << "Position is greater then size of list" << std::endl;
		return;
	}
	Node<T>* temp = this->first;
	for (size_t i = 0; i < position; i++)
	{
		temp = temp->next;
	}
	Node<T>* newNode = new Node<T>;
	newNode->value = element;
	
	if (position == 0)
	{
		this->push_front(element);
		return;
	}
	if (position == this->size)
	{
		this->push_back(element);
		return;
	}
	temp->prev->next = newNode;
	newNode->prev = temp->prev;
	newNode->next = temp;
	temp->prev = newNode;
	this->size++;

}
template <typename T> void List<T>::remove(const size_t position)
{
	if (position > size)
	{
		std::cout << "Position is greater then size of list" << std::endl;
		return;
	}
	Node<T>* temp = this->first;
	for (size_t i = 0; i < position; i++)
	{
		temp = temp->next;
	}
	if (temp->prev)
	{
		if (temp->next)
		{
			temp->prev->next = temp->next;
		}
		else
		{
			temp->prev->next = nullptr;
		}
		
	}
	if (temp->next)
	{
		if (temp->prev)
		{
			temp->next->prev = temp->prev;
		}
		else
		{
			temp->next->prev = nullptr;
		}
	}
	delete temp;
	this->size--;
}
