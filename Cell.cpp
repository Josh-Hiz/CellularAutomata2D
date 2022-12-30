//
// Created by Josh Hizgiaev on 12/29/22.
//

#include "Include/Cell.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Cell::Cell(int xPos, int yPos, Cell::State state) {
    this->xCell = xPos;
    this->yCell = yPos;
    this->cellState = state;
    cell.setSize(sf::Vector2f(30,30));
}

int Cell::getX() const {
    return xCell;
}

int Cell::getY() const {
    return yCell;
}

Cell::State Cell::getState() {
    return cellState;
}

void Cell::setPosition(int xPos, int yPos) {
    xCell = xPos;
    yCell = yPos;
}
