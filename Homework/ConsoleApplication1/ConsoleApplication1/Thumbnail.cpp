#include "stdafx.h"
#include "Thumbnail.h"

//Constructors
Thumbnail::Thumbnail(const char* location)
{
	this->Load(location);
}

//Methods
void Thumbnail::Load(const char* location)
{

	std::ifstream stream(location, std::ios::in);
	if (!stream)
	{
		std::cout << "Error at loading file." << std::endl;
		return;
	}
	while ((int)stream.tellg() != -1) // reading lines untill the end of file
	{
		try
		{
			this->ReadLine(stream);
			
		}
		catch (const std::exception&)
		{
			std::cout << "Error at reading line " << std::endl;
		}
	}
	stream.close();
}

//Private methods
void Thumbnail::WhiteSpaces(char* arr, int& curPos)
{
	if (arr[curPos] == ';')
	{
		return;
	}
	while (arr[curPos] == ' ' || arr[curPos] == '(' || arr[curPos] == ')' || arr[curPos] == ',')
	{
		curPos++;
	}
	

}
void Thumbnail::FindWord(char* arr,int length,int& curPos,char*& word)
{
	int startPos = curPos;
	int slashPos = -1;
	int wordLen = 0;
	while (arr[curPos] != ' ' && curPos < length)
	{
		if (arr[curPos] == ';')
		{
			if (arr[curPos-1] == '\\')
			{
				slashPos = curPos - 1;
				wordLen--;
			}
			else
			{
				return;
			}
		}
		wordLen++;
		curPos++;
	}
	char* temp = new char[wordLen+1];
	for (size_t i = 0; i < wordLen; i++)
	{
		if (startPos == slashPos)
		{
			startPos++;
		}
		temp[i] = arr[startPos++];
	}
	temp[wordLen] = '\0';
	word = temp;
}
void Thumbnail::FindNumber(char* arr,int lenght, int& curPos, int& num)
{

	int startPos = curPos;
	int numDigits = 0;
	while ((arr[curPos] == '0' || arr[curPos] == '1' || arr[curPos] == '2' || arr[curPos] == '3' || arr[curPos] == '4' || arr[curPos] == '5' || arr[curPos] == '6' || arr[curPos] == '7' || arr[curPos] == '8' || arr[curPos] == '9') && curPos < lenght)
	{
		numDigits++;
		curPos++;
	}
	if (arr[curPos] == ';')
	{
		return;
	}
	if (numDigits > 0)
	{
		num = 0;
	}
	for (size_t i = 0; i < numDigits; i++) //extract number from "arr"
	{
		num *= 10;
		num += arr[startPos++] - '0';
	}
}
void Thumbnail::ReadLine(std::ifstream& stream)
{
	char c;
	stream.get(c);
	int curPos = 0;
	int count = 0;

	do
	{	
		if (c == '\n')
		{
			count++;
			break;
		}
		count++;
	} while (stream.get(c));
	char* line;
	char* sourse = NULL;
	int x = -1;
	int y = -1;
	int width = -1;
	int heigth = -1;
	char* destination = NULL;
	if ((int)stream.tellg() == -1)
	{
		
		stream.clear();
		stream.seekg(-count, std::ios::cur);
	}
	else
	{
		stream.seekg(-count - 1, std::ios::cur);
	}
	if (count == 1) // some kind of error handler... :X (strange error, strange handler)
	{
		stream.seekg(-1);
		return;
	}
	line = new char[count + 1];
	stream.getline(line, count + 1);
	this->WhiteSpaces(line, curPos);
	this->FindWord(line, count, curPos, sourse);
	this->WhiteSpaces(line, curPos);
	this->FindNumber(line, count, curPos, x);
	this->WhiteSpaces(line, curPos);
	this->FindNumber(line, count, curPos, y);
	this->WhiteSpaces(line, curPos);
	this->FindNumber(line, count, curPos, width);
	this->WhiteSpaces(line, curPos);
	this->FindNumber(line, count, curPos, heigth);
	this->WhiteSpaces(line, curPos);
	this->FindWord(line, count, curPos, destination);
	if (line[curPos] == ';' || sourse == "" || destination == "" || x == -1 || y == -1 || width == -1 || heigth == -1)
	{
		delete[] line;
		delete[] sourse;
		delete[] destination;
		return;
	}
	Image img(sourse);
	Image newImage;
	newImage.Crop(img, x, y, width, heigth);
	newImage.Save(destination);

	delete[] line;
	delete[] sourse;
	delete[] destination;
}
