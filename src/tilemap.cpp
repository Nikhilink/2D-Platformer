#include "tilemap.h"
#include "game_objects.h"


TileMap::TileMap(std::string file_path, AssetLoader loader): m_FilePath(file_path), loader(loader)
{
    loadFile();
}

void TileMap::render()
{
    for(std::vector<Tile>& r : map)
    {
        for(Tile& tile: r)
        {
            if(tile.tile_id != 0)
            {
                DrawTexturePro(loader.getTiles(), loader.getTiles(tile.tile_id), tile.position, {0,0}, 0, WHITE);
            }
        }
    }
}


void TileMap::loadFile()
{
    std::ifstream file("C:/Users/nikhi/Documents/nikhil/projects/cpp/Alien Platformer/src/level1.txt");

    if(file.is_open())
    {
        float y = 0;
        std::string line;
        while(std::getline(file, line))
        {
            float x = 0;
            std::vector<Tile> row;

            std::stringstream ss(line);

            unsigned int tile;
            char comma;

            while(ss >> tile)
            {
                if(tile != 0)       // Ground
                    row.push_back(Tile(tile, true, Rectangle{x, y, 128, 128}));
                else 
                    row.push_back(Tile(tile, false,Rectangle{x, y, 128, 128}));
                ss >> comma; 
                x += 128;
            }
            y += 128;

            map.push_back(row);
        }
        file.close();
    }
}

// void TileMap::checkTileMapCollisions(GameObject& object)
// {
//     for(std::vector<Tile>& x_tiles : map)
//     {
//         for(Tile& tile : x_tiles)
//         {
            
//         }
//     }
// }