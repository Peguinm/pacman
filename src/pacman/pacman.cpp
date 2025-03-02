#include "pacman.h"
#include "SDL3/SDL_stdinc.h"
#include "entity.h"

#include <iostream>

Pacman::Pacman(Uint64 id, ECS::Registry *registry)
  : Pacman::Entity(id, registry)
{
}

void
Pacman::update()
{
    std::cout << "Sou a porra do pacman" << std::endl;
}

void
Pacman::draw()
{
    std::cout << "Sou a porra do pacman" << std::endl;
}