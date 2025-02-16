#include "game.h"
#include "SDL3/SDL.h"
#include "registry.h"
#include <cstddef>
#include <iostream>
#include <memory>

pm::Game::Game(std::size_t windowWidth, std::size_t windowHeight)
  : m_isRunning(false)
  , m_windowWidth(windowWidth)
  , m_windowHeight(windowHeight)
  , m_windowName("paman")
{
    m_window = SDL_CreateWindow(m_windowName.c_str(), m_windowWidth, m_windowHeight, 0);
    if (m_window == nullptr) {
        std::cout << "ERROR::GAME::COULD_NOT_CREATE_WINDOW: " << SDL_GetError();
        m_isRunning = false;
        return;
    }

    m_renderer = SDL_CreateRenderer(m_window, 0);
    if (m_renderer == nullptr) {
        std::cout << "ERROR::GAME::COULD_NOT_CREATE_RENDERER: " << SDL_GetError();
        m_isRunning = false;
        return;
    }

    m_registry = std::unique_ptr<ecs::Registry>(new ecs::Registry);

    m_isRunning = true;
}

pm::Game::~Game()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
}

bool
pm::Game::isRunning()
{
    return m_isRunning;
}

void
pm::Game::run()
{
    while (m_isRunning) {
        readInput();
        update();
        render();
    }
}

void
pm::Game::readInput()
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
pm::Game::render()
{
}

void
pm::Game::update()
{
}