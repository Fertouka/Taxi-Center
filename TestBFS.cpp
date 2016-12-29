// fertoud 316295005 amitayi 203839030

#include <iostream>
#include <cmath>
#include <stack>
#include "gtest/gtest.h"
#include "Point.h"
#include "Grid.h"
#include "BFS.h"

using namespace std;

#include "Matrix.h"

class TestBFS : public::testing::Test {
protected:
    Node start;
    Node* end;
    Matrix grid;
    vector<Point> trail;

    virtual void SetUp() {
        cout << "Setting Up" << endl;
    }

    virtual void TearDown() {
        cout << "Tear Down" << endl;
    }

public:
    TestBFS() : start(Point(0,0),list<Node*>()), end(new Node(Point(2,0), list<Node*>())), grid(3,3){}
};

/**
 * checking if the bfs function return the right and short trail
 */
TEST_F(TestBFS, testPrintTrail) {
    trail = vector<Point>();
    trail.push_back(Point(2,0));
    trail.push_back(Point(1,0));
    trail.push_back(Point(0,0));
    vector<Point> trailFromBfs = vector<Point>();
    vector<Node*> bfsVector = BFS::bfs(grid, start.getPoint(), (*end).getPoint());
    while(!bfsVector.empty()) {
        trailFromBfs.push_back((*bfsVector.back()).getPoint());
        bfsVector.pop_back();
    }
    EXPECT_EQ(trail, trailFromBfs);
}
