#pragma once
#include <string>
#include <Windows.h>

class BMP
{
public:
	BMP(std::string filename);
	BITMAPFILEHEADER bmpFileHeader;
	BITMAPINFOHEADER bmpInfoHeader;

private:
	int pixelArrayOffset;
	int width;
	int height;
	int bitsPerPixel;
};

