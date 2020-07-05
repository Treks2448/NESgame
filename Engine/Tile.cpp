#include "Tile.h"


Tile::Tile(const IntVector2& scenePos, int sideLength, Sprite& sprite)
	:
	scenePos(scenePos),
	bounds(0, sideLength, sideLength, 0),
	sprite(&sprite)
{
}

IntVector2 Tile::GetScenePos() const
{
	return scenePos;
}

IntRect Tile::GetBounds() const
{
	return bounds;
}

void Tile::Draw(int x, int y, Graphics& gfx, const Color& c)
{
	sprite->Draw(x, y, gfx, c);
}

