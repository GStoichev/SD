#pragma once

#include <iostream>
#include <fstream>
class DIBHeader
{
public:
	DIBHeader();
	DIBHeader(std::ifstream& istream);
	void Update(const int width,const int height);
	void Load(std::ifstream& istream);
	int GetSize() const;
	int GetWidth() const;
	int GetHeigth() const;
	int GetSPlates() const;
	int GetPixels() const;
	int GetCompression() const;
	int GetSizeRaw() const;
	int GetHorizontalResolution() const;
	int GetVerticalResolution() const;
	int GetColorInPlate() const;
	int GetImportantColor() const;
	void Save(std::ostream& ostream);

private:
	int size; //size of inforamtion header
	int width; //width of image
	int heigth; //heigth of image
	short plates; // number of color plates
	short pixels; // bits per pixel
	int comperession; // used compression method
	int sizeRaw; //size of raw bitmap data
	int horizontalResolution; //horizontal resolution of image per pixel
	int verticalResolution; //vertical resolution of image per pixel
	int colorsInPlate; //number of colors in color plate
	int imporatantColors; //number of imporatant colors
	
};

