#pragma once
#include "BMP.h"
#include "Vector2.h"
#include "Rect.h"
#include "Graphics.h"
#include "Colors.h"

class Sprite
{
public:
	Sprite(int width, int height, const IntRect& clipBounds, const char* filename, float frameTime);
	int GetState() const;
	int GetFrameTime() const;
	void SetState(int state);
	void SetFrame(int frame);
	void SetFrameTime(float ft);
	// Advances the animation of the sprite by one frame
	void AdvanceFrame(float deltaTime);
	// Draws the sprite at position (x, y) with specified colour as chroma key
	void Draw(int x, int y, Graphics& gfx, const Color& chroma) const;
private:
	BMP image;
	IntRect clipBounds;
	IntRect drawRect;
	IntVector2 drawRectPos;
	const int nFrames;
	const int nStates;
	int currState;
	float frameTime;
	float timer;
};

