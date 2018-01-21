#include "stdafx.h"
#include "Reader.h"

Reader::Reader(const char* location, BinaryTree<Pair>& BT)
{
	std::ifstream stream(location, std::ios::in, std::ios::binary);
	if (!stream)
	{
		std::cout << " File is not open correctly" << std::endl;
		return;
	}
	Vector<Pair> holder;
	while ((int)stream.tellg() != -1)
	{
		int key;
		int length;
		char* data;
		stream.read((char*)&key, sizeof(key));
		stream.read((char*)&length, sizeof(length));
		data = new char[length + 1];
		stream.read(data, length);
		data[length + 1] = '\0';
		Pair temp(key, data);
		holder.push(temp);
		delete[] data;
	}
	holder.sort();
	this->addToBT(holder, 0, holder.getSize());
}
void Reader::addToBT(Vector<Pair> holder, int start, int end)
{
	if (start < end)
	{
		return;
	}
	int mid = (start + end) / 2;
	this->BT.insert(holder[mid]);
	this->addToBT(holder, start, mid);
	this->addToBT(holder, mid + 1, end);
}