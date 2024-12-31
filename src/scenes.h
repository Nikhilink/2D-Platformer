#pragma once

#include "loaders.h"
#include "game_objects.h"
#include "tilemap.h"

class Scene
{
    public:
        virtual void initialize() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void cleanUp() = 0;
        virtual void input() = 0;

        virtual ~Scene() = default;
};

class Level1Scene : public Scene
{
    public:
        Level1Scene(AssetLoader assetLoader);
        void initialize() override;
        void update() override;
        void render() override;
        void cleanUp() override;
        void input() override;

    private:
        AssetLoader m_AssetLoader;

        TileMap map;
        std::vector<std::shared_ptr<GameObject>> m_GameObjects;;
};