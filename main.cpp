#include <iostream>
#include "Include/Grid.h"

int main() {

    //For testing purposes, when the program is run, the grid should pop up,
    //and I should be able to place black squares on a white box grid for today
    int32_t windowWidth = 50; // Cols
    int32_t windowHeight = 50; // Rows
    bool randomize = false;
    std::cout << "Welcome to Conway's Game of Life! To begin, do you want to place your own cells or do you want to randomize every cell on the board? \n Please put 1 for yes, or 0 for no." << std::endl;
    std::cin >> randomize;
    std::cout << "Please input the height and width of the board (rows and columns) respectively:" << std::endl;
    std::cin >> windowHeight >> windowWidth;
    Grid gameOfLife(windowWidth, windowHeight, randomize);
    gameOfLife.run();
    return 0;
}
