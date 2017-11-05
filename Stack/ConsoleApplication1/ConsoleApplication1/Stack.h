#pragma once
#include <iostream>

template <typename T> struct Node
{
	T top;
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
	this->size = 0;
	this->block = new Node<T>;
	this->block->next = nullptr;
}

//Methods
template <typename T> void Stack<T>::Push(T& element)
{
	this->size++;
	Node<T>* newBlock = new Node<T>;
	newBlock->top = this->block->top;
	newBlock->next = this->block->next;
	this->block->top = element;
	this->block->next = newBlock;
}
template <typename T> void Stack<T>::Pop()
{
	if (this->size)
	{
		this->size--;
		Node<T>* temp = this->block->next->next;
		this->block->top = this->block->next->top;
		delete this->block->next;
		this->block->next = temp;
	}
	else
	{
		std::cout << "Stack is empty, so you can't pop!" << std::endl;
	}
}
template <typename T> bool Stack<T>::Empty()
{
	if (this->block->next == nullptr)
	{
		return true;
	}
	return false;
}
template <typename T> T& Stack<T>::Top()
{
	return this->block->top;
}
//Destructor
template <typename T>Stack<T>::~Stack()
{
	delete this->block;
}