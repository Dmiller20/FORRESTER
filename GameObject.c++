/*#ifndef __GameObject__
#define __GameObject__
#include "TextureManager.c++"




class GameObject
{
public:
		GameObject(const char* texturesheet, int x, int y)
		{
			
			objTexture = TextureManager::LoadTexture(texturesheet);

			xpos = x;
			ypos = y;
		}
		~GameObject()
		{

		}

		void Update()
		{
			xpos++;
			ypos = 0;

			srcRect.h = 64;
			srcRect.w = 64;
			srcRect.x = 0;
			srcRect.y = 0;

			destRect.x = xpos;
			destRect.y = ypos;
			destRect.w = srcRect.w * 2;
			destRect.h = srcRect.h * 2;
		}
		void Render()
		{
			SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
		}

private:
		int xpos;
		int ypos;

		SDL_Texture* objTexture;
		SDL_Rect srcRect, destRect;	
};

#endif*/