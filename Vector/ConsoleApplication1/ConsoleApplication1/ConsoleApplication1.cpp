#include "stdafx.h"
#include "Vector.h"

int main()
{
	Vector<int> vec(5,10);
	Vector<int> vec2(10, 20);
	vec.Swap(vec2);

	vec.Print();
	std::cout << std::endl;
	vec2.Print();
}