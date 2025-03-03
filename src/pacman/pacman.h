#ifndef _PACMAN_H
#define _PACMAN_H

#include "SDL3/SDL.h"
#include "entity.h"
#include "registry.h"
#include "sprite_component.h"
#include <cstdint>

class Pacman : public Entity
{
  public:
    Pacman(Uint64 id, ECS::Registry *registry);

    ECS::SpriteComponent *sprite;

    void update(SDL_Time deltaTime) override;
    void draw(SDL_Renderer *renderer) override;
};

#endif