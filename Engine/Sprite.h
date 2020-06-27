#pragma once
#include "BMP.h"
#include "Vector2.h"
#include "Rect.h"
#include "Graphics.h"
#include "Colors.h"

class Sprite
{
public:
	Sprite(int width, int height, const IntRect& clipBounds, const char* filename, int frameTime);
	int GetState() const;
	int GetFrameTime() const;
	void SetState(int state);
	void SetFrameTime(int ft);
	void AdvanceFrame();
	void Draw(int x, int y, Graphics& gfx, Color chroma) const;
private:
	BMP image;
	IntRect clipBounds;
	IntRect drawRect;
	IntVector2 drawRectPos;
	const int nFrames;
	const int nStates;
	int currState;
	int frameTime;
};

