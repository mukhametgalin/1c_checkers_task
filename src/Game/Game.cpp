//
// Created by artur on 31.03.2022.
//

#include "Game/Game.h"
#include "Tools/Tools.h"

namespace Game {

void Game::Run() {
    initializeGame();

    if (game_bot_.is_first()) {
        if (!game_bot_.make_turn(game_payload_.GetBoard())) {
            tools::io::IO::Print("You Won!\n");
            tools::FinishGame(*this);
        }
    }
    while (tools::ValidateGame(*this)) {
        while (!game_bot_.recieve_turn(game_payload_.GetBoard(), tools::io::IO::AskTurn())) {
            tools::io::IO::Print("bad turn! retry\n");
        }
        if (!game_bot_.make_turn(game_payload_.GetBoard())) {
            tools::io::IO::Print("You Won!\n");
            tools::FinishGame(*this);
        }
    }
    tools::io::IO::Print("You Lost, sorry \n");
    tools::FinishGame(*this);
}

    void Game::initializeGame() {
        is_running_ = true;
        game_bot_.setSide(tools::io::IO::Register());
        game_payload_.SetBoardSize(tools::io::IO::AskBoardSize());
        game_bot_.set_difficulty(tools::io::IO::AskGameDifficulty());
    }

    game_payload::board::Board &game_payload::GamePayload::GetBoard() {
        return board_;
    }

    bool game_payload::GamePayload::SetBoardSize(size_t board_size) {
        return board_.set_size(board_size);
    }
} // namespace Game