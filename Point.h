// fertoud 316295005 amitayi 203839030

#ifndef EX1_POINT_H
#define EX1_POINT_H

#include <ostream>

class Point {
private:
    int x;
    int y;

public:

/**
 * default constructor of point
 */
    Point();

/**
 * constructor of point
 * @param x x axes
 * @param y y axes
 */
    Point(int x, int y);

/**
 * @return the x axes
 */
    int getX() const;

/**
 * setting the x axes
 * @param x2 the new axes
 */
    void setX(int x2);

/**
 * @return the y axes
 */
    int getY() const;

/**
 * setting the y axes
 * @param y2 the new axes
 */
    void setY(int y2);

/**
 * @param p a point
 * @return the distance between the points
 */
    double distance(Point p);

/**
 * @param p a point
 * @return if the points are equals
 */
    bool operator==(const Point &p) const;

/**
 * @param os the system
 * @param point
 * @return a string of a point
 */
    friend std::ostream &operator<<(std::ostream &os, const Point &point);
/**
 * defining the >> operator for the user's inputs
 * @param input - the input
 * @param point - the point
 * @return - none
 */
    friend std::istream &operator>>(std::istream &input, Point &point);
};

#endif //EX1_POINT_H
