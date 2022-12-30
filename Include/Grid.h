//
// Created by Josh Hizgiaev on 12/29/22.
//

#ifndef CELLULARAUTOMATA2D_GRID_H
#define CELLULARAUTOMATA2D_GRID_H

#include <iostream>
#include <vector>
#include <cstdio>
#include "Include/Cell.h"

class Grid {

private:
    std::vector<Cell> gridVector;

public:
    void initGridVector();

    void setWidth(int width);
    void setHeight(int height);

    void placeCell();
    void deleteCell();

    void gridCopy();
    void update();

    Grid(int gridWidth, int gridHeight);

};


#endif //CELLULARAUTOMATA2D_GRID_H
