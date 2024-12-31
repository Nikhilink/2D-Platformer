#pragma once

#include "pch.h"

#include "loaders.h"

class Tile
{
    public:
        Tile(unsigned int& tile_id, bool collision, Rectangle position) : tile_id(tile_id), collision(collision), position(position)
        {

        }
        bool collision;
        unsigned int tile_id;
        Rectangle position;
};

class TileMap
{
    std::string m_FilePath;
    unsigned int width, height;
    std::vector<std::vector<Tile>> map;
    AssetLoader loader;

    public:
        TileMap()
        {
            
        }
        TileMap(std::string file_path, AssetLoader loader);
        void loadFile();

        void render();
        void update();

        // void checkCollisions(GameObject& object1, GameObject& object2);

        // void checkTileMapCollisions(GameObject& object);
};