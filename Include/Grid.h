//
// Created by Josh Hizgiaev on 12/29/22.
//

#ifndef CELLULARAUTOMATA2D_GRID_H
#define CELLULARAUTOMATA2D_GRID_H

#include <iostream>
#include <vector>
#include <cstdio>
#include "Cell.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Grid {

private:
    std::vector<std::vector<Cell>> gridVector;
    int32_t height;
    int32_t width;
    bool isRunning;

public:

    int countNeighbors(int x, int y);

    void initGridVector();

    void setWidth(int width);
    void setHeight(int height);

    static void placeCell(int x, int y, std::vector<std::vector<Cell>>& gridVec);
    static void deleteCell(int x, int y, std::vector<std::vector<Cell>>& gridVec);

    std::vector<std::vector<Cell>> gridCopy(const std::vector<std::vector<Cell>>& gridVec);
    void update();

    void run();

    void display(int gWidth, int gHeight);

    Grid();

    Grid(int gridWidth, int gridHeight);

};


#endif //CELLULARAUTOMATA2D_GRID_H
