//
// Created by Josh Hizgiaev on 12/29/22.
//

#ifndef CELLULARAUTOMATA2D_CELL_H
#define CELLULARAUTOMATA2D_CELL_H

#include <iostream>
#include <vector>
#include <cstdio>

//Use enum to keep track of the state of each cell
//When grid is initialized, each cell will have a state of dead
//However when the user places the cells by clicking on the boxes,
//and clicks the "Run" button, then the program will start

class Cell {

    enum State {
        ALIVE,
        DEAD
    };

private:
    std::int32_t xCell;
    std::int32_t yCell;
    State cellState;

public:

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

    bool getState();

    void setPosition(int xPos, int yPos);

    Cell(int xPos, int yPos, Cell::State state);

};


#endif //CELLULARAUTOMATA2D_CELL_H
