#include "SDL3/SDL.h"
#include "SDL3/SDL_stdinc.h"
#include "entity.h"
#include "game.h"
#include "registry.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>

// TODO usar o cscope

int
main(int argc, char **argv)
{
    Engine::Game::getInstance()->init();

    ECS::Registry *registry = Engine::Game::getInstance()->getRegistry();
    if (registry == nullptr) {
        std::cout << "ERROR::GAME::REGISTRY_NOT_INITIALIZED" << std::endl;
        return EXIT_FAILURE;
    }

    Entity *pacman = registry->createEntity();

    while (Engine::Game::getInstance()->isRunning()) {
        Engine::Game::getInstance()->readInput();
        Engine::Game::getInstance()->update();
        Engine::Game::getInstance()->render();
    }

    Engine::Game::getInstance()->clean();

    return 0;
}