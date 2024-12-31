#pragma once

#include "pch.h"

class Transform2D
{
    public:
    Rectangle position;
    float rotation = 0;

    void setScale(float x, float y);

    void setScaleX(float x);

    void setScaleY(float y);
};

class AnimationClip
{
    public:
        // Texture2D spritesheet;

        std::vector<Rectangle> textures;
        std::vector<float> keyFrames;

        AnimationClip(std::vector<Rectangle> textures, const std::vector<float> keyFrames);

        Rectangle getCurrentFrame(float currentTime) const;

        float getTotalDuration() const;
};

class Animation
{
    public:
        std::unordered_map<std::string, std::shared_ptr<AnimationClip>> clips;
        
        std::string currentState;
        float currentTime = 0.0f;
        Texture2D spritesheet;

        Animation(Texture2D texture);
        Animation();

        void addClip(std::string state, std::shared_ptr<AnimationClip> clip);
        void setState(std::string state);
        void update();

        Rectangle getCurrentFrame() const;

        void setCurrentState(std::string state);

        Texture2D getSpriteSheet() const;

        void setSpriteSheet(Texture2D texture);

        ~Animation();
};

class GameObject
{
    public:
        Transform2D transform;
        std::string name;
        Animation animation;

        // GameObject();
        // GameObject(std::string name, Texture2D animationTexture);
        // GameObject(std::string name, Vector2 position, Texture2D animationTexture);
        // GameObject(std::string name, Vector2 position, float rotation, Texture2D animationTexture);

        void addAnimaton(std::string state, std::shared_ptr<AnimationClip> clip);
        void setAnimationState(std::string state);

        virtual void update() = 0;
        void render();
        virtual void input() = 0;

        ~GameObject();
};

class Player : public GameObject
{
    public:

        Player();
        Player(std::string name, Texture2D animationTexture);
        Player(std::string name, Vector2 position, Texture2D animationTexture);
        Player(std::string name, Vector2 position, float rotation, Texture2D animationTexture);


        void update() override;
        void input() override;

    private:
        bool looking_left;
        bool player_idle = true;
};