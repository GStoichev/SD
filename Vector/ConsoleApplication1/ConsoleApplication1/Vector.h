#pragma once
#include <iostream>

template <typename T> class Vector
{
public:
	Vector();
	Vector(int length, const T val); //Creating vector with length = "length" and fill all positions with value = "val"
	Vector(const Vector& vec);
	~Vector();
	int GetSize() const; //Get size of Vector
	void PushBack(const T element); //Add element at end of sequence
	void PopBack(); //Remove last element from sequence
	void Insert(const T element, size_t index); //Insert element at "index"
	void Erase(size_t index); // Earase element at "index"
	bool Empty(); // Check did sequence is empty if it is then return true
	void Clear(); // Clearing allocated memmory and deleting all elements from sequence
	void Swap(Vector& vec);
	Vector<T>& operator=(const Vector<T>& vec);
	T& operator[](int index); //get element at "index" in sequence
	T& At(int index); //Get element at "index" in sequence
	T& Front(); //Get first element in sequence
	T& Back(); //Get last element in sequence
	T* Data(); //Get all sequence

	//void Assign(int length, const T val);
	void Print();

private:
	int size;
	int capacity;
	T* sequence;
	void CopyFunc(const Vector& vec);
	void Resize();
};

//Constructors
template <typename T> Vector<T>::Vector()
{
	this->size = 0;
	this->capacity = 8;
	this->sequence = new T[this->capacity];
}
template <typename T> Vector<T>::Vector(int length, const T val)
{
	this->size = 0;
	this->capacity = 8;
	this->sequence = new T[this->capacity];
	while (this->capacity <= length)
	{
		this->Resize();
	}
	this->size = length;
	for (size_t i = 0; i < length; i++)
	{
		this->sequence[i] = val;
		
	}
}
template <typename T> Vector<T>::Vector(const Vector<T>& vec)
{
	this->CopyFunc(vec);
}

//Methods
template <typename T> T& Vector<T>::Front()
{
	return this->sequence[0];
}
template <typename T> T& Vector<T>::Back()
{
	return this->sequence[this->size - 1];
}
template <typename T> T& Vector<T>::At(int index)
{
	return this->sequence[index];
}
template <typename T> T& Vector<T>::operator[](int index)
{
	return this->sequence[index];
}
template <typename T> T* Vector<T>::Data()
{
	return this->sequence;
}

template <typename T> void Vector<T>::PushBack(const T element)
{
	if (this->size == this->capacity)
	{
		this->Resize();
	}
	this->sequence[this->size++] = element;
}
template <typename T> void Vector<T>::PopBack()
{
	this->size--;
}
template <typename T> void Vector<T>::Insert(const T element, size_t position)
{
	this->size++;
	if (this->size >= this->capacity)
	{
		this->Resize();
	}
	T* temp = new T[this->size];
	for (size_t i = 0; i < position; i++)
	{
		temp[i] = this->sequence[i];
	}
	temp[position] = element;
	for (size_t i = position+1; i < this->size; i++)
	{
		temp[i] = this->sequence[i - 1];
	}
	delete[] this->sequence;
	this->sequence = temp;
}
template <typename T> void Vector<T>::Erase(size_t position)
{
	this->size--;
	T* temp = new T[this->size];
	for (size_t i = 0; i < position; i++)
	{
		temp[i] = this->sequence[i];
	}
	for (size_t i = position + 1; i < this->size + 1; i++)
	{
		temp[i - 1] = this->sequence[i];
	}
	delete[] this->sequence;
	this->sequence = temp;
}
template <typename T> bool Vector<T>::Empty()
{
	return !(this->size);
}
template <typename T> void Vector<T>::Clear()
{
	delete[] this->sequence;
	this->size = 0;
	this->capacity = 8;
	this->sequence = new T[this->capacity];
}
template <typename T> void Vector<T>::Swap(Vector<T>& vec)
{
	Vector<T> temp = vec;
	vec = *this;
	*this = temp;
}
//Getters
template <typename T> int Vector<T>::GetSize() const
{
	return this->size;
}

//Private Methods
template <typename T> void Vector<T>::Resize()
{
	this->capacity *= 2;
	T* temp = new T[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->sequence[i];
	}
	delete[] this->sequence;
	//this->sequence = new T[this->capacity];
	this->sequence = temp;

}
template <typename T> void Vector<T>::CopyFunc(const Vector<T>& vec)
{
	this->capacity = vec.capacity;
	this->size = vec.size;
	this->sequence = new T[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		this->sequence[i] = vec.sequence[i];
	}
}

//Operators
template <typename T> Vector<T>& Vector<T>::operator=(const Vector<T>& vec)
{
	if (this != &vec)
	{
		delete[] this->sequence;
		this->CopyFunc(vec);
	}
	return *this;
}

//Destructor
template <typename T> Vector<T>::~Vector()
{
	delete[] this->sequence;
}


template <typename T> void Vector<T>::Print()
{
	std::cout << this->size << std::endl;
	std::cout << this->capacity << std::endl;
	for (size_t i = 0; i < this->size; i++)
	{
		std::cout << this->sequence[i] << " ";
	}
	std::cout << std::endl;
}