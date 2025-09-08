#include "../include/Update.hpp"
#include "../libpacman/include/Tile.hpp"
#include "../include/MouseLogic.hpp"
#include "../include/FileO.hpp"
#include "../libpacman/include/FileI.hpp"
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
			if (Tile::tileSet.matrix[i][k].m_containedEntity){
				Tile::tileSet.matrix[i][k].m_containedEntity->Update();
			}
			if(Tile::tileSet.matrix[i][k].m_coinContainer){
				Tile::tileSet.matrix[i][k].m_coinContainer->Update();
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
		PollKeys();

		if (SaveKeyPressed()){
			Save();
		}else if(IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_L)){
			std::ifstream file = FileI::FindFile();
			Tile::tileSet = FileI::MakeMatrix(file);
			Tile::InitTileSet();
			std::cout << "Moved matrix into ram\n";
			Tile::SetEntityRectangles();
		}
	}
}
