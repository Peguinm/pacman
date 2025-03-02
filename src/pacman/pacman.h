#ifndef _PACMAN_H
#define _PACMAN_H

#include "SDL3/SDL_stdinc.h"
#include "entity.h"
#include <cstdint>

class Pacman : public Entity
{
  public:
    Pacman(Uint64 id, ECS::Registry *registry);

    void update() override;
    void draw() override;
};

#endif