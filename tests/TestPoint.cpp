

#include <iostream>
#include <cmath>
#include <gtest/gtest.h>
#include "gtest/gtest.h"
#include "Point.h"
using namespace std;

class TestPoint : public::testing::Test {
protected:
    Point p1;
    Point p2;
    int x, y;

    virtual void SetUp() {
        //setting the x and y values
        cout << "Setting Up" << endl;
        x = 2;
        y = 3;
    }

    virtual void TearDown() {
        cout << "Tear Down" << endl;
    }
//initializing the objects
public:
    TestPoint() : p1(2, 3), p2(0, 1) {}
};
//testing the x value getter
TEST_F(TestPoint, testGetX) {
    EXPECT_EQ(x, p1.getX());
}
//testing the y value getter
TEST_F(TestPoint, testGetY) {
    EXPECT_EQ(y, p1.getY());
}
//testing the x value setter
TEST_F(TestPoint, testSetX) {
    p1.setX(p2.getX());
    EXPECT_EQ(p1.getX(), p2.getX());
}
//testing the y value setter
TEST_F(TestPoint, testGSetY) {
    p1.setY(p2.getY());
    EXPECT_EQ(p1.getY(), p2.getY());
}
//testing if the x value isn't negative
TEST_F(TestPoint, testXvaL) {
    ASSERT_GE(p1.getX(),0);
}
//testing if the y value isn't negative
TEST_F(TestPoint, testYvaL) {
    ASSERT_GE(p1.getY(),0);
}
//testing the distancew function
TEST_F(TestPoint, testDistance) {
    p1.setX(0);
    p1.setY(0);
    p2.setX(1);
    p2.setY(1);
    EXPECT_EQ(p1.distance(p2), sqrt(2));
}
//testing the == operator between two points
TEST_F(TestPoint, testOperatorEq) {
    p1.setX(p2.getX());
    p1.setY(p2.getY());
    EXPECT_EQ((p1 == p2), true);
}
//testing the print operator of point
TEST_F(TestPoint, testOperatorPrint) {
    EXPECT_EQ(cout << p1, cout << "(" << p1.getX() << " ," << p1.getY() << ")");
}
