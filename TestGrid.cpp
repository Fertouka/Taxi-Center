// fertoud 316295005 amitayi 203839030

#include <iostream>
#include <cmath>
#include "gtest/gtest.h"
#include "Point.h"
#include "Grid.h"

using namespace std;

class TestGrid : public::testing::Test {
protected:
    Point p1;
    Point p2;
    int width1;
    int width2;
    int height1;
    int height2;
    list<Point> obstacles1;
    list<Point> obstacles2;
    Grid g1;
    Grid g2;

    virtual void SetUp() {
        cout << "Setting Up" << endl;
        /*p1 = Point(1,1);
        p2 = Point(2,2);
        width1 = 3;
        width2 = 2;
        height1 = 5;
        height2 = 4;
        obstacles1 = list<Point>(1,p1);
        obstacles2 = list<Point>(1,p2)*/

    }

    virtual void TearDown() {
        cout << "Tear Down" << endl;
    }

public:
    TestGrid() :  p1(1,1), p2(2,2), width1(3), width2(2), height1(5), height2(5), obstacles1(1, p1),
                  obstacles2(1,p2), g1(width1,height1,obstacles1), g2(width2,height2,obstacles2) {}
};



TEST_F(TestGrid, testGetWidth) {
    EXPECT_EQ(width1, g1.getWidth());
}

TEST_F(TestGrid, testGetHeight) {
    EXPECT_EQ(height1, g1.getHeight());

}

TEST_F(TestGrid, TestGetObstacles) {
    EXPECT_EQ(obstacles1,g1.getObstacles());
}
TEST_F(TestGrid, testSetHeight) {
    g1.setHeight(g2.getHeight());
    EXPECT_EQ(g2.getHeight(), g1.getHeight());
}

TEST_F(TestGrid, testGSetWidth) {
   g1.setWidth(g2.getWidth());
    EXPECT_EQ(g2.getWidth(), g1.getWidth());
}

TEST_F(TestGrid, testSetObstacles) {
    g1.setObstacles(g2.getObstacles());
    EXPECT_EQ(g2.getObstacles(), g1.getObstacles());
}

TEST_F(TestGrid, testOperatorEq) {
    g1.setObstacles(g2.getObstacles());
    g1.setWidth(g2.getWidth());
    g1.setHeight(g2.getHeight());
    EXPECT_EQ((g1 == g2), true);
}
TEST_F(TestGrid, testGetGrid) {
    g1.setObstacles(g2.getObstacles());
    g1.setWidth(g2.getWidth());
    g1.setHeight(g2.getHeight());
    EXPECT_EQ(g1.getGrid(), g2);
}

TEST_F(TestGrid, testHeightCheck) {
    ASSERT_GE(g1.getHeight(),1);
}
TEST_F(TestGrid, testWidthCheck) {
    ASSERT_GE(g1.getWidth(),1);
}
