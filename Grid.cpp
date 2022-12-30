//
// Created by Josh Hizgiaev on 12/29/22.
//

#include "Include/Grid.h"
#include "Include/Cell.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Grid::Grid(int gridWidth, int gridHeight) {
    this->height = gridHeight;
    this->width = gridWidth;
    this->isRunning = false;
}

void Grid::initGridVector() {

        for (int i = 0; i < height; i++) {
            std::vector<Cell> cellVec;
            for (int j = 0; j < width; j++) {
                cellVec.push_back(*new Cell(i, j, Cell::DEAD));
            }
            gridVector.push_back(cellVec);
        }

        for(int x = 0; x < gridVector.size(); x++){
            for(int y = 0; y < gridVector[x].size(); y++){
                gridVector[x][y].cell.setPosition(x*gridVector[x][y].cell.getSize().x,y*gridVector[x][y].cell.getSize().y);
                gridVector[x][y].cell.setSize(sf::Vector2f(30,30));
                gridVector[x][y].cell.setOutlineThickness(1);
                gridVector[x][y].cell.setOutlineColor(sf::Color::Black);
            }
        }
    }

    void Grid::display(int gWidth, int gHeight) const {
        sf::RenderWindow window(sf::VideoMode(gWidth, gHeight), "Cellular Automata", sf::Style::Default);

        //Run the program as long as the window is open
        while (window.isOpen() && isRunning) {
            //Check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event)) {
                //"close requested" event: closes the window
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear(sf::Color::White);

            for (const auto &i: gridVector) {
                for (const auto &j: i) {
                    window.draw(j.cell);
                }
            }
            window.display();

        }
    }

    void Grid::setWidth(int gWidth) {
        this->width = gWidth;
    }

    void Grid::setHeight(int gHeight) {
        this->height = gHeight;
    }

    void Grid::gridCopy() {

    }

    void Grid::update() {

    }

    void Grid::deleteCell() {

    }

    void Grid::placeCell() {

    }

    void Grid::run() {
        std::cout << "Automata is running" << std::endl;
        isRunning = true;
        initGridVector();
        display(30 * width, 30 * height + 50);

    }

