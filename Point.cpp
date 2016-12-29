// fertoud 316295005 amitayi 203839030

#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

Point::Point() {}

Point::Point(int x, int y) : x(x), y(y) {}

int Point::getX() const {
    return x;
}

void Point::setX(int x2) {
    x = x2;
}

int Point::getY() const {
    return y;
}

void Point::setY(int y2) {
    y = y2;
}

double Point::distance(Point p) {
    return std::sqrt(pow(p.getX() - x, 2) + pow(p.getY() - y, 2));
}

bool Point::operator==(const Point &p) const {
    return x == p.x && y == p.y;
}

ostream &operator<<(ostream &os, const Point &point) {
    os << "(" << point.x << "," << point.y << ")\n";
    return os;
}

istream &operator>>(istream &input, Point &point) {
    cout << "(";
    input >> point.x;
    cout << ",";
    input >> point.y;
    cout << ")";
    return input;
}
