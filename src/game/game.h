#ifndef _GAME_H
#define _GAME_H

#include "registry.h"
#include <SDL3/SDL.h>
#include <cstddef>
#include <memory>
#include <string>

namespace Engine {
class Game
{
  public:
    Game(ECS::Registry &registry, std::size_t windowWidth, std::size_t windowHeight);
    ~Game();

    bool isRunning();
    void run();

  private:
    std::string m_windowName;
    std::size_t m_windowWidth;
    std::size_t m_windowHeight;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

    ECS::Registry &m_registry;

    bool m_isRunning;

    void readInput();
    void render();
    void update();
};
}

#endif