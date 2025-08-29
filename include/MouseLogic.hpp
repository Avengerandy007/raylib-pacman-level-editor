#include "../libpacman/include/Entity.hpp"
#include <cstdint>
#include <tuple>
#pragma once

enum class TypesOfEntities{
	Wall,
	Player,
	Coin,
};

extern TypesOfEntities entityToBePlaced;
extern void PollClicks();
extern void PollKeys();
extern bool LeftClick();
extern bool RightClick();
extern std::tuple<uint8_t, uint8_t> GetTileUnderMouse();
extern void CreateEntity(std::tuple<uint8_t, uint8_t>& tile);
extern void PlaceEntity();
extern void RemoveEntity();
