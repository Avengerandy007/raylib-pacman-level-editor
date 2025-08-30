#include "../include/Update.hpp"
#include "../libpacman/include/Tile.hpp"
#include "../include/MouseLogic.hpp"
#include <iostream>
#include <memory>
#include "../libpacman/include/FileI.hpp"
#define println(x) std::cout << x << "\n"

TypesOfEntities entityToBePlaced = TypesOfEntities::Wall;

void InitRaylib(){
	SetTargetFPS(165);
	InitWindow(1000, 1000, "Pacman");
	SetExitKey(KEY_NULL);
}

void InitTextures(){
	Wall::Texture();
	Player::Texture();
	Coin::Texture();
	Ghost::Texture();
}

int main(){
	std::cout << "Hello World!" << std::endl;
	
	instance = GAME;

	InitRaylib();
	println("Started raylib");

	InitTextures();

	Tile::InitTileSet();
	println("Created tiles");
	Update();

	println("Update cycle finished");

	CloseWindow();
}
