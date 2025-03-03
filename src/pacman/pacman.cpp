#include "pacman.h"
#include "SDL3/SDL.h"
#include "SDL3_ttf/SDL_ttf.h"
#include "entity.h"
#include "sprite_component.h"

#include <cstddef>
#include <iostream>

Pacman::Pacman(Uint64 id, ECS::Registry *registry)
  : Entity(id, registry)
  , sprite(NULL)
{
    sprite = registry->createSpriteComponent();
}

void
Pacman::update(SDL_Time deltaTime)
{
}

void
Pacman::draw(SDL_Renderer *renderer)
{
    std::cout << SDL_GetError() << std::endl;
    SDL_FRect rect = {
        .x = 0,
        .y = 0,
        .w = 30,
        .h = 30,
    };

    SDL_RenderFillRect(renderer, &rect);

    TTF_Init();

    

    TTF_Quit();
}