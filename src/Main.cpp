#include "../include/Update.hpp"
#include "../libpacman/include/Tile.hpp"
#include <iostream>
#include <memory>
#include "../libpacman/include/FileI.hpp"
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
	println("Created tiles");
	Tile::tileSet = FileI::MakeMatrix(FileI::FindFile());
	Tile::InitTileSet();
	for (auto& collumn : Tile::tileSet.matrix){
		for (auto& tile : collumn){
			if (tile.m_containedEntity){
				tile.m_containedEntity->rect = std::make_shared<Rectangle>(tile.m_def);
				std::cout << tile.m_containedEntity->typeId << " at " << tile.m_def.x << ", " << tile.m_def.y << "\n";
			}
			else std::cout << 0 << " at " << tile.m_def.x << ", " << tile.m_def.y << "\n";
		}
	}
	Update();
	println("Update cycle finished");
	CloseWindow();
}
