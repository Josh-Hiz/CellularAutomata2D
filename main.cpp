#include <iostream>
#include "GridManager/Grid.h"
#include "GridManager/Nodes.h"
#include <SFML/Graphics.hpp>

const int32_t windowWidth = 1440;
const int32_t windowHeight = 1080;

int main() {

    //Init Grid
    Grid grid;

    grid.setCols(30);
    grid.setRows(30);
    grid.setNodeSize(10);
    grid.initGrid();

    //Basic window setup

    sf::RenderWindow window(sf::VideoMode(windowWidth,windowHeight), "Cellular Automata");

    window.setFramerateLimit(60);

//    sf::CircleShape circle;
//
//    circle.setRadius(40.0f);
//    circle.setPosition((float) windowWidth/2 - circle.getRadius(), (float) windowHeight/2 - circle.getRadius());
//    circle.setFillColor(sf::Color::White);

    while(window.isOpen())
    {
        sf::Event event{};

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            window.clear();

            window.display();
        }
    }


    return 0;
}
