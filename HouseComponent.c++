#pragma once
#include "SpriteComponent.c++"
#include "TransformComponent.c++"
class HouseComponent : public Component
{
public:
HouseComponent() = default;
HouseComponent(const char* path)
{
    setTex(path);
}
~HouseComponent()
{
    SDL_DestroyTexture(texture1);
}
void setTex(const char* path)
    {
        texture1 = TextureManager::LoadTexture(path);
    }

    void init() override
    {
        transform1 = &entity->getComponent<TransformComponent>();
        
       srcRect1.x = srcRect1.y = 0;
        srcRect1.w = transform1->width * 2;
        srcRect1.h = transform1->height * 2;
        destRect1.w = transform1->width * transform1->scale * 2;
        destRect1.h = transform1->height * transform1->scale * 2;
    }

    void update() override
    {
        destRect1.x = (int)transform1->position.x;
        destRect1.y = (int)transform1->position.y;
        
    }

    void draw() override
    {
        TextureManager::Draw(texture1, srcRect1, destRect1);
    }

private:
SDL_Rect srcRect1 , destRect1;
SDL_Texture* texture1;
TransformComponent* transform1;
};