#include <iostream>

#include "Tools/Tools.h"

namespace Game::tools {

bool ValidateGame(const Game&) {
    return true;
}

void FinishGame(const Game&) {
    exit(0);
}

}