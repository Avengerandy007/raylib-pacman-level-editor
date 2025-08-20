#include "../include/Update.hpp"
#include "../libpacman/include/Tile.hpp"
#include <iostream>
#include <memory>
#define println(x) std::cout << x << "\n"

void InitRaylib(){
	SetTargetFPS(60);
	InitWindow(1000, 1000, "Pacman");
	SetExitKey(KEY_NULL);
}

void InitTextures(){
	Wall::Texture();
}

int main(){
	std::cout << "Hello World!" << std::endl;
	InitRaylib();
	println("Started raylib");
	InitTextures();
	Tile::InitTileSet();
	println("Created tiles");
	Update();
	println("Update cycle finished");
	CloseWindow();
}
