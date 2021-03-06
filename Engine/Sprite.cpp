#include "Sprite.h"
#include <fstream>

Sprite::Sprite(int width, int height, const IntRect& clipBounds, const char* filename, float frameTime)
	:
	frameTime(frameTime),
	drawRect(0, width, height, 0),
	clipBounds(clipBounds),
	image(filename),
	drawRectPos(0, 0),
	nFrames(image.bmpInfoHeader.biWidth / width),
	nStates(image.bmpInfoHeader.biHeight / height),
	currState(0),
	timer(0)
{
}

int Sprite::GetState() const
{
	return currState;
}

int Sprite::GetFrameTime() const
{
	return frameTime;
}

void Sprite::AdvanceFrame(float deltaTime)
{
	// increment timer
	timer += deltaTime;
	if (timer < frameTime) { return; }
	else timer = 0.f;

	// go to the next frame
	if (drawRectPos.x + drawRect.GetWidth() >= image.bmpInfoHeader.biWidth -1)
		drawRectPos.x = 0;
	else
		drawRectPos.x += drawRect.GetWidth();
	
}

void Sprite::SetFrame(int frame)
{
	// Verify that correct frame is input
	if (frame > nFrames) throw std::runtime_error("The requested frame is larger than the total number of frames.");

	drawRectPos.x = frame * drawRect.GetWidth();
}

void Sprite::Draw(int xPos, int yPos, Graphics& gfx, const Color& chromaKey) const
{
	for (int x = drawRectPos.x; x < drawRectPos.x + drawRect.GetWidth(); x++)
	{
		for (int y = drawRectPos.y; y < drawRectPos.y + drawRect.GetHeight(); y++)
		{
			// Check whether pixel is within draw bounds
			int drawX = xPos + x - drawRectPos.x;
			int drawY = yPos + y - drawRectPos.y;
 			if (!clipBounds.Contains(drawX, drawY)) continue;
			
			// Check whether the pixel isn't same colour as chroma
			if (image.GetPixel(x,y).dword == chromaKey.dword) continue;
			
			gfx.PutPixel(drawX, drawY, image.GetPixel(x, y));
		}
	}
}

void Sprite::SetState(int state)
{
	if (state >= nStates) return;
	currState = state;
	drawRectPos.y = state * drawRect.GetWidth();
}

void Sprite::SetFrameTime(float ft)
{
	frameTime = ft;
}
