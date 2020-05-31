#pragma once
#include <string>
#include <Windows.h>
#include "Graphics.h"

class BMP
{
public:
	BMP(const std::string& filename);
	~BMP();	
	
	BITMAPFILEHEADER bmpFileHeader;
	BITMAPINFOHEADER bmpInfoHeader;	

	void print(Graphics& gfx) const;
	
private:
	int bitDepth = bmpInfoHeader.biBitCount;
	int width = bmpInfoHeader.biWidth;
	int height = bmpInfoHeader.biHeight;
	int bytesPerPixel = bitDepth / 8;
	unsigned char* image = nullptr;
};

