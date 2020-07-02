#pragma once
#include "Rect.h"
#include "Sprite.h"
#include "Vector2.h"

class Tile
{
public:
	Tile(IntVector2 scenePos, int sideLength, Sprite& sprite);
	
	// Returns the tiles position in the scene
	IntVector2 GetScenePos() const;

	// Returns the bounding square of the tile
	IntRect GetBounds() const;
	
	// Draws the tile to the screen
	void Draw(int x, int y);

private:
	const IntVector2 scenePos;
	IntRect bounds;
	Sprite* sprite;
};

