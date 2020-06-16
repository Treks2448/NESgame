#pragma once
#include <string>
#include <Windows.h>
#include "Colors.h"
#include "Graphics.h"

class BMP
{
public:
	BMP(const std::string& filename);
	BMP(const BMP& bmp) = delete; //TODO: implement copy constructor and copy assignment
	~BMP();

	BITMAPFILEHEADER bmpFileHeader;
	BITMAPINFOHEADER bmpInfoHeader;

	Color GetPixelNoAlpha(int x, int y) const;
	Color GetPixel(int x, int y) const;

	void Print(Graphics& gfx, int x, int y);
	
private:
	int bitDepth = bmpInfoHeader.biBitCount;
	int width = bmpInfoHeader.biWidth;
	int height = bmpInfoHeader.biHeight;
	int bytesPerPixel = bitDepth / 8;
	unsigned char* image = nullptr;
};

