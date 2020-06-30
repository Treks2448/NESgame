#include "Sprite.h"

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

	// go to the next frame
	if (drawRectPos.x + drawRect.GetWidth() >= image.bmpInfoHeader.biWidth -1)
		drawRectPos.x = 0;
	else
		drawRectPos.x += drawRect.GetWidth();
	
	timer = 0;
}

void Sprite::Draw(int xPos, int yPos, Graphics& gfx, Color chromaKey) const
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
			Color pixel = image.GetPixel(x, y);
			if (pixel.dword == chromaKey.dword) continue;
			
			gfx.PutPixel(drawX, drawY, pixel);
		}
		
	}
}

void Sprite::SetState(int state)
{
	if (state >= nStates) return;
	currState = state;
	drawRectPos.y = state * drawRect.GetWidth();
}

void Sprite::SetFrameTime(int ft)
{
	frameTime = ft;
}
