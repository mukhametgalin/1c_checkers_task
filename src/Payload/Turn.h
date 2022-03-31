//
// Created by artur on 31.03.2022.
//

#ifndef SHASHKI_1C_TURN_H
#define SHASHKI_1C_TURN_H

#include <iostream>
#include <memory>
#include <utility>

#include "Board.h"

namespace Game {

using Coordinates = std::pair<int, int>;
using TurnInfo = std::string;
class Turn {
public:
    Turn(std::shared_ptr<game_payload::board::Figure> figure,
            Coordinates first, Coordinates second) : figure_(std::move(figure)), source_coordinates_(std::move(first)),
                                                        changed_coordinates_(std::move(second)) {}
    TurnInfo GetInfo() const;
    Coordinates get_source_coordinates() const {
        return source_coordinates_;
    }
    Coordinates get_changed_coordinates() const {
        return changed_coordinates_;
    }
private:
    std::shared_ptr<game_payload::board::Figure> figure_;
    Coordinates source_coordinates_;
    Coordinates changed_coordinates_;
};

}


#endif //SHASHKI_1C_TURN_H
