#pragma once
#include "Vector2.h"

class Grid
{
public:
	Grid(const IntVector2& scenePos, int cellLength);
	IntVector2 GetScenePos() const;
	int GetCellLength() const;
	// Returns the scene position of the nearest cell to the specified scene position
	IntVector2 FitToGrid(const IntVector2& scenePos) const;
private:
	IntVector2 scenePos;
	int cellLength;
};

