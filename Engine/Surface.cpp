#include "Surface.h"

Surface::Surface(int sizeX, int sizeY, std::string filename)
	:
	drawRect(0, sizeX, 0, sizeY)
{
	std::ifstream in(filename);

	int imageX;
	int imageY;
	pixels = new Color[imageX * imageY]; // needs to be of the size of the image

	// Loop through each pixel in the image and assign that pixels colour to the element of the array
	for (int ix = 0; ix < imageX; ix++)
	{
		for (int iy = 0; iy < imageY; iy++)
		{

		}
	}
}
