#ifndef _ENTITY_H
#define _ENTITY_H

#include "SDL3/SDL.h"
#include "sprite_component.h"
#include <memory>

namespace ECS {
class Registry;
}

class Entity
{
  public:
    Entity(Uint64 id, ECS::Registry *registry);
    virtual ~Entity();
    Uint64 id;

    virtual void update(SDL_Time deltaTime){};
    virtual void draw(SDL_Renderer *renderer){};

  private:
    Entity();

  protected:
    ECS::Registry *m_registry;
};

#endif