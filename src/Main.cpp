#include "../include/Update.hpp"
#include "../libpacman/include/Tile.hpp"
#include <Raylib/include/raylib.h>
#include <iostream>
#include <memory>
#define println(x) std::cout << x << "\n"

void InitRaylib(){
	InitWindow(1000, 1000, "Pacman");
	SetExitKey(KEY_NULL);
	SetTargetFPS(60);
}

int main(){
	std::cout << "Hello World!" << std::endl;
	InitRaylib();
	println("Started raylib");
	Tile::InitTileSet();
	println("Created tiles");
	Tile::tileSet.matrix[0][0].m_containedEntity = std::make_unique<Wall>();
	Tile::tileSet.matrix[1][1].m_containedEntity = std::make_unique<Wall>();
	Tile::tileSet.matrix[1][1].m_containedEntity->rect = std::make_shared<Rectangle>(Tile::tileSet.matrix[1][1].m_def);
	Update();
	println("Update cycle finished");
	CloseWindow();
}
