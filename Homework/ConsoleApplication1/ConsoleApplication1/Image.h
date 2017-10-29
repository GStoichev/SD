#pragma once
#include "BitmapFileHeader.h"
#include "DIBHeader.h"
#include "PixelArray.h"
#include <cmath>

class Image
{

public:
	Image();
	Image(const char* location);
	void Load(const char* location);
	void Save(const char* location);
	Image& Crop(Image image,const int x,const int y,const int width,const int heigth); 

private:
	int state; // state of file 0 is for OK, other are different kind of errors
	BitmapFileHeader BMPFileHeader;
	DIBHeader infoHeader;
	PixelArray pixelArray;

};
