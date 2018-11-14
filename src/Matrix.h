
#ifndef EX1_MATRIX_H
#define EX1_MATRIX_H

#include <iostream>
#include <list>
#include "Grid.h"
#include "Node.h"
class Matrix : public Grid {
private:
    Node **matrix;
public:

/**
 * matrix constructor
 * @param width of the matrix
 * @param height of the matrix
 */
    Matrix(int width, int height);

/**
 * matrix constructor
 * @param width of the matrix
 * @param height of the matrix
 * @param obstacles in matrix
 */
    Matrix(int width, int height, std::list<Point> &obstacles);

/**
 * destructor of matrix
 */
    ~Matrix();
/**
 * create a drid
 */
    void create();

    void restart();

/**
 * @return the grid
 */
    Grid getGrid();
/**
 * setting the grid
 */
    Grid setGrid();

/**
 * getting a point and returning the node of this point in the matrix
 * @param p point
 * @return the node of p point in the matrix
 */
    Node* locationInGrid(Point p);

/**
 * convertting index of 2d array to the point of the grid
 * @param x axws
 * @param y axes
 * @return point of the grid
 */
    Point convertIndexToPointInMatrix(int x, int y);

    Matrix();
};

#endif //EX1_MATRIX_H
