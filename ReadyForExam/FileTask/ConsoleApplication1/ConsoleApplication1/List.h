#pragma once

template <typename T> struct Node
{
	T value;
	Node<T>* next;
};


template <typename T> class List
{
public:
	List();
	void push_front(const T& element);
	void pop_front();
	~List();
	void clear();
	size_t size() const;

private:
	Node<T>* block;
	size_t size;
};

//constructor
template <typename T> List<T>::List()
{
	this->block = nullptr;
}

//Methods
template <typename T> void List<T>::push_front(const T& element)
{
	Node<T>* newElem = new Node<T>();
	newElem->value = element;
	if (this->block != nullptr)
	{
		this->block->next = newElem;
	}
	this->block = newElem;
	this->block->next = nullptr;
	this->size++;
}
template <typename T> void List<T>::pop_front()
{
	if (this->block != nullptr)
	{
		Node<T>* temp = this->block;
		this->block = this->block->next;
		this->size--;
		delete temp;
	}
}
template <typename T> size_t List<T>::size() const
{
	return this->size();
}
template <typename T> void List<T>::clear()
{
	while (this->block != nullptr)
	{
		this->pop_front();
	}
}
//destructor
template <typename T> List<T>::~List()
{
	this->clear();
}