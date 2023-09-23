#pragma once
#include "Game.c++"
#include "TextureManager.c++"
#include <iostream>



//levels
int lvl1[24][40] = 
{
      
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 1,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1 },
    { 1,1,4,3,3,3,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,3,3,3,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,3,3,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,3,3,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,3,3,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,1 },
    { 1,1,4,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,1 },
    { 1,1,4,2,2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,2,3,3,2,2,2,2,2,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1 },
    { 1,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
   
};
class Map
{
public:

    Map()
    {
        dirt = TextureManager::LoadTexture("C:/kcgrid/usr/local/etc/100056849/dirt_asset.png");
        grass = TextureManager::LoadTexture("C:/kcgrid/usr/local/etc/100056849/grass_asset.png");
        water = TextureManager::LoadTexture("C:/kcgrid/usr/local/etc/100056849/water_asset.png");
        sand = TextureManager::LoadTexture("C:/kcgrid/usr/local/etc/100056849/sand_asset.png");
        sky = TextureManager::LoadTexture("C:/kcgrid/usr/local/etc/100056849/sky_asset.png");

        LoadMap(lvl1);
        src.x = 0;
        src.y = 0;
        src.w = dest.w = 32;
        src.h = dest.h = 32;


        dest.x = 0;
        dest.y = 0;
        // sky = 0, water = 1, grass = 2, dirt = 3, sand = 4
    }

    ~Map()
    {
        SDL_DestroyTexture(dirt);
        SDL_DestroyTexture(grass);
        SDL_DestroyTexture(water);
        SDL_DestroyTexture(sand);
        SDL_DestroyTexture(sky);
    }

    void LoadMap(int arr[24][40])
    {
        for (int row = 0; row < 24; row++)
        {
            for (int column = 0; column < 40; column++)
            {
                map[row][column] = arr[row][column];
            }
        }
    }

    void DrawMap()
    {
        int type = 0;

         for (int row = 0; row < 24; row++)
        {
            for (int column = 0; column < 40; column++)
            {
                type = map[row][column];

                dest.x = column * 32;
                dest.y = row * 32;

                switch (type)
                {
                    case 0:
                        TextureManager::Draw(sky, src, dest);
                    case 1:
                        TextureManager::Draw(water, src, dest);
                        break;
                    case 2:
                        TextureManager::Draw(grass, src, dest);
                        break;
                    case 3:
                        TextureManager::Draw(dirt, src, dest);
                        break;
                    case 4:
                    TextureManager::Draw(sand, src, dest);
                    break;
                    default:
                        break;
                }
            }
        }
    }

private:

   SDL_Rect src,dest;
   SDL_Texture* dirt;
   SDL_Texture* grass;
   SDL_Texture* water;
   SDL_Texture* sand;
   SDL_Texture* sky;
    int map[24][40];

};