#ifndef _REGISTRY_H
#define _REGISTRY_H

#include "SDL3/SDL_stdinc.h"
#include "entity.h"
#include "sprite_component.h"
#include <algorithm>
#include <cstdint>
#include <memory>
#include <unordered_map>

namespace ECS {
class Registry
{
  public:
    Registry(){};
    ~Registry(){};

    Entity *createEntity();
    SpriteComponent *createSpriteComponent();

    Uint64 entities = 0;
    std::unordered_map<Uint64, std::unique_ptr<Entity>> entityRegistry;
    std::unordered_map<Uint64, std::unique_ptr<SpriteComponent>> spriteComponentRegistry;
};
}

#endif