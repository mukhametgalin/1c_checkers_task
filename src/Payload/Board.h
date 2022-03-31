//
// Created by artur on 31.03.2022.
//

#ifndef SHASHKI_1C_BOARD_H
#define SHASHKI_1C_BOARD_H

#include <iostream>
#include <utility>
#include <vector>
#include <optional>

using Coordinates = std::pair<int, int>;

enum FigureType {
    base,
    godmode
};

enum FigureColor {
    white,
    black
};

namespace Game::game_payload::board {

class Figure {
public:
    Figure(Coordinates coords, FigureType type, FigureColor color): coordinates_(coords), type_(type), color_(color) {}
    Coordinates get_coordinates() const;

    bool change_coordinates(Coordinates);

    FigureType& get_type();
    FigureColor& get_color();
    bool operator==(const Figure& other) {
        return coordinates_.first != other.coordinates_.first || coordinates_.second != other.coordinates_.second;
    }
private:
    Coordinates coordinates_;
    FigureType type_ = FigureType::base;
    FigureColor color_ = FigureColor::white;
};

using FiguresHolder = std::vector<Figure>;

class Board {
public:
    bool set_size(size_t);
    FiguresHolder &get_figures();
    std::optional<Figure> get_figure_by_coordinates(Coordinates);
    bool validateCoordinate(Coordinates) const;
    void addFigure(Coordinates, FigureType, FigureColor);
    void deleteFigure(Figure);
private:
    FiguresHolder figures_;
    size_t board_size_;
};

}


#endif //SHASHKI_1C_BOARD_H
