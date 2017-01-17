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
    stack<Point> trail;
    trail.push(Point(2,0));
    trail.push(Point(1,0));
    trail.push(Point(0,0));
    stack<Point> trailFromBfs;
    stack<Node*> bfs = BFS::bfs(&grid, start.getPoint(), (*end).getPoint());
    while(!bfs.empty()) {
        trailFromBfs.push((*(bfs.top())).getPoint());
        bfs.pop();
    }
    EXPECT_EQ(trail, trailFromBfs);
}
