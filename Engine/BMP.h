#pragma once
#include <string>
#include <Windows.h>
#include "Colors.h"
#include "Graphics.h"

class BMP
{
public:
	BMP(const std::string& filename);
	// TODO: implement rule of five
	~BMP();
	void Print(Graphics& gfx, int x, int y);
	Color GetPixelNoAlpha(int x, int y) const;
	Color GetPixel(int x, int y) const;
public:
	BITMAPFILEHEADER bmpFileHeader;
	BITMAPINFOHEADER bmpInfoHeader;
private:
	int bitDepth = bmpInfoHeader.biBitCount;
	int width = bmpInfoHeader.biWidth;
	int height = bmpInfoHeader.biHeight;
	int bytesPerPixel = bitDepth / 8;
	unsigned char* image = nullptr;
};

