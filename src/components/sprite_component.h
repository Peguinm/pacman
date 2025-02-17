#ifndef _SPRITE_COMPONENT_H
#define _SPRITE_COMPONENT_H

#include "SDL3/SDL_stdinc.h"

namespace ECS {
class SpriteComponent
{
  public:
    SpriteComponent(Uint64 id);
    ~SpriteComponent(){};

    Uint64 id;
};
}

#endif