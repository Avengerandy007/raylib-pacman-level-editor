#include "../include/Update.hpp"
#include "../libpacman/include/Tile.hpp"
#include <iostream>
#include <memory>
#include "../libpacman/include/FileI.hpp"
#define println(x) std::cout << x << "\n"

void InitRaylib(){
	SetTargetFPS(165);
	InitWindow(1000, 1000, "Pacman");
	SetExitKey(KEY_NULL);
}

void InitTextures(){
	Wall::Texture();
	Player::Texture();
}

int main(){
	std::cout << "Hello World!" << std::endl;
	InitRaylib();
	println("Started raylib");
	InitTextures();
	Tile::InitTileSet();
	Tile::tileSet.matrix[0][0].m_containedEntity = std::make_unique<Player>();
	Tile::tileSet.matrix[0][0].m_containedEntity->rect = Tile::tileSet.matrix[0][0].m_def;
	println("Created tiles");
	Update();
	println("Update cycle finished");
	CloseWindow();
}
