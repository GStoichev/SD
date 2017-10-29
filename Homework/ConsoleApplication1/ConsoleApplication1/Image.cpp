#include "stdafx.h"
#include "Image.h"

//Constructors
Image::Image()
{
	this->state = 0;
	this->BMPFileHeader = BitmapFileHeader();
	this->infoHeader = DIBHeader();
	this->pixelArray = PixelArray();
}
Image::Image(const char* location)
{
	this->Load(location);
}

//Methods
Image& Image::Crop(Image image,const int x,const int y,const int width,const int heigth)
{
	if (this->state == 2)
	{
		this->state = 0;
	}
	//Check Parameters
	if (image.infoHeader.GetWidth() < x + width || image.infoHeader.GetHeigth() < y + heigth || x < 0 || y < 0 || width <= 0 || heigth <= 0)
	{
		this->state = 2;
		std::cout << "Entered parameters for croping image are invalide!" << std::endl;
		return *this;
	}

	//Copying image to new image
	*this = image;

	//Initzializing temporary variables needed for croping operation
	int rowWidth = (((image.infoHeader.GetPixels() * image.infoHeader.GetWidth() + 31) / 32) * 4); //width in bytes for one row of image
	int newBufSize = ((((image.infoHeader.GetPixels() * width) + 31) / 32) * 4) * heigth; // size in bytes of new image's buffer 
	int oldBufSize = rowWidth * image.infoHeader.GetHeigth(); // size in bytes of image's buffer
	int newSize = newBufSize + image.infoHeader.GetSize() + 14; // size in bytes of new image (14 is constant for size of bitmap file header)
	int oldWidth = image.infoHeader.GetWidth();
	int oldHeight = image.infoHeader.GetHeigth();
	int curPos = 0; // current position in new buffer
	char* oldBuf = image.pixelArray.GetBuffer();
	char* newBuf = new char[newBufSize];
	int bytesPerPixel = image.infoHeader.GetPixels() / 8;

	//Croping a part from image and save it in newBuf
	for (size_t i = (y*rowWidth + x * bytesPerPixel); i < (y+heigth)*rowWidth ; i += rowWidth)
	{
		for (size_t j = 0; j < width * bytesPerPixel; j++)
		{
			newBuf[curPos++] = oldBuf[i+j];
		}
	}

    //Updating new image
	this->BMPFileHeader.Update(newSize);
	this->infoHeader.Update(width, heigth);
	this->pixelArray.Update(newBuf, newBufSize);
		
	return *this;
}
void Image::Load(const char* location)
{
	if (state == 1)
	{
		state = 0;
	}
	std::ifstream stream(location, std::ios::in | std::ios::binary);
	if (!stream)
	{
		state = 1;
		std::cout << "Image at location " << location << " can't load! Try again." << std::endl;		
		this->BMPFileHeader = BitmapFileHeader();
		this->infoHeader = DIBHeader();
		return;
	}
	else
	{
		this->BMPFileHeader = BitmapFileHeader(stream);
		this->infoHeader = DIBHeader(stream);
		stream.seekg(this->BMPFileHeader.GetOffSet()); // set get pointer of stream at starting position of pixel array
		size_t size = (((infoHeader.GetPixels()*infoHeader.GetWidth() + 31) / 32) * 4)*infoHeader.GetHeigth(); // size in bytes of image's pixel array
		this->pixelArray = PixelArray(stream, size);
		
	}

	stream.close();
	
}
void Image::Save(const char* location)
{
	if (state != 0)
	{
		std::cout << "Error at saving image, maybe image is damaged or didn't exist." << std::endl;
	}
	else
	{
		std::ofstream stream(location, std::ios::out | std::ios::binary);
		if (!stream)
		{
			std::cout << "Error image can't be created" << std::endl;
			return;
		}

		this->BMPFileHeader.Save(stream);
		this->infoHeader.Save(stream);
		this->pixelArray.Save(stream);

		stream.close();
	}
}
