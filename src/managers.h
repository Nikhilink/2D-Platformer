#pragma once

#include "pch.h"

#include "scenes.h"

class SceneManager
{
    public:
        SceneManager();

        void addScene(std::string sceneName, std::shared_ptr<Scene> scene);

        void loadScene(std::string sceneName);

        void updateScene();
        void renderScene();
        void inputScene();
        void cleanUpScene();

    private:
        std::unordered_map<std::string, std::shared_ptr<Scene>> m_Scenes;
        std::shared_ptr<Scene> m_CurrentScene;
};