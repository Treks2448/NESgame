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
}

BMP::~BMP()
{
	delete[] image;
	image = nullptr;
}

void BMP::print(Graphics& gfx) const
{
	for (int iy = 0; iy < height; iy++)
	{
		for (int ix = 0; ix < width; ix++)
		{
			int iPixel = bytesPerPixel * ix + iy * width * bytesPerPixel;
			gfx.PutPixel(ix, iy, image[iPixel + 2], image[iPixel + 1], image[iPixel + 0]);

			// TODO: add alpha channel to the image 
		}
	}
}
