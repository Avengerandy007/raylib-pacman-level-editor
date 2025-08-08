#include "../Raylib/include/raylib.h"
#include "../libpacman/include/Tile.hpp"
#include "../include/MouseLogic.hpp"
#include <memory>
#include <cstdint>

bool Click(){
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) return true;
	else return false;
}

void PlaceEntity(){
	Vector2 pos = GetMousePosition();
	int x = pos.x, y = pos.y;
	x /= 50;
	y /= 50;
	Tile::tileSet.matrix[x][y].m_containedEntity = std::make_unique<Wall>();
	Tile::tileSet.matrix[x][y].m_containedEntity->rect = std::make_shared<Rectangle>(Tile::tileSet.matrix[x][y].m_def);
}
