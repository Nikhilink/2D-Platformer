#pragma once

#include "options.h"
#include "managers.h"

class Game
{
    public:

        Game();
        Game(WindowOptions options);

        void runGame();

    private:
        void initialize();

        void loadScenes();

        void loop();

        void cleanUp();

        WindowOptions m_WindowOptions;

        SceneManager m_SceneManager;

        AssetLoader m_AssetLoader;
};