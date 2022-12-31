#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Include/Grid.h"

const int32_t windowWidth = 80; // Cols
const int32_t windowHeight = 50; // Rows

int main() {

    //For testing purposes, when the program is run, the grid should pop up,
    //and I should be able to place black squares on a white box grid for today
    Grid gameOfLife(windowWidth, windowHeight);
    gameOfLife.run();
    return 0;
}
