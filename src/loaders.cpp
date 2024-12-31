#include "loaders.h"


void AssetLoader::load()
{
    m_Characters = LoadTexture("assets/spritesheet_players.png");
    m_Tiles = LoadTexture("assets/spritesheet_ground.png");

    m_Tile[0] = {-18,-18, -18, -18};
    m_Tile[1] = {0, TILE_WIDTH * 1, TILE_WIDTH, TILE_HEIGHT};
    m_Tile[2] = {TILE_WIDTH * 1, 0, TILE_WIDTH, TILE_HEIGHT};
    m_Tile[3] = {0, 0, TILE_WIDTH, TILE_HEIGHT};
    m_Tile[4] = {0, TILE_HEIGHT * 2, TILE_WIDTH, TILE_HEIGHT};
    // 24 x 24

    // Player Load green

    m_Assets["player_green_1_left"] = {512, 512, -WIDTH, HEIGHT};
    m_Assets["player_green_2_left"] = {512, 256, -WIDTH, HEIGHT};

    m_Assets["player_green_1_right"] = {512, 512, WIDTH, HEIGHT};
    m_Assets["player_green_2_right"] = {512, 256, WIDTH, HEIGHT};

    m_Assets["player_green_idle_left"] = {640, 0, WIDTH, HEIGHT};
    m_Assets["player_green_idle_right"] = {640, 0, -WIDTH, HEIGHT};

    m_Assets["player_green_jump_left"] = {512, 1536, -WIDTH, HEIGHT};
    m_Assets["player_green_jump_right"] = {512, 1536, WIDTH, HEIGHT};


    m_Assets["player_blue_1"] = {WIDTH * 2, 0, WIDTH, HEIGHT};
    m_Assets["player_blue_2"] = {WIDTH * 3, 0, WIDTH, HEIGHT};
    m_Assets["player_pink_1"] = {WIDTH * 4, 0, WIDTH, HEIGHT};
    m_Assets["player_pink_2"] = {WIDTH * 5, 0, WIDTH, HEIGHT};

    m_Assets["player_yellow_1"] = {WIDTH * 6, 0, WIDTH, HEIGHT};
    m_Assets["player_yellow_2"] = {WIDTH * 7, 0, WIDTH, HEIGHT};

    m_Assets["player_beige_1"] = {0, HEIGHT * 1, WIDTH, HEIGHT};
    m_Assets["player_beige_2"] = {WIDTH * 1, HEIGHT * 1, WIDTH, HEIGHT};

    m_Assets["player_pink_1"] = {WIDTH * 4, 0, WIDTH, HEIGHT};

    // Enemy Load
    m_Assets["enemy_spike"] = {WIDTH * 8, 0, WIDTH, HEIGHT};

    m_Assets["enemy_box_1"] = {WIDTH * 2, HEIGHT * 1, WIDTH, HEIGHT};
    m_Assets["enemy_box_2"] = {WIDTH * 3, HEIGHT * 1, WIDTH, HEIGHT};

    m_Assets["enemy_drill_1"] = {WIDTH * 6, HEIGHT * 1, WIDTH, HEIGHT};
    m_Assets["enemy_drill_2"] = {WIDTH * 7, HEIGHT * 1, WIDTH, HEIGHT};
    m_Assets["enemy_drill_3"] = {WIDTH * 8, HEIGHT * 1, WIDTH, HEIGHT};

    m_Assets["enemy_bug_small_2"] = {WIDTH * 1, HEIGHT * 2, WIDTH, HEIGHT};
    m_Assets["enemy_bug_small_3"] = {WIDTH * 2, HEIGHT * 2, WIDTH, HEIGHT};
    m_Assets["enemy_bug_small_1"] = {0, HEIGHT * 2, WIDTH, HEIGHT};

    m_Assets["enemy_bug_large_1"] = {WIDTH * 3, HEIGHT * 2, WIDTH, HEIGHT};
    m_Assets["enemy_bug_large_2"] = {WIDTH * 4, HEIGHT * 2, WIDTH, HEIGHT};
    m_Assets["enemy_bug_large_3"] = {WIDTH * 5, HEIGHT * 2, WIDTH, HEIGHT};

    m_Assets["enemy_fly_1"] = {WIDTH * 6, HEIGHT * 2, WIDTH, HEIGHT};
    m_Assets["enemy_fly_2"] = {WIDTH * 7, HEIGHT * 2, WIDTH, HEIGHT};
    m_Assets["enemy_fly_3"] = {WIDTH * 8, HEIGHT * 2, WIDTH, HEIGHT};

}

void AssetLoader::cleanUp()
{
    UnloadTexture(m_Characters);
}


Rectangle AssetLoader::getAssets(std::string name)
{
    return m_Assets.at(name);
}

Rectangle AssetLoader::getTiles(unsigned int id)
{
    return m_Tile.at(id);
}

Texture2D AssetLoader::getCharacters()
{
    return m_Characters;
}

Texture2D AssetLoader::getTiles()
{
    return m_Tiles;
}