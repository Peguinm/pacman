#include "main.h"

int
main(int argc, char **argv)
{
    Engine::Game *game = Engine::Game::getInstance();
    game->init();

    ECS::Registry *registry = game->getRegistry();
    if (registry == nullptr) {
        std::cout << "ERROR::GAME::REGISTRY_NOT_INITIALIZED" << std::endl;
        return EXIT_FAILURE;
    }

    Time *time = game->getTime();
    if (time == nullptr) {
        std::cout << "ERROR::GAME::TIME_NOT_INITIALIZED" << std::endl;
        return EXIT_FAILURE;
    }

    Entity *random = registry->createEntity<Entity>();
    Entity *pacman = registry->createEntity<Pacman>();

    while (game->isRunning()) {
        time->calcDeltaTime();
        game->readInput();
        game->update(time->getDeltaTime());
        game->render();
        time->updateOldTime();
    }

    game->clean();

    return 0;
}