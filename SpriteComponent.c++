#pragma once
#include "Components.c++"
#include <sdl/SDL.h>
#include "TextureManager.c++"
class SpriteComponent : public Component
{
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path)
    {
        setTex(path);
    }
    ~SpriteComponent()
    {
        SDL_DestroyTexture(texture);
    }
    void setTex(const char* path)
    {
        texture = TextureManager::LoadTexture(path);
    }

    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;
    }

    void update() override
    {
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }

private:
TransformComponent* transform;
SDL_Texture *texture;
SDL_Rect srcRect, destRect;

};