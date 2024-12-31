#include "game_objects.h"

#pragma region Transform2D

void Transform2D::setScale(float x, float y)
{
    position.width *= x;
    position.height *= y;
}

void Transform2D::setScaleX(float x)
{
    position.width *= x;
}

void Transform2D::setScaleY(float y)
{
    position.height *= y;
}

#pragma endregion
#pragma region GameObject


// GameObject::GameObject()
// {
//     transform.position = {0, 0, 100, 100};
//     transform.rotation = 0.0f;
// }

// GameObject::GameObject(std::string name, Texture2D animationTexture):name(name)
// {
//     animation.setSpriteSheet(animationTexture);
// }

// GameObject::GameObject(std::string name, Vector2 position, Texture2D animationTexture): name(name)
// {
//     transform.position = {position.x, position.y, 100, 100};
//     animation.setSpriteSheet(animationTexture);
// }

GameObject::~GameObject()
{
}

// GameObject::GameObject(std::string name, Vector2 position, float rotation, Texture2D animationTexture): name(name)
// {
//     transform.position = {position.x, position.y, 100, 100};
//     transform.rotation = rotation;
// }

void GameObject::addAnimaton(std::string state, std::shared_ptr<AnimationClip> clip)
{
    animation.addClip(state, clip);
}

void GameObject::setAnimationState(std::string state)
{
    animation.setState(state);
}


// void GameObject::update()
// {
//     animation.update();
// }


void GameObject::render()
{
    Texture2D spritesheet = animation.getSpriteSheet();
    if(spritesheet.id)
    {
        Rectangle currentFrame = animation.getCurrentFrame();
        // TraceLog(LOG_INFO, TextFormat("%f %f %f %f", currentFrame.x,currentFrame.y,currentFrame.width,currentFrame.height));

        DrawTexturePro(spritesheet, currentFrame, transform.position, {0, 0}, transform.rotation, WHITE);

    }

}

// void GameObject::input()
// {
//     if(IsKeyDown(KEY_RIGHT))
//     {
//         setAnimationState("blue_walk");
//     }
//     else
//     {
//         setAnimationState("walk");
//     }
// }

void Player::update()
{
    transform.position.y += 100 * GetFrameTime();
    animation.update(); 
}

// void Player::render()
// {
//     Texture2D spritesheet = animation.getSpriteSheet();
//     if(spritesheet.id)
//     {
//         Rectangle currentFrame = animation.getCurrentFrame();
//         // TraceLog(LOG_INFO, TextFormat("%f %f %f %f", currentFrame.x,currentFrame.y,currentFrame.width,currentFrame.height));

//         DrawTexturePro(spritesheet, currentFrame, transform.position, {0, 0}, transform.rotation, WHITE);

//     }

// }

void Player::input()
{
    if(IsKeyDown(KEY_RIGHT))
    {
        animation.setCurrentState("blue_walk");
        looking_left = false;
        transform.position.x += 200 * GetFrameTime();
    }
    else if(IsKeyDown(KEY_LEFT))
    {
            animation.setCurrentState("walk");
            looking_left = true;
            transform.position.x -= 200 * GetFrameTime();
    }
    else
    {   if(looking_left)
            animation.setCurrentState("idle_left");
        else
            animation.setCurrentState("idle_right");
    }
    if(IsKeyPressed(KEY_SPACE))
    {
        transform.position.y -= 100;
        if(looking_left)
            animation.setCurrentState("jump_left");
        else
            animation.setCurrentState("jump_right");
    }
}

Player::Player()
{
    transform.position = {0, 0, 120, 256};
    transform.rotation = 0.0f;
}

Player::Player(std::string name, Texture2D animationTexture)
{
    this->name = name;
    animation.setSpriteSheet(animationTexture);
}

Player::Player(std::string name, Vector2 position, Texture2D animationTexture)
{
    this->name = name;
    transform.position = {position.x, position.y, 128, 196};
    animation.setSpriteSheet(animationTexture);
}



Player::Player(std::string name, Vector2 position, float rotation, Texture2D animationTexture)
{
    this->name = name;
    transform.position = {position.x, position.y, 100, 200};
    transform.rotation = rotation;
}

#pragma endregion
#pragma region Animation


void Animation::addClip(std::string state, std::shared_ptr<AnimationClip> clip)
{
    clips[state] = clip;
}

void Animation::setState(std::string state)
{
    currentState = state;
    currentTime = 0.0f;
}
void Animation::setCurrentState(std::string state)
{
    currentState = state;
}

Texture2D Animation::getSpriteSheet() const
{
    return spritesheet;
}

void Animation::update()
{
        currentTime = currentTime + GetFrameTime();
        // TraceLog(LOG_INFO, TextFormat("%d %f", currentTime, GetFrameTime()));
        if(currentTime > clips.at(currentState)->getTotalDuration())
        {
            currentTime = 0.0f;
        }
}

Rectangle Animation::getCurrentFrame() const
{
    return clips.at(currentState)->getCurrentFrame(currentTime); // clips["walk"].GetCurrentFrame(currentTime);
}

Animation::Animation()
{

}

Animation::Animation(Texture2D texture): spritesheet(texture)
{

}

Animation::~Animation()
{
}

void Animation::setSpriteSheet(Texture2D tex)
{
    spritesheet = tex;
}


#pragma endregion
#pragma region AnimationClip

Rectangle AnimationClip::getCurrentFrame(float currentTime) const
{
    for(size_t i = 0;i < keyFrames.size(); i++)
    {
        if(currentTime < keyFrames[i])
        {
            return textures[i - 1];
        }
    }
    return textures.back();
}
AnimationClip::AnimationClip(std::vector<Rectangle> textures, const std::vector<float> keyFrames): 
            textures(textures), keyFrames(keyFrames)
{

}
float AnimationClip::getTotalDuration() const
{
    return keyFrames.back();
}

#pragma endregion
