#include "registry.h"
#include "entity.h"
#include "sprite_component.h"
#include <memory>
#include <type_traits>

ECS::SpriteComponent *
ECS::Registry::createSpriteComponent()
{
    ++entities;
    spriteComponentRegistry[entities] = std::make_unique<SpriteComponent>(entities);
    return spriteComponentRegistry[entities].get();
}