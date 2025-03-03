#ifndef _GAME_H
#define _GAME_H

#include "registry.h"
#include "time.h"
#include <SDL3/SDL.h>
#include <cstddef>
#include <memory>
#include <string>

namespace Engine {
class Game
{
  public:
    inline static Game *getInstance()
    {
        if (m_instance == nullptr)
            m_instance = new Game();
        return m_instance;
    }

    ~Game(){};

    ECS::Registry *getRegistry() const;
    Time *getTime() const;

    bool isRunning() const;

    void init();

    void readInput();
    void render();
    void update(SDL_Time deltaTime);
    void clean();

  private:
    Game();

    static Game *m_instance;

    std::unique_ptr<Time> m_time;

    std::string m_windowName;
    std::size_t m_windowWidth;
    std::size_t m_windowHeight;

    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

    std::unique_ptr<ECS::Registry> m_registry;

    bool m_isRunning;
};
}

#endif