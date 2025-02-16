#include "SDL3/SDL.h"
#include "SDL3/SDL_init.h"
#include "game/game.h"
#include <cstdlib>
#include <iostream>

// TODO usar o cscope

int
main(int argc, char **argv)
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "ERROR::SDL::FAILED_TO_INIT_VIDEO_SUBMODULE";
        return EXIT_FAILURE;
    }

    const std::size_t window_width = 400;
    const std::size_t window_height = 400;

    pm::Game game(window_width, window_height);

    game.run();

    return 0;
}