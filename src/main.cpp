#include "main.h"
#include "pacman.h"

int
main(int argc, char **argv)
{
    Engine::Game::getInstance()->init();

    ECS::Registry *registry = Engine::Game::getInstance()->getRegistry();
    if (registry == nullptr) {
        std::cout << "ERROR::GAME::REGISTRY_NOT_INITIALIZED" << std::endl;
        return EXIT_FAILURE;
    }

    Entity *random = registry->createEntity<Entity>();
    Entity *pacman = registry->createEntity<Pacman>();

    while (Engine::Game::getInstance()->isRunning()) {
        Engine::Game::getInstance()->readInput();
        Engine::Game::getInstance()->update();
        Engine::Game::getInstance()->render();
    }

    Engine::Game::getInstance()->clean();

    return 0;
}