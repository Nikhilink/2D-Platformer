#include "scenes.h"

Level1Scene::Level1Scene(AssetLoader assetLoader): m_AssetLoader(assetLoader)
{

}

void Level1Scene::initialize()
{
    map = TileMap("level1.txt", m_AssetLoader);

    #pragma region Player Animations
    #pragma region Idle Anim
    std::vector<Rectangle> idle_left_frames;
    std::vector<float> idle_left_key_frames;

    idle_left_frames.push_back(m_AssetLoader.getAssets("player_green_idle_left"));

    idle_left_key_frames.push_back(.0f);
    idle_left_key_frames.push_back(.3f);

    std::shared_ptr<AnimationClip> idleLeftClip =std::make_shared<AnimationClip>(idle_left_frames, idle_left_key_frames);
    #pragma endregion
    #pragma region Idle Anim Right
    std::vector<Rectangle> idle_right_frames;
    std::vector<float> idle_right_key_frames;

    idle_right_frames.push_back(m_AssetLoader.getAssets("player_green_idle_right"));

    idle_right_key_frames.push_back(.0f);
    idle_right_key_frames.push_back(.3f);

    std::shared_ptr<AnimationClip> idleRightClip =std::make_shared<AnimationClip>(idle_right_frames, idle_right_key_frames);
    #pragma endregion
    #pragma region Walk Left
    std::vector<Rectangle> walk_frames;
    std::vector<float> walk_key_frames;

    walk_frames.push_back(m_AssetLoader.getAssets("player_green_1_left"));
    walk_frames.push_back(m_AssetLoader.getAssets("player_green_2_left"));

    walk_key_frames.push_back(.0f);
    walk_key_frames.push_back(.1f);
    walk_key_frames.push_back(.2f);

    std::shared_ptr<AnimationClip> walkLeftClip =std::make_shared<AnimationClip>(walk_frames, walk_key_frames);
    #pragma endregion
    #pragma region Walk Right Anim
    std::vector<Rectangle> blue_walk_frames;
    std::vector<float> blue_walk_key_frames;

    blue_walk_frames.push_back(m_AssetLoader.getAssets("player_green_1_right"));
    blue_walk_frames.push_back(m_AssetLoader.getAssets("player_green_2_right"));

    blue_walk_key_frames.push_back(.0f);
    blue_walk_key_frames.push_back(.2f);
    blue_walk_key_frames.push_back(.3f);


    std::shared_ptr<AnimationClip> walkRightClip =std::make_shared<AnimationClip>(blue_walk_frames, blue_walk_key_frames);
    #pragma endregion
    #pragma region Jump Left
    std::vector<Rectangle> jump_left_frames;
    std::vector<float> jump_left_key_frames;

    jump_left_frames.push_back(m_AssetLoader.getAssets("player_green_jump_left"));

    jump_left_key_frames.push_back(.0f);
    jump_left_key_frames.push_back(.3f);

    std::shared_ptr<AnimationClip> jumpLeftClip =std::make_shared<AnimationClip>(jump_left_frames, jump_left_key_frames);

    #pragma endregion
    std::vector<Rectangle> jump_right_frames;
    std::vector<float> jump_right_key_frames;

    jump_right_frames.push_back(m_AssetLoader.getAssets("player_green_jump_right"));

    jump_right_key_frames.push_back(.0f);
    jump_right_key_frames.push_back(.3f);

    std::shared_ptr<AnimationClip> jumpRightClip =std::make_shared<AnimationClip>(jump_right_frames, jump_right_key_frames);

    std::shared_ptr<GameObject> player = std::make_shared<Player>("Player",Vector2{128.0f, 256.0f}, m_AssetLoader.getCharacters());
    player->addAnimaton("walk", walkLeftClip);
    player->addAnimaton("blue_walk", walkRightClip);
    player->addAnimaton("idle_left", idleLeftClip);
    player->addAnimaton("idle_right", idleRightClip);
    player->addAnimaton("jump_left", jumpLeftClip);
    player->addAnimaton("jump_right", jumpRightClip);
    player->setAnimationState("idle_right");

    m_GameObjects.push_back(player);

    #pragma endregion
}

void Level1Scene::update()
{
    for(int i = 0;i < m_GameObjects.size();i++)
    {
        m_GameObjects[i]->update();
    }
}
void Level1Scene::render()
{
    map.render();
    for(int i = 0;i < m_GameObjects.size();i++)
    {
        m_GameObjects[i]->render();
    }
}
void Level1Scene::cleanUp()
{
}
void Level1Scene::input()
{
    for(int i = 0;i < m_GameObjects.size();i++)
    {
        m_GameObjects[i]->input();
    }
}