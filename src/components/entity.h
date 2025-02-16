#ifndef _ENTITY_H
#define _ENTITY_H

#include "registry.h"
#include "sprite_component.h"
#include <memory>

class Entity
{
  private:
    Entity();
    ~Entity();

    std::unique_ptr<SpriteComponent> m_spriteComponent;
    std::unique_ptr<ecs::Registry> m_registry;
};

#endif