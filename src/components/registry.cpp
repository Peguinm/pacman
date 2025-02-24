#include "registry.h"
#include "sprite_component.h"
#include <memory>

Entity *
ECS::Registry::createEntity()
{
    ++entities;
    entityRegistry[entities] = std::make_unique<Entity>(entities, this);
    return entityRegistry[entities].get();
}

ECS::SpriteComponent *
ECS::Registry::createSpriteComponent()
{
    ++entities;
    spriteComponentRegistry[entities] = std::make_unique<SpriteComponent>(entities);
    return spriteComponentRegistry[entities].get();
}