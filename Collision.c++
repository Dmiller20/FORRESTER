#pragma once
#include <sdl/SDL.h>
class Collision
{
public:
    //AABB = access aligned bounding box
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB)
    {
        if(
            recA.x + recA.w >= recB.x &&
            recB.x + recB.w >= recA.x &&
            recA.y + recA.h >= recB.y &&
            recB.y + recB.h >= recA.y 
        )
    {
        return true;
    }
        return false;
    }

};