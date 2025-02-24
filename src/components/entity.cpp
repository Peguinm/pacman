#include "entity.h"
#include "SDL3/SDL_stdinc.h"
#include "registry.h"
#include <cstdio>
#include <iostream>

Entity::Entity(Uint64 id, ECS::Registry *registry)
  : id(id)
  , m_registry(registry)
{
    // if (m_registry != nullptr) {
    //     printf("Entity %d -> Tenho um registry %p\n", id, m_registry);

    //     if (id >= 3)
    //         return;

    //     m_registry->createEntity();
    // }
}

Entity::~Entity() {}
