#include "../include/FileO.hpp"
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
	std::fstream file;
	std::cout << "Created file stream\n";
	file.open(fileName, std::ios::trunc | std::ios::out);
	std::cout << "Opened file stream\n";
	for (int i = 0; i < 20; i++){
		for (int k = 0; k < 20; k++){
			if (Tile::tileSet.matrix[i][k].m_containedEntity == nullptr){
				file << EMPTY;
			}else file << Tile::tileSet.matrix[i][k].m_containedEntity->typeId;
		}
	}
	file.close();
	std::cout << "File is " << file.is_open() << "\n";
}
