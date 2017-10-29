#pragma once
#include <fstream>
#include <iostream>
#include "Image.h"

class Thumbnail
{
public:
	Thumbnail(const char* location);
	void Load(const char* location); // Loading thumbnail file and croping images by useing it

private:
	void WhiteSpaces(char* arr, int& curPos); //skip intervals, brackets and commas
	void FindWord(char* arr, int length,int& curPos,char*& word); //Finding word from postion of "curPos" and save it at "word"
	void FindNumber(char* arr,int length, int& curPos, int& num); //Find number from postion of "curPos" and save it at "num"
	void ReadLine(std::ifstream& stream); // Reading a line from "stream"

};
