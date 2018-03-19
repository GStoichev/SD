#pragma once
#include <iostream>

template <typename T> struct Node
{
	T value;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T> class List
{
public:
	List();
	void push_front(const T& element);
	void pop_front();
	void push_back(const T& element);
	void pop_back();
	void sort();
	void clear();
	bool empty();
	void print();
	~List();
private:
	void mergeSort(Node<T>** head);
	void split(Node<T>* head, Node<T>** left, Node<T>** right);
	Node<T>* mergeList(Node<T>* left , Node<T>* right);
	Node<T>* first;
	Node<T>* last;
	size_t size;
};


template <typename T> void List<T>::sort()
{
	this->mergeSort(&this->first);
}
template <typename T> void List<T>::mergeSort(Node<T>** headRef)
{
	Node<T>* head = *headRef;
	Node<T>* left;
	Node<T>* right;
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}
	

	split(head,&left,&right);

	mergeSort(&left);
	mergeSort(&right);

	*headRef = mergeList(left,right);

}
template <typename T> Node<T>* List<T>::mergeList(Node<T>* left, Node<T>* right)
{
	if (left == nullptr)
	{
		return right;
	}
	else if (right == nullptr)
	{
		return left;
	}
	Node<T>* result = nullptr;
	if (left->value <= right->value)
	{
		result = left;
		result->next = mergeList(left->next, right);
	}
	else
	{
		result = right;
		result->next = mergeList(left, right->next);
	}
	return result;
}
template <typename T> void List<T>::split(Node<T>* head, Node<T>** left, Node<T>** right)
{
	Node<T>* slow;
	Node<T>* fast;

	if (head == nullptr || head->next == nullptr)
	{
		*left = head;
		*right = nullptr;
	}
	else
	{
		slow = head;
		fast = head->next;
		 
		while (fast != nullptr)
		{
			fast = fast->next;
			if (fast != nullptr)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}

		*left = head;
		*right = slow->next;
		slow->next = nullptr;
		
	}
	
}
template <typename T> List<T>::List()
{
	this->size = 0;
	this->first = nullptr;
	this->last = nullptr;
}
template <typename T> bool List<T>::empty()
{
	return !this->size;
}
template <typename T> void List<T>::push_back(const T& element)
{
	Node<T>* block = new Node<T>;
	block->value = element;
	block->prev = nullptr;
	if (this->empty())
	{
		this->first = this->last = block;
		this->first->next = this->last->next = nullptr;
		this->size++;
	}
	else
	{
		block->next = this->last;
		this->last->next = block;
		this->last = block;
		this->size++;
	}
}
template <typename T> void List<T>::push_front(const T& element)
{
	Node<T>* block = new Node<T>;
	block->value = element;
	block->prev = nullptr;
	if (this->empty())
	{
		this->first = this->last = block;
		this->first->next = this->last->next = nullptr;
		this->size++;
	}
	else
	{
		block->next = this->first;
		this->first->prev = block;
		this->first = block;
		this->size++;
	}
}
template <typename T> void List<T>::pop_back()
{
	if (!this->empty())
	{
		Node<T>* block = this->last;
		this->last = this->last->prev;
		this->size--;
		delete block;
		return;
	}
	std::cout << "List is already empty!" << std::endl;

}
template <typename T> void List<T>::pop_front()
{
	if (!this->empty())
	{
		Node<T>* block = this->first;
		this->first = this->first->next;
		this->size--;
		delete block;
		return;
	}
	std::cout << "List is already empty!" << std::endl;
}
template <typename T> void List<T>::clear()
{
	int lenght = this->size;
	for (size_t i = 0; i < lenght; i++)
	{
		this->pop_front();
	}
}
template <typename T> void List<T>::print()
{
	Node<T>* temp = this->first;
	for (size_t i = 0; i < this->size; i++)
	{
		std::cout << temp->value << "\n";
		temp = temp->next;
	}
}
template <typename T> List<T>::~List()
{
	this->clear();
}