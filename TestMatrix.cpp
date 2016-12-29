// fertoud 316295005 amitayi 203839030

#include <iostream>
#include "gtest/gtest.h"
#include "Point.h"
#include "Grid.h"
#include "Matrix.h"

using namespace std;

class TestMatrix : public::testing::Test {
protected:
    Point p;
    int i;
    int j;
    int height;
    int width;
    Node node;
    Matrix mat;

    virtual void SetUp() {
        cout << "Setting Up" << endl;
        i = 1;
        j = 2;
    }

    virtual void TearDown() {
        cout << "Tear Down" << endl;
    }

public:
    TestMatrix() : width(3), height(3), p(2, 1),  node(p), mat(width,height) {}
};

/**
 * testing that location in grid returning the right node in the matrix
 */
TEST_F(TestMatrix, testLocationInGrid) {
    mat.create();
    EXPECT_EQ((mat.locationInGrid(p)->getPoint()), node.getPoint());
    EXPECT_EQ((mat.locationInGrid(p)->getDistance()), node.getDistance());
    EXPECT_EQ((mat.locationInGrid(p))->isIsVisited(), node.isIsVisited());
}

/**
 * testing that ConvertIndexToMatrix convertting indexes of 2d array to the right point of the grid
 */
TEST_F(TestMatrix, testConvertIndexToMatrix) {
    EXPECT_EQ(mat.convertIndexToPointInMatrix(i, j), p);
}

/**
 * testing that the height bigger than 1 and not negative
 */
TEST_F(TestMatrix, testHeightInput) {
    ASSERT_GE(mat.getHeight(),1);
}

/**
 * testing that the width bigger than 1 and not negative
 */
TEST_F(TestMatrix, testWidthInput) {
    ASSERT_GE(mat.getWidth(), 1);
}