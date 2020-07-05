#include "Grid.h"
#include <cmath>

Grid::Grid(const IntVector2& scenePos, int cellLength)
    :
    scenePos(scenePos),
    cellLength(cellLength)
{
}

IntVector2 Grid::GetScenePos() const
{
    return scenePos;
}

int Grid::GetCellLength() const
{
    return cellLength;
}

IntVector2 Grid::FitToGrid(const IntVector2& worldPos) const
{
    int nCellsX = std::floor(worldPos.x / cellLength);
    int nCellsY = std::floor(worldPos.y / cellLength);
    IntVector2 newPos = scenePos + IntVector2(nCellsX * cellLength, nCellsY * cellLength);
    return newPos;
}
