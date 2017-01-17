// fertoud 316295005 amitayi 203839030

#ifndef EX1_GRID_H
#define EX1_GRID_H

#include "Node.h"
#include "Point.h"
class Grid {
protected:
    int width;
    int height;
    std::list<Point> obstacles;
public:

/**
 * constructor of grid
 * @param width of the grid
 * @param height of the grid
 */
    Grid(int width, int height);

/**
 * default constructor of grid
 */
    Grid();

/**
 * constructor of grid
 * @param width of the grid
 * @param height of the grid
 * @param obstacles in the grid
 */
    Grid(int width, int height, const list <Point> &obstacles);

/**
 * destructor of grid
 */
    virtual ~Grid();

/**
 * creating the stucture of the grid
 */
    virtual void create();
/**
 * restart the nodes in the grid to be with 0 distance and without visiting
 */
    virtual void restart();

/**
 * getting the grid
 * @return grid
 */
    virtual Grid getGrid();

/**
 * getting a point and returning the node of this point in the grid
 * @param p point
 * @return the node of p point in the grid
 */
    virtual Node * locationInGrid(Point p);

/**
 * @param rhs a grid
 * @return if two grid are equals
 */
    bool operator==(const Grid &rhs) const;

/**
 * @param rhs a grid
 * @return if two grid are not equals
 */
    bool operator!=(const Grid &rhs) const;

/**
 * getting the width of the grid
 */
    int getWidth() const;

/**
 * setting the width of the grid
 */
    void setWidth(int width);

/**
 * getting the height of the grid
 */
    int getHeight() const;

/**
 * setting the height of the grid
 */
    void setHeight(int height);

/**
 * getting the obstacles of the grid
 */
    const list <Point> &getObstacles() const;

/**
 * setting the obstacles of the grid
 */
    void setObstacles(const list <Point> &obstacles);
};

#endif //EX1_GRID_H
