#include "BMP.h"
#include <fstream>
#include "Graphics.h"

BMP::BMP(const std::string& filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (!in) throw ("File could not be read.");
	
	// get the details of the file 
	in.read(reinterpret_cast<char*>(&bmpFileHeader), sizeof(bmpFileHeader));
	in.read(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(bmpInfoHeader));
	
	// Read and store some image data
	bitDepth = bmpInfoHeader.biBitCount;
	width = bmpInfoHeader.biWidth;
	height = bmpInfoHeader.biHeight;
	bytesPerPixel = bitDepth / 8;

	// Check for incompatibilities
	if (bitDepth != 24 && bitDepth != 32) throw std::runtime_error("Unsupported bit depth.");
	if (bmpFileHeader.bfType != 0x4D42) throw std::runtime_error("Unrecognised file format.");
	if (height <= 0) throw std::runtime_error("File reader only supports bitmaps which start from the bottom right corner");
	
	// Array storing the image being read
	// Each element is a colour (unsigned char)
	// 3-4 colours per pixel (4th is alpha)
	long size = bytesPerPixel * width * height;
	image = new unsigned char[size];

	// Length of a row of pixels in the image array
	int rowStride = width * bytesPerPixel;

	// Padding is added at the end of each row in bitmap files
	// such that the width of the image is a multiple of 4 bytes
	int padding = (4 - (bytesPerPixel * width) % 4) % 4;

	// Seek to the start of the image
	in.seekg(bmpFileHeader.bfOffBits, in.beg);

	for (int iy = (height - 1); iy >= 0; --iy)
	{
		// Read the length of one row of pixels and store that in the array
		int curPos = rowStride * iy; 
		in.read(reinterpret_cast<char*>(image + curPos), rowStride);
		in.seekg(padding, in.cur); // not necessary for 32 bit image
	}

	pixels = new Color[width * height];

	for (int ix = 0; ix < width; ix++)
	{
		for (int iy = 0; iy < height; iy++)
		{
			int rowStride = width * bytesPerPixel;
			int i = ix * bytesPerPixel + iy * rowStride;
			//agbr
			Color c;
			if (bytesPerPixel == 3) pixels[ix + iy * width] = Color(image[i + 2], image[i + 1], image[i + 0]);
			else pixels[ix + iy * width] = Color(image[i + 3], image[i + 2], image[i + 1], image[i + 0]);
		}
	}
}

BMP::~BMP()
{
	delete[] image;
	image = nullptr;
	delete[] pixels;
	pixels = nullptr;
}

Color BMP::GetPixelNoAlpha(int x, int y) const
{
	int rowStride = width * bytesPerPixel;
	int i = x * bytesPerPixel + y * rowStride;
	return Color(image[i+2], image[i+1], image[i+0]);
}

Color& BMP::GetPixel(int x, int y) const
{
	/*
	int rowStride = width * bytesPerPixel;
	int i = x * bytesPerPixel + y * rowStride;
	//agbr
	if (bytesPerPixel == 3) return Color(image[i + 2], image[i + 1], image[i + 0]);
	else return Color(image[i+3], image[i+2], image[i+1], image[i+0]);
	*/
	return pixels[x + y * width];
}

void BMP::Print(Graphics& gfx, int in_x, int in_y)
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			int i = (y * width * bytesPerPixel) + x * bytesPerPixel;
			Color c(image[i + 3], image[i + 2], image[i + 1], image[i + 0]);
			gfx.PutPixel(in_x + x, in_y + y, c);

		}

	}
}
