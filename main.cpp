#include <iostream>
#include "Game/Game.h"

int main() {
    auto game = new Game::Game();
    game->Run();

    delete game;
    return 0;
}
