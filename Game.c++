#ifndef __Game__
#define __Game__
#include "Map.c++"
#include <iostream>
#include "ECS.c++"
#include "Components.c++"
#include "Vector2D.c++"
#include "TextureManager.c++"
#include "Collision.c++"

Map* first_map;

Manager manager;
  auto& player(manager.addEntity());
//auto& house(manager.addEntity());
//auto& tree(manager.addEntity());
//auto& tree1(manager.addEntity());
  auto& wall (manager.addEntity());

class Game
{
	public:
	
	Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
	{
		
		int flags = 0;
		if(fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			std::cout << "Subsystems Initialized!" << std::endl;

			window = SDL_CreateWindow(title, xpos, ypos,
	        width, height, flags);
			if(window)
			{
				std::cout << "Window Created!" << std::endl;
			}
			renderer = SDL_CreateRenderer(window, -1, 0);
			if(renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				std::cout << "Renderer Created!" << std::endl;
			}
			isRunning = true;			
		}
		if(IMG_Init(IMG_INIT_PNG))
			{
				flags = IMG_INIT_PNG;
				int initStatus = IMG_Init(flags);
				if((initStatus & flags) != flags)
				{
					std::cout << "SDL2_Image Format not available" << std::endl;
				}
				
			}
	 	
		first_map = new Map();
		player.addComponent<TransformComponent>();
		player.addComponent<SpriteComponent>("C:/kcgrid/usr/local/etc/100056849/singlesprite.png");
		player.addComponent<KeyboardController>();
		player.addComponent<ColliderComponent>("player");
/*
		house.addComponent<TransformComponent>(725, 210);
		house.addComponent<HouseComponent>("C:/kcgrid/usr/local/etc/100056849/BrickHouse.png");
		tree.addComponent<TransformComponent>(1050, 475);
		tree.addComponent<HouseComponent>("C:/kcgrid/usr/local/etc/100056849/pine_tree.png");
		tree1.addComponent<TransformComponent>(200, 475);
		tree1.addComponent<HouseComponent>("C:/kcgrid/usr/local/etc/100056849/pine_tree.png");
*/
		
		
		wall.addComponent<TransformComponent>(300, 300, 300, 20, 1);
		wall.addComponent<SpriteComponent>("C:/kcgrid/usr/local/etc/100056849/dirt_asset.png");
		wall.addComponent<ColliderComponent>("wall");
	 }



	~Game()
	{

	}
	void handleEvents()
	{
		
		SDL_PollEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
			isRunning = false;
			break;

			default:
			   break;
		}
	}
	void update()
	{
		manager.refresh();
		manager.update();
		//std:: cout << cnt++ << std:: endl;
		if(Collision::AABB(player.getComponent<ColliderComponent>().collider,
							wall.getComponent<ColliderComponent>().collider))
			{
				player.getComponent<TransformComponent>().scale = 1;
				player.getComponent<TransformComponent>().velocity * -1;
				std::cout << "Wall Hit!" << std::endl;
			}
	}
	void render()
	{
		SDL_RenderClear(renderer);
		first_map->DrawMap();
		manager.draw();
		SDL_RenderPresent(renderer);
	}
	void clean()
	{
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		IMG_Quit();
		SDL_Quit();
		std::cout << "Game Cleaned" << std::endl;
	}

	bool running()
	{
		return isRunning;
	} 
	
	
	private:
	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
	
};

#endif