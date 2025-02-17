#ifndef _ENTITY_H
#define _ENTITY_H

#include "SDL3/SDL_stdinc.h"
#include "sprite_component.h"
#include <memory>

class Entity
{
  public:
    Entity(Uint64 id);
    ~Entity();
    Uint64 id;

  private:
    Entity();
};

#endif