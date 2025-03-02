#include "game.h"
#include "SDL3/SDL.h"
#include "SDL3/SDL_stdinc.h"
#include <cstddef>
#include <iostream>
#include <memory>
#include <utility>

const Uint32 WINDOW_WIDTH = 400;
const Uint32 WINDOW_HEIGHT = 400;

Engine::Game *Engine::Game::m_instance = nullptr;

Engine::Game::Game()
  : m_isRunning(false)
  , m_windowWidth(WINDOW_WIDTH)
  , m_windowHeight(WINDOW_HEIGHT)
  , m_windowName("pacman")
{
}

void
Engine::Game::init()
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "ERROR::SDL::FAILED_TO_INIT_VIDEO_SUBMODULE: " << SDL_GetError() << std::endl;
        return;
    }

    m_window = SDL_CreateWindow(m_windowName.c_str(), m_windowWidth, m_windowHeight, 0);
    if (m_window == nullptr) {
        std::cout << "ERROR::GAME::COULD_NOT_CREATE_WINDOW: " << SDL_GetError() << std::endl;
        m_isRunning = false;
        return;
    }

    m_renderer = SDL_CreateRenderer(m_window, 0);
    if (m_renderer == nullptr) {
        std::cout << "ERROR::GAME::COULD_NOT_CREATE_RENDERER: " << SDL_GetError() << std::endl;
        m_isRunning = false;
        return;
    }

    m_registry = std::make_unique<ECS::Registry>();

    m_isRunning = true;
}

bool
Engine::Game::isRunning()
{
    return m_isRunning;
}

void
Engine::Game::readInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                m_isRunning = false;
                break;
        }
    }
}

void
Engine::Game::render()
{
}

ECS::Registry *
Engine::Game::getRegistry()
{
    return m_registry.get();
}

void
Engine::Game::update()
{
    for (auto &e : getRegistry()->entityRegistry) {
        Entity *entity = e.second.get();

        std::cout << "ID: " + std::to_string(entity->id) << std::endl;
        entity->update();
    }
}

void
Engine::Game::clean()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();

    delete m_instance;
}