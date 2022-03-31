//
// Created by artur on 31.03.2022.
//

#include "Board.h"

const size_t kRowsNumber = 3;

Coordinates Game::game_payload::board::Figure::get_coordinates() const {
    return Coordinates();
}

bool Game::game_payload::board::Figure::change_coordinates(Coordinates coords) {
    coordinates_ = coords;
    return true;
}

FigureType &Game::game_payload::board::Figure::get_type() {
    return type_;
}

FigureColor &Game::game_payload::board::Figure::get_color() {
    return color_;
}

Game::game_payload::board::FiguresHolder& Game::game_payload::board::Board::get_figures() {
    return figures_;
}

std::optional<Game::game_payload::board::Figure> Game::game_payload::board::Board::get_figure_by_coordinates(Coordinates coords) {
    for (auto& figure: figures_) {
        if (figure.get_coordinates() == coords) {
            return figure;
        }
    }
    return std::nullopt;
}

bool Game::game_payload::board::Board::set_size(size_t size) {
    board_size_ = size;
    for (int i = 1; i <= kRowsNumber; ++i) {
        for (int j = 1; j <= board_size_ / 2; j++) {
            addFigure(Coordinates(i, j * 2 - (i % 2)), FigureType::base, FigureColor::white);
        }
    }
    for (int i = board_size_ - kRowsNumber + 1; i <= board_size_; ++i) {
        for (int j = 1; j <= board_size_ / 2; j++) {
            addFigure(Coordinates(i, j * 2 - (i % 2)), FigureType::base, FigureColor::black);
        }
    }
    return true;
}

bool Game::game_payload::board::Board::validateCoordinate(Coordinates coords) const {
    return coords.first > 0 && coords.first <= board_size_ &&
        coords.second > 0 && coords.second <= board_size_;
}

void Game::game_payload::board::Board::addFigure(Coordinates coords, FigureType type, FigureColor color) {
    std::cout << coords.first << ' ' << coords.second << std::endl;
    figures_.push_back(Figure(coords, type, color));
}

void Game::game_payload::board::Board::deleteFigure(Game::game_payload::board::Figure figure) {
    for (FiguresHolder::iterator i = figures_.begin(); i != figures_.end(); ++i) {
        if (*i == figure) {
            figures_.erase(i);
            return;
        }
    }
}
