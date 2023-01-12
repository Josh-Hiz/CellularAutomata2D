//
// Created by Josh Hizgiaev on 12/29/22.
//

#ifndef CELLULARAUTOMATA2D_CELL_H
#define CELLULARAUTOMATA2D_CELL_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//Use enum to keep track of the state of each cell
//When grid is initialized, each cell will have a state of dead
//However when the user places the cells by clicking on the boxes,
//and clicks the "Run" button, then the program will start

class Cell {

public:

private:
    std::int32_t xCell;
    std::int32_t yCell;
    int cellState;

public:
    constexpr static float cellSize = 10;

    sf::RectangleShape cell;

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

    int getState() const;

    void setState(int state);

    void setPosition(int xPos, int yPos);

    Cell(int xPos, int yPos, int state);

};


#endif //CELLULARAUTOMATA2D_CELL_H
