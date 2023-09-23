#pragma once
#include "Game.c++"
#include "ECS.c++"
#include "Components.c++"

class KeyboardController : public Component
{
public:
    TransformComponent *transform;
    
    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override
    {
        if(event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_w:
                    transform->velocity.y = -1;
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    break;
                default:
                    break;
            }
        }
        if(event.type == SDL_KEYUP)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_w:
                    transform->velocity.y = 0;
                    break;
                case SDLK_a:
                    transform->velocity.x = 0;
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                default:
                    break;
            }
        }
    }
};