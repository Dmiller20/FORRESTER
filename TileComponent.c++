#include "ECS.c++"
#include "TransformComponent.c++"
#include "SpriteComponent.c++"
#include "sdl/SDL.h"

class TileComponent : public Component
{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;
    SDL_Rect tileRect;
    int tileID;
    char *path;

    TileComponent() = default;
    TileComponent(int x, int y, int w, int h, int id)
    {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = id;

        switch (tileID)
        {
        case 0:
            path = "C:/kcgrid/usr/local/etc/100056849/water_asset.png";
            break;
        case 1:
            path = "C:/kcgrid/usr/local/etc/100056849/dirt_asset.png";
            break;
        case 2:
            path = "C:/kcgrid/usr/local/etc/100056849/grass_asset.png";
            break;
        default:
            break;
        }
        
    }

    void init() override
    {
        entity->addComponent<TransformComponent>(tileRect.x,tileRect.y,tileRect.w,tileRect.h, 1);
        transform = &entity->getComponent<TransformComponent>();

        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }
private:


};