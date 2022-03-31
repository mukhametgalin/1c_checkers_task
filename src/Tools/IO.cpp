//
// Created by artur on 31.03.2022.
//

#include "IO.h"

namespace Game::tools::io {


bool IO::Register() {
    Print("HELLO!\n");
    Print("chose your side (w - white, b - black):\n");
    char c = RetryRead<char>("Wrong side!\n", [](char c) {
        return c == 'w' || c == 'b';
    });
    return c == 'w';
}

size_t IO::AskBoardSize() {
    Print("Enter board size (bigger than 8 and even):\n");
    int x = RetryRead<int>("Wrong Board size!\n", [](int x) {
        if (x <= 0 || x % 2 != 0 || x > 8)
            return false;
        return true;
    });

    return x;
}

Difficulty IO::AskGameDifficulty() {
    Print("Enter Game Difficulty (1 - easy, 2 - medium, 3 - hard):\n");
    int x = RetryRead<int>("Wrong Game Difficulty!\n", [](int x) {
        return x >= 1 && x <= 3;
    });

    switch (x) {
        case 1:
            return Difficulty::easy;
        case 2:
            return Difficulty::medium;
        case 3:
        default:
            return Difficulty::hard;
    }
}

Turn IO::AskTurn() {
    Print("Chose your turn!\n");

    auto checker = [](const std::string& s) {
        if (s.size() < 2)
            return false;
        char x = s[0];
        char y = s[1];
        x = tolower(x);

        bool fl = true;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] < '0' || s[i] > '9') {
                fl = false;
                break;
            }
        }
        return x >= 'a' && x <= 'z' && fl;
    };

    auto first_c = RetryRead<std::string>("Wrong first coordinates!\n", checker);
    int first_x = first_c[0] - 'a' + 1;
    first_c.erase(first_c.begin());
    int first_y = stoi(first_c);

    auto second_c = RetryRead<std::string>("Wrong second coordinates!\n", checker);
    int second_x = second_c[0] - 'a' + 1;
    second_c.erase(second_c.begin());
    int second_y = stoi(second_c);

    return Turn{nullptr, {first_x, first_y}, {second_x, second_y}};
}

void IO::Print(const std::string& message) {
    std::cout << message;
}

}
