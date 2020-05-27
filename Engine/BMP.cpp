#include "BMP.h"
#include <fstream>

BMP::BMP(std::string filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		// check whether the file is of the correct type.


		// find the offset to the pixel array
		std::string offsetBits;
		in.seekg(sizeof(bmpFileHeader) - sizeof(DWORD));
		for (int i = 0; i < sizeof(DWORD); offsetBits.push_back(in.get()));

		
		// find out how many bits per pixel
		// find the size of the image (w and h)
		// 
	}
	int t =69;
}
