#include "../Raylib/include/raylib.h"
#include "../libpacman/include/Tile.hpp"
#include "../include/MouseLogic.hpp"
#include <iostream>
#include <memory>
#include <cstdint>
#include <tuple>

void PollClicks(){
	if (LeftClick()) PlaceEntity();
	else if (RightClick()) RemoveEntity();
}

void PollKeys(){
	if (IsKeyPressed(KEY_P)){
		entityToBePlaced = TypesOfEntities::Player;
	}else if (IsKeyPressed(KEY_W)){
		entityToBePlaced = TypesOfEntities::Wall;
	}else if (IsKeyPressed(KEY_C)){
		entityToBePlaced = TypesOfEntities::Coin;
	}
}

bool LeftClick(){
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) return true;
	else return false;
}

bool RightClick(){
	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) return true;
	else return false;
}

std::tuple<uint8_t, uint8_t> GetTileUnderMouse(){
	Vector2 pos = GetMousePosition();
	int x = pos.x, y = pos.y;
	x /= 50;
	y /= 50;
	return std::make_tuple(x, y);
}

void CreateEntity(std::tuple<uint8_t, uint8_t>& tile){
	switch (entityToBePlaced) {
		case TypesOfEntities::Wall:
			Tile::tileSet.matrix[std::get<0>(tile)][std::get<1>(tile)].m_containedEntity = std::make_unique<Wall>();
			break;
		case TypesOfEntities::Player:
			Tile::tileSet.matrix[std::get<0>(tile)][std::get<1>(tile)].m_containedEntity = std::make_unique<Player>(std::get<0>(tile), std::get<1>(tile));
			break;

		case TypesOfEntities::Coin:
			Tile::tileSet.matrix[std::get<0>(tile)][std::get<1>(tile)].m_containedEntity = std::make_unique<Coin>();
			break;

	}
}

void PlaceEntity(){
	//Get tile to apply changes
	std::tuple<uint8_t, uint8_t> tile = GetTileUnderMouse();

	//If tile is already ocupied, remove what is inside
	if(Tile::tileSet.matrix[std::get<0>(tile)][std::get<1>(tile)].m_containedEntity != nullptr) Tile::tileSet.matrix[std::get<0>(tile)][std::get<1>(tile)].m_containedEntity = nullptr; 

	//Fill the tile with selected entity type
	CreateEntity(tile);
	if (!Tile::tileSet.matrix[std::get<0>(tile)][std::get<1>(tile)].m_containedEntity) std::cerr << "Did not correctly place entity\n";

	//Set the rect of said entity to this tile
	Tile::tileSet.matrix[std::get<0>(tile)][std::get<1>(tile)].m_containedEntity->rect = Tile::tileSet.matrix[std::get<0>(tile)][std::get<1>(tile)].m_def;
}

void RemoveEntity(){
	std::tuple<uint8_t, uint8_t> tile = GetTileUnderMouse();
	Tile::tileSet.matrix[std::get<0>(tile)][std::get<1>(tile)].m_containedEntity = nullptr;
}
