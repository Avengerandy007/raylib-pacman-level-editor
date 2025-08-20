#include "../include/Update.hpp"
#include "../libpacman/include/Tile.hpp"
#include "../include/MouseLogic.hpp"
#include "../include/FileIO.hpp"
#include <cstdint>
#include <iostream>

void ResfreshWindow(){
	BeginDrawing();

	ClearBackground(BLACK);

	EndDrawing();
}

void UpdateTiles(){
	for (uint8_t i = 0; i < 20; i++){
		for (uint8_t k = 0; k < 20; k++){
			if (!Tile::tileSet.matrix[i][k].m_containedEntity) continue;
			else{
				Tile::tileSet.matrix[i][k].m_containedEntity->Update();
			}
		}
	}
}

void Update(){
	bool running = true;
	while (running){
		if (WindowShouldClose()) running = false;
		ResfreshWindow();
		UpdateTiles();
		PollClicks();
		if (SaveKeyPressed()){
			Save();
		}
	}
}
