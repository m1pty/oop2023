#include <iostream>
#include <memory>
#include <cmath>
#include "../include/Graphics.hpp"

Tile::Tile() : texture_path(GRASS_PATH), entity_standing(nullptr), is_blocked(false){};
Tile::Tile(std::string& path) : texture_path(path), entity_standing(nullptr), is_blocked(false){}
Tile::Tile(std::string& path, bool is_blocked) : texture_path(path), entity_standing(nullptr), is_blocked(is_blocked){}
