//
// Created by artur on 31.03.2022.
//

#ifndef SHASHKI_1C_GAME_H
#define SHASHKI_1C_GAME_H

#include <iostream>
#include <vector>
#include <memory>
#include <optional>

#include "Payload/Board.h"
#include "Tools/IO.h"
#include "Payload/Turn.h"
#include "GameBot/GameBot.h"

namespace Game {

namespace game_payload {

class GamePayload {
public:
    board::Board& GetBoard();
    bool SetBoardSize(size_t);

private:
    board::Board board_;
};

}

class Game {
public:
    Game() {}

    void Run();

private:
    void initializeGame();
    bool is_running_ = false;
    game_payload::GamePayload game_payload_;
    GameBot game_bot_;
};

} // namespace Game


#endif //SHASHKI_1C_GAME_H
