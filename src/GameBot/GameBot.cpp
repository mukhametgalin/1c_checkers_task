//
// Created by artur on 31.03.2022.
//

#include "GameBot.h"
#include "Tools/IO.h"

bool Game::GameBot::recieve_turn(Game::game_payload::board::Board& board, Game::Turn turn) {
    auto start = turn.get_source_coordinates();
    auto end = turn.get_changed_coordinates();
    auto figure = board.get_figure_by_coordinates(turn.get_source_coordinates());
    auto target = board.get_figure_by_coordinates(turn.get_changed_coordinates());

    if (!figure || target)
        return false;



    if (abs(end.first - start.first) != abs(end.second - start.first))
        return false;

    if (figure->get_type() == FigureType::base) {
        if (abs(end.first - start.first) != 1 || abs(end.second - start.second) != 1) {
            return false;
        }

        if (figure->get_color() == FigureColor::white) {
            if (end.second - start.second < 0)
                return false;
        } else {
            if (end.second - start.second > 0)
                return false;
        }
    }

    int x_it = 1;
    if (end.first - start.first < 0) x_it = -1;
    int y_it = 1;
    if (end.second - start.second < 0) y_it = -1;
    int cnt = 0;

    for (int x = start.first + x_it, y = start.second + y_it;
            x != end.first && y != end.second; x += x_it, y += y_it) {
        auto t = board.get_figure_by_coordinates({x, y});
        if (t) {
            cnt++;
            ::Game::tools::io::IO::Print("deleted figure!\n");
            board.deleteFigure(t.value());
        }
    }
    if (difficulty_ != Difficulty::easy) {
        if (!cnt) {
            for (auto fig: board.get_figures()) {
                auto fig_coords = fig.get_coordinates();
                if (fig_coords.first == start.first && fig_coords.second == start.second)
                    continue;

                if (figure->get_color() == FigureColor::white) {
                    if (fig_coords.second - start.second < 0)
                        continue;
                } else {
                    if (fig_coords.second - start.second > 0)
                        continue;
                }

                if (abs(fig_coords.first - start.first) != abs(fig_coords.second - start.second))
                    continue;

                auto target = fig_coords;
                if (fig_coords.first < start.first) {
                    target.first -= 1;
                } else {
                    target.first += 1;
                }
                if (fig_coords.second < start.second) {
                    target.second -= 1;
                } else {
                    target.second += 1;
                }

                if (board.get_figure_by_coordinates(target)) {
                    continue;
                }
                if (board.validateCoordinate(target)) {
                    return false;
                }
            }
        }
    }

    figure->change_coordinates(turn.get_changed_coordinates());

    return true;

}

std::optional<Game::Turn> Game::GameBot::make_turn(Game::game_payload::board::Board &) {

    return std::nullopt;
}

bool Game::GameBot::set_difficulty(Game::Difficulty difficulty) {
    difficulty_ = difficulty;
    return true;
}

bool Game::GameBot::setSide(bool white_side) {
    first_step_ = true;
    if (white_side)
        first_step_ = false;
}

bool Game::GameBot::is_first() const {
    return first_step_;
}
