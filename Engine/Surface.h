#pragma once
#include "Rect.h"
#include "Vector2.h"
#include "Colors.h"
#include <string>

class Surface
{
public:
	Surface(int sizeX, int sizeY, std::string filename);

private:
	IntRect drawRect;
	Color* pixels = nullptr;
};

