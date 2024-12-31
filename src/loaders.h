#pragma once

#include "pch.h"

constexpr int WIDTH = 128;
constexpr int HEIGHT = 256;

constexpr int TILE_WIDTH = 128;
constexpr int TILE_HEIGHT = 128;

class AssetLoader
{
    public:
        void load();
        void cleanUp();

        Rectangle getAssets(std::string name);
        Rectangle getTiles(unsigned int id);

        Texture2D getCharacters();
        Texture2D getTiles();

    private:
        std::unordered_map<std::string, Rectangle> m_Assets;
        std::unordered_map<unsigned int, Rectangle> m_Tile;


        Texture2D m_Tiles;
        Texture2D m_Characters;
};