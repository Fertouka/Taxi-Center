

#include <iostream>
#include <list>
#include "Node.h"
#include "Grid.h"
using namespace std;

Grid::Grid() : width(0), height(0) {}

Grid::Grid(int width, int height) : width(width), height(height) {}

Grid::Grid(int width, int height, const list <Point> &obstacles) : width(width), height(height), obstacles(obstacles) {}

Grid::~Grid(){}

void Grid::create() {}

void Grid::restart() {}

Grid Grid::getGrid() {
    return *this;
}

Node * Grid::locationInGrid(Point p) {}

bool Grid::operator==(const Grid &rhs) const {
    return width == rhs.width &&
           height == rhs.height &&
           obstacles == rhs.obstacles;
}

bool Grid::operator!=(const Grid &rhs) const {
    return !(rhs == *this);
}

int Grid::getWidth() const {
    return width;
}

void Grid::setWidth(int width) {
    Grid::width = width;
}

int Grid::getHeight() const {
    return height;
}

void Grid::setHeight(int height) {
    Grid::height = height;
}

const list <Point> &Grid::getObstacles() const {
    return obstacles;
}

void Grid::setObstacles(const list <Point> &obstacles) {
    Grid::obstacles = obstacles;
}

