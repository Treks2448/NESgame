#pragma once
#include "BMP.h"
#include "Vector2.h"
#include "Rect.h"
#include "Graphics.h"
#include "Colors.h"

class Sprite
{
public:
	Sprite(int init_x, int init_y, int width, int height, const IntRect& clipBounds, const char* filename);
	
	int GetState() const;
	void SetState(int state);

	// Advances the animation by one frame
	void AdvanceFrame();
	// Draws the sprite
	void Draw(Graphics& gfx, Color chroma) const;
private:
	Vector2 pos;

	BMP image;
	IntRect clipBounds;
	IntRect drawRect;
	IntVector2 drawRectPos;
	
	const int nFrames;
	const int nStates;
	int currState;
};

