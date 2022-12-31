//
// Created by Josh Hizgiaev on 12/29/22.
//

#include "Include/Cell.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Cell::Cell(int xPos, int yPos, int state) {
    this->xCell = xPos;
    this->yCell = yPos;
    this->cellState = state;
    cell.setSize(sf::Vector2f(cellSize,cellSize));
}

int Cell::getX() const {
    return xCell;
}

int Cell::getY() const {
    return yCell;
}

int Cell::getState() const {
    return cellState;
}

void Cell::setPosition(int xPos, int yPos) {
    xCell = xPos;
    yCell = yPos;
}

void Cell::setState(int state) {
    this->cellState = state;
}
