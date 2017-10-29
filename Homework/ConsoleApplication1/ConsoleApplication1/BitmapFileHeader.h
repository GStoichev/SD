#pragma once

#include <iostream>
#include <fstream>


class BitmapFileHeader
{
public:
	BitmapFileHeader();
	BitmapFileHeader(std::ifstream& istream);
	void Update(const int size);
	void Load(std::ifstream& istream); // loading/reloading header from file stream
	bool CheckFormat(); 
	int GetSize() const;
	int GetOffSet() const;
	void Save(std::ofstream& ostream);

private:
	char identifyer[2]; //contains information for type of file
	int size; // size of file in bytes
	short reserved1; // reserved information for programs like photoshop
	short reserved2; // reserved information for programs like photoshop
	int offset; //starting position of pixel array
	
};