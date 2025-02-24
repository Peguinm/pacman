#ifndef _ENTITY_H
#define _ENTITY_H

#include "SDL3/SDL_stdinc.h"
#include "sprite_component.h"
#include <memory>

namespace ECS {
class Registry;
}

class Entity
{
  public:
    Entity(Uint64 id, ECS::Registry *registry);
    ~Entity();
    Uint64 id;

  private:
    Entity();
    ECS::Registry *m_registry;
};

#endif