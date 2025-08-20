#include "../libpacman/include/Entity.hpp"
#include <cstdint>
#include <tuple>
#pragma once
extern void PollClicks();
extern bool LeftClick();
extern bool RightClick();
extern std::tuple<uint8_t, uint8_t> GetTileUnderMouse();
extern void PlaceEntity();
extern void RemoveEntity();
