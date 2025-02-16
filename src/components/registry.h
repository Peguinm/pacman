#ifndef _REGISTRY_H
#define _REGISTRY_H

#include "SDL3/SDL_stdinc.h"
#include <algorithm>
#include <memory>
#include <unordered_map>

namespace ecs {
class Registry
{
  private:
    Uint64 m_entities = 0;
};
}

#endif