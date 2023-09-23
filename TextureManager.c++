#ifndef __TextureManager__
#define __TextureManager__

#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <vector>

class ColliderComponent;

static SDL_Renderer *renderer = nullptr;
static SDL_Event event;
static std::vector<ColliderComponent*> colliders;

//std::vector<ColliderComponent*> Game::colliders;

class TextureManager
{
	public:
		static SDL_Texture* LoadTexture(const char* texture)
		{
			SDL_Surface* tempSurface = IMG_Load(texture);
			SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer,tempSurface);
			SDL_FreeSurface(tempSurface);

			return tex;
		}
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
	{
		SDL_RenderCopy(renderer, tex, &src, &dest);
	}
	private:
};

#endif