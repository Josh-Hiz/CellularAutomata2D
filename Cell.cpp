//
// Created by Josh Hizgiaev on 12/29/22.
//

#include "Include/Cell.h"

Cell::Cell(int xPos, int yPos, Cell::State state) {
    this->xCell = xPos;
    this->yCell = yPos;
    this->cellState = state;}

int Cell::getX() const {
    return xCell;
}

int Cell::getY() const {
    return yCell;
}

bool Cell::getState() {
    return cellState;
}

void Cell::setPosition(int xPos, int yPos) {
    xCell = xPos;
    yCell = yPos;
}
