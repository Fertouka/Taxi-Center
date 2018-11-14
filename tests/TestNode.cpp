

#include <iostream>
#include <cmath>
#include "gtest/gtest.h"
#include "Point.h"
#include "Node.h"

using namespace std;

class TestNode : public::testing::Test {
protected:
    Point p1;
    Point p2;
    list<Node*> neighbours1;
    list<Node*> neighbours2;
    list<Node*> neighbours3;
    Node node1;
    Node node2;
    Node node3;
    Node node4;
    Node node5;
    Node node6;
    Node node7;
    Node node8;
//setting the values
    virtual void SetUp() {
        cout << "Setting Up" << endl;
        node6 = Node(Point(8,1),list<Node*>());
        node7 = Node(Point(3,1),list<Node*>());
        node4 = Node(Point(1,4),list<Node*>());
        node5 = Node(Point(2,2),list<Node*>(1,&node6));
        node8 = Node(Point(2,0),list<Node*>(1,&node7));
        neighbours2 = list<Node*>(1,&node5);
        neighbours1 = list<Node*>(1,&node8);
        neighbours3 = list<Node*>(1,&node4);
    }

    virtual void TearDown() {
        cout << "Tear Down" << endl;
    }
//initializin the objects
public:
    TestNode() : p1(2, 3), p2(0, 1),/*neighbours3(1,&node4),*/ node3(Point(5,5),neighbours3),
                neighbours1(1,&node8),
                 neighbours2(1,&node5),node2(p2,neighbours2),node1(p1,neighbours1) {}
};
//testing the point getter
TEST_F(TestNode, testGetPoint) {
    EXPECT_EQ(p1, node1.getPoint());
}
//testing the neighbours getter
TEST_F(TestNode, testGetNeighbours) {
    EXPECT_EQ(neighbours1, node1.getNeighbours());
}
//testin the distance getter
TEST_F(TestNode,testGetDistance) {
    EXPECT_EQ(0,node1.getDistance());
}
//testing the isVisited getter
TEST_F(TestNode, testIsIsVisited) {
    EXPECT_EQ(node1.isIsVisited(), false);
}
//testing the point setter
TEST_F(TestNode, testSetPoint) {
    //setting the new point
    node1.setPoint(node2.getPoint());
    EXPECT_EQ(node2.getPoint(), node1.getPoint());
}
//testing the distance setter
TEST_F(TestNode, testSetDistance) {
    //setting the new distance
    node1.setDistance(4);
    EXPECT_EQ(4,node1.getDistance());
}
//test the isVisited setter
TEST_F(TestNode, testSetIsVisited) {
    //setting the new value
       node1.setIsVisited(true);
    EXPECT_EQ(node1.isIsVisited(), true);
}
//testing the neighbours setter
TEST_F(TestNode, testSetNeighbours) {
    //setting the new neighbours list
    node1.setNeighbours(node2.getNeighbours());
    EXPECT_EQ(node2.getNeighbours(),node1.getNeighbours());
}
//testing the input of the distance value
TEST_F(TestNode, testDistanceInput) {
    //checking if the distance is at least -1
    ASSERT_GE(node1.getDistance(),-1);
}
//testing the == operator
TEST_F(TestNode, testOperatorEq) {
    //setting the nodes to be equal
    node1.setIsVisited(node2.isIsVisited());
    node1.setNeighbours(node2.getNeighbours());
    node1.setDistance(node2.getDistance());
    node1.setPoint(node2.getPoint());
//checking the operator
    EXPECT_EQ((node1 == node2), true);
}
//testing the father getter and setter
TEST_F(TestNode, testSetAndGetFather) {
    //setting node2 to be node1's father
    node1.setFather(&node2);
    //checking if they are equal
    EXPECT_EQ(node1.getFather()->getPoint(), node2.getPoint());
}
