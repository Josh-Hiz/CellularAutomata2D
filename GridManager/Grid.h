//
// Created by Josh Hizgiaev on 9/19/22.
//
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef CELLULARAUTOMATA2D_GRID_H
#define CELLULARAUTOMATA2D_GRID_H


class Grid {

private:

    int32_t rows{};
    int32_t columns{};
    int32_t nodeSize{};

public:

    //Getters & setters for default constructor
    [[nodiscard]] int32_t getRows() const;
    [[nodiscard]] int32_t getCols() const;
    [[nodiscard]] int32_t getNodeSize() const;

    void setRows(const int32_t & rows);
    void setCols(const int32_t & cols);
    void setNodeSize(const int32_t & nodeDimension);

    void initGrid();

    //Constructors:
    Grid(); //Default
    Grid(int32_t row, int32_t cols, int32_t size) : rows(row), columns(cols), nodeSize(size){};

    //Deconstructor
    ~Grid();
};


#endif //CELLULARAUTOMATA2D_GRID_H
