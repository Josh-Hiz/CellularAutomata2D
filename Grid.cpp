//
// Created by Josh Hizgiaev on 12/29/22.
//

#include "Include/Grid.h"
#include "Include/Cell.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

constexpr int window_delay = 100;

//Regular constructor used for testing purposes
Grid::Grid(int gridWidth, int gridHeight) {
    this->height = gridHeight;
    this->width = gridWidth;
    this->isRunning = false;
}

//Default constructor
Grid::Grid() {
    this->height = 800;
    this->width = 600;
    this->isRunning= false;
}

void Grid::initGridVector() {

        for (int i = 0; i < width; i++) {
            std::vector<Cell> cellVec;
            for (int j = 0; j < height; j++) {
                cellVec.push_back(*new Cell(i, j, 0));
            }
            gridVector.push_back(cellVec);
        }

        //Not the most efficient but I just want to demonstrate the use of the Cell class, however this can be done in a single nested loop
        for(int x = 0; x < width; x++){
            for(int y = 0; y < height; y++){
                gridVector[x][y].cell.setPosition(float(x)*gridVector[x][y].cell.getSize().x,float(y)*gridVector[x][y].cell.getSize().y);
                gridVector[x][y].cell.setSize(sf::Vector2f(30,30));
                gridVector[x][y].cell.setOutlineThickness(1);
                gridVector[x][y].cell.setOutlineColor(sf::Color::White);
                gridVector[x][y].cell.setFillColor(sf::Color::Black);
            }
        }
    }

    void Grid::display(int gWidth, int gHeight) {
        sf::RenderWindow window(sf::VideoMode(gWidth, gHeight), "Cellular Automata", sf::Style::Default);

        //Run the program as long as the window is open
        while (window.isOpen()) {
            //Check all the window's events that were triggered since the last iteration of the loop
            sf::Event event{};
            while (window.pollEvent(event)) {
                //"close requested" event: closes the window
                switch(event.type)
                {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        if (event.key.code == sf::Keyboard::E)
                        {
                            std::cout << "E is pressed! Begin Automata!" << std::endl;
                            isRunning = true;
                        }
                        if (event.key.code == sf::Keyboard::P)
                        {
                            std::cout << "P is pressed! Automata has stopped/paused!" << std::endl;
                            isRunning = false;
                        }

                        break;
                    case sf::Event::MouseButtonPressed:
                        if(!isRunning)
                        {
                            if (event.mouseButton.button == sf::Mouse::Left)
                            {
                                placeCell(int(event.mouseButton.x)/int(Cell::cellSize),int(event.mouseButton.y)/int(Cell::cellSize));
                                std::cout << "Number of alive neighbors: " << countNeighbors(int(event.mouseButton.x)/int(Cell::cellSize),int(event.mouseButton.y)/int(Cell::cellSize)) << std::endl;
//                                std::cout<< "Current cell state: " << gridVector[int(event.mouseButton.x)/int(Cell::cellSize)][int(event.mouseButton.y)/int(Cell::cellSize)].getState() << std::endl;
                            }
                            if (event.mouseButton.button == sf::Mouse::Right)
                            {
                                deleteCell(int(event.mouseButton.x)/int(Cell::cellSize),int(event.mouseButton.y)/int(Cell::cellSize));
                                std::cout << "Number of alive neighbors: " << countNeighbors(int(event.mouseButton.x)/int(Cell::cellSize),int(event.mouseButton.y)/int(Cell::cellSize)) << std::endl;
//                                std::cout<< "Current cell state: " << gridVector[int(event.mouseButton.x)/int(Cell::cellSize)][int(event.mouseButton.y)/int(Cell::cellSize)].getState() << std::endl;

                            }
                        }
                        break;
                }
            }

            window.clear(sf::Color::White);

            for (const auto &i: gridVector) {
                for (const auto &j: i) {
                    window.draw(j.cell);
                }
            }

            if(isRunning){
                update();
            }

            window.display();
            sf::sleep(sf::milliseconds(window_delay));
        }
    }

    int Grid::countNeighbors(int x, int y) {
        if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
            return 0;
        } else {
            int16_t count = 0;
            for (int i = y - 1; i <= y + 1; i++) {
                for (int j = x - 1; j <= x + 1; j++) {
//                    std::cout << gridVector[j][i].getState() << std::endl;
                    if(!(j == x and i == y)){
//                        std::cout << gridVector[i][j].getState() << ",";
                        if (gridVector[j][i].getState() == 1) {
                            count++;
                        }
                    }
                }
            }
            return count;
        }
    }

    void Grid::setWidth(int gWidth) {
        this->width = gWidth;
    }

    void Grid::setHeight(int gHeight) {
        this->height = gHeight;
    }

    void Grid::update() {
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                if((countNeighbors(i,j) < 2  || countNeighbors(i,j) > 3) && gridVector[i][j].getState() == 1) {
                    deleteCell(i,j);
                } else if(countNeighbors(i,j) == 3){
                    placeCell(i,j);
                }
            }
        }

    }

    void Grid::deleteCell(int x, int y) {
        std::cout << "X: " << x << " Y: " << y << std::endl;
        gridVector[x][y].setState(0);
        gridVector[x][y].cell.setFillColor(sf::Color::Black);
    }

    void Grid::placeCell(int x, int y) {
        std::cout << "X: " << x << " Y: " << y << std::endl;
        gridVector[x][y].setState(1);
        gridVector[x][y].cell.setFillColor(sf::Color::White);
    }

    void Grid::run() {
        std::cout << "Automata is running" << std::endl;
        initGridVector();
        display(30 * width, 30 * height);

    }