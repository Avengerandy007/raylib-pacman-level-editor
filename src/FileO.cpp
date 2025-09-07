#include "../include/FileO.hpp"
#include <filesystem>
#include <string>
bool SaveKeyPressed(){
	if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_S)){
		return true;
	}
	else return false;
}

void Save(){
	std::string fileName = "";
	std::cout << "Enter file name\n";
	std::cin >> fileName;
	if (!DirectoryExists("./levels")){
		std::filesystem::create_directories("./levels");
	}
	std::fstream file("./levels/" + fileName, std::ios::trunc | std::ios::out);
	std::cout << "Created file stream\n";
	std::string fileContent = "";
	std::cout << "Opened file stream\n";
	Coin::coinCount = 0;
	for (int i = 0; i < 20; i++){
		for (int k = 0; k < 20; k++){
			if (Tile::tileSet.matrix[i][k].m_containedEntity == nullptr){
				if (Tile::tileSet.matrix[i][k].m_coinContainer){
					Coin::coinCount++;
					fileContent += std::to_string(COIN);
				}else{
					fileContent += std::to_string(EMPTY);
				}
				
			}else{
				fileContent += std::to_string(Tile::tileSet.matrix[i][k].m_containedEntity->typeId);
			}
		}
	}
	fileContent.insert(0, std::to_string(Coin::coinCount));
	fileContent.insert(std::to_string(Coin::coinCount).length(), ",");
	file << fileContent;
	file.close();
	std::cout << "File is " << file.is_open() << "\n";
}
