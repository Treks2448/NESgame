#pragma once
#include "Rect.h"
#include "Sprite.h"
#include "Vector2.h"
#include "Graphics.h"
#include "Colors.h"

class Tile
{
public:
	Tile(const IntVector2& scenePos, int sideLength, Sprite& sprite);
	IntVector2 GetScenePos() const;
	IntRect GetBounds() const;
	// Draws the tile to the screen
	void Draw(int x, int y, Graphics& gfx, const Color& chroma);
private:
	const IntVector2 scenePos;
	IntRect bounds;
	Sprite* sprite;
};

