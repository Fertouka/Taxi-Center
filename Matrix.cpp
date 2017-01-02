// fertoud 316295005 amitayi 203839030

#include "Matrix.h"

Matrix::Matrix(int width, int height) : Grid(width, height) {
    matrix = new Node*[width];
    for (int i = 0; i < width; ++i) {
        matrix[i] = new Node[height];
    }
}

Matrix::Matrix(int width, int height, std::list<Point> &obstacles)  : Grid(width, height, obstacles){
    matrix = new Node*[width];
    for (int i = 0; i < width; ++i) {
        matrix[i] = new Node[height];
    }
}

Matrix::~Matrix() {
    delete[](matrix);
}

Point Matrix::convertIndexToPointInMatrix(int x, int y) {
    return Point(y, width - 1 - x);
}

void Matrix::create() {
    //updating the node's point and his neighbours in the matrix
    for (int i = 0; i < width ; ++i) {
        for (int j = 0; j < height; ++j) {
            std::list<Node*> neighbours;
            if ((j - 1) >= 0) {
                neighbours.push_back(&matrix[i][j - 1]);
            }
            if ((i - 1) >= 0) {
                neighbours.push_back(&matrix[i - 1][j]);
            }
            if ((j + 1) < height) {
                neighbours.push_back(&matrix[i][j + 1]);
            }
            if ((i + 1) < width) {
                neighbours.push_back(&matrix[i + 1][j]);
            }
            matrix[i][j].setPoint(convertIndexToPointInMatrix(i, j));
            matrix[i][j].setNeighbours(neighbours);
        }
    }

    //updating the obstacles in the matrix
    if (!obstacles.empty()) {
        std::list<Point> copyOfObstacles (obstacles);
        for (int i = 0; i < copyOfObstacles.size(); ++i) {
            Point location = (*locationInGrid(copyOfObstacles.front())).getPoint();
            matrix[location.getX()][location.getY()].setDistance(-1);
            copyOfObstacles.pop_front();
        }
    }
}

void Matrix::restart() {
    for (int i = 0; i < width ; ++i) {
        for (int j = 0; j < height; ++j) {
            matrix[i][j].restart();
        }
    }
}

Grid Matrix::getGrid() {
    return *this;
}

Node* Matrix::locationInGrid(Point p) {
    return &matrix[width - 1 - p.getY()][p.getX()];
}

Matrix::Matrix() {

}




