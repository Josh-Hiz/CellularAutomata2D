//
// Created by Josh Hizgiaev on 9/19/22.
//

/**Purpose of this class:
 * Basically be the window manager, meaning create
 * the nodes (squares) and each square has data in it,
 * similar to the grid manager in JPaint
 */

#include <iostream>
#include <cmath>
#include "Grid.h"

//Getters & Setters:
int32_t Grid::getRows() const
{
    return rows;
}

int32_t Grid::getCols() const
{
    return columns;
}

int32_t Grid::getNodeSize() const
{
    return nodeSize;
}

void Grid::setRows(const int32_t & rowCount)
{
    rows = rowCount;
}

void Grid::setCols(const int32_t &cols)
{
    columns = cols;
}

void Grid::setNodeSize(const int32_t & nodeDimension)
{
    nodeSize = nodeDimension;
}

Grid::Grid() = default;

Grid::~Grid()
{
    printf("Automaton destroyed");
}

void Grid::initGrid()
{
    sf::RectangleShape grid[columns][rows];
    sf::Vector2f nodeDimensions(nodeSize, nodeSize);

    for(int32_t i = 0; i < columns; i++)
    {
        for(int32_t j = 0; j < rows; j++)
        {
            grid[i][j].setSize(nodeDimensions); //Will index out of bounds error if not initialized first
            grid[i][j].setFillColor(sf::Color::White);
            grid[i][j].setOutlineColor(sf::Color::Black);
            grid[i][j].setOutlineThickness(1.0f);

            grid[i][j].setPosition(i*nodeDimensions.x + 5.0f, j*nodeDimensions.y + 5.0f);


        }
    }

}




