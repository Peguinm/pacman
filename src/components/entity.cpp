#include "entity.h"
#include "SDL3/SDL.h"
#include "registry.h"
#include <cstdio>
#include <iostream>

Entity::Entity(Uint64 id, ECS::Registry *registry)
  : id(id)
  , m_registry(registry)
{
}

Entity::~Entity() {}
