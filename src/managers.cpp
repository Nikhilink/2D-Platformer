#include "managers.h"

SceneManager::SceneManager()
{

}

void SceneManager::addScene(std::string sceneName, std::shared_ptr<Scene> scene)
{
    m_Scenes[sceneName] = std::move(scene);
}

void SceneManager::loadScene(std::string sceneName)
{
    TraceLog(LOG_INFO, "Loading Scene");
    auto it = m_Scenes.find(sceneName);

    if(it != m_Scenes.end())
    {
        if(m_CurrentScene != nullptr)
        {
            m_CurrentScene->cleanUp();
        }
        m_CurrentScene = it->second;
        m_CurrentScene->initialize();
    }
    else
    {
        TraceLog(LOG_ERROR, TextFormat("Error: Scene %s does not exist!", sceneName));
        TraceLog(LOG_ERROR, sceneName.c_str());
    }
}

void SceneManager::updateScene()
{
    m_CurrentScene->update();
}

void SceneManager::renderScene()
{
    m_CurrentScene->render();
}

void SceneManager::inputScene()
{
    m_CurrentScene->input();
}

void SceneManager::cleanUpScene()
{
    m_CurrentScene->render();
}
