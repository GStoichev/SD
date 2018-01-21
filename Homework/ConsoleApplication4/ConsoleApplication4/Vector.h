#pragma once
template <typename T> class Vector
{
public:
	Vector();
	~Vector();
	void push(const T& element);
	void sort();
	size_t getSize();
	T operator[](const int position);
private:
	void resize();
	T* arr;
	size_t size;
	size_t capacity;
};

//Constructor
template <typename T> Vector<T>::Vector()
{
	this->size = 0;
	this->capacity = 4;
	this->arr = new T[this->capacity];
}
//Destructor
template <typename T> Vector<T>::~Vector()
{
	delete[] this->arr;
}
//Operators
template <typename T> T Vector<T>::operator[](const int position)
{
	//add exeption
	return this->arr[position];
}
//Methods
template <typename T> size_t Vector<T>::getSize()
{
	return this->size;
}
template <typename T> void Vector<T>::push(const T& element)
{
	if (this->size >= this->capacity)
	{
		resize();
	}
	this->arr[this->size++] = element;
	
}
template <typename T> void Vector<T>::sort()
{
	for (size_t i = 0; i < this->size - 1; i++)
	{
		for (size_t j = 0; j < this->size - 1 - i; j++)
		{
			if (this->arr[j + 1] < this->arr[j])
			{
				T temp = this->arr[j];
				this->arr[j] = this->arr[j + 1];
				this->arr[j + 1] = temp;
			}
		}
	}
}

//Private methods
template <typename T> void Vector<T>::resize()
{
	this->capacity *= 2;
	T* temp = new T[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = temp;
}