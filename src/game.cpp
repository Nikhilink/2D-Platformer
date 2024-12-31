#include "game.h"

#include "logging.h"

Game::Game()
{
    m_WindowOptions = WindowOptions("Alien Platformer", 1280, 720, 60);
}
Game::Game(WindowOptions options): m_WindowOptions(options)
{

}

void Game::initialize()
{
    SetTraceLogCallback(log);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    InitWindow(m_WindowOptions.width, m_WindowOptions.height, m_WindowOptions.title.c_str());
    SetTargetFPS(m_WindowOptions.fps);

    m_AssetLoader.load();

    loadScenes();
}

void Game::loadScenes()
{
    m_SceneManager.addScene("level_1", std::make_shared<Level1Scene>(m_AssetLoader));
    m_SceneManager.loadScene("level_1");
}

void Game::loop()
{
    while(!WindowShouldClose())
    {
        m_SceneManager.inputScene();
        m_SceneManager.updateScene();

        BeginDrawing();

            ClearBackground(BLACK);
            m_SceneManager.renderScene();
        
        EndDrawing();
    }
}

void Game::cleanUp()
{
    CloseWindow();
}

void Game::runGame()
{
    initialize();

    loop();

    cleanUp();
}