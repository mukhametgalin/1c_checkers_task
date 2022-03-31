//
// Created by artur on 31.03.2022.
//

#ifndef SHASHKI_1C_IO_H
#define SHASHKI_1C_IO_H

#include <iostream>
#include "Payload/Turn.h"
#include "GameBot/GameBot.h"
#include <functional>

namespace Game::tools::io {

class IO {
public:

    template <typename T>
    static T RetryRead(const std::string& message, std::function<bool(const T&)> func) {
        T a;
        std::cin >> a;
        while (!func(a)) {
            Print(message);
            std::cin >> a;
        }
        return a;
    }

    static bool Register();

    static size_t AskBoardSize();

    static Difficulty AskGameDifficulty();

    static Turn AskTurn();

    static void Print(const std::string &);

};
}



#endif //SHASHKI_1C_IO_H
