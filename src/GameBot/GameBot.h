//
// Created by artur on 31.03.2022.
//

#ifndef SHASHKI_1C_GAMEBOT_H
#define SHASHKI_1C_GAMEBOT_H

#include <optional>

#include "Payload/Turn.h"
#include "Payload/Board.h"

namespace Game {

enum class Difficulty {
    easy,
    medium,
    hard
};

class GameBot {
public:
    bool recieve_turn(game_payload::board::Board &, Turn);

    std::optional<Turn> make_turn(game_payload::board::Board &);

    bool set_difficulty(Difficulty);

    bool setSide(bool white_side);

    bool is_first() const;
private:
    Difficulty difficulty_;
    bool first_step_ = false;
};

}

#endif //SHASHKI_1C_GAMEBOT_H
