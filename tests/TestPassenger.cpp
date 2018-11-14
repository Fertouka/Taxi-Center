

#include <iostream>
#include <cmath>
#include "gtest/gtest.h"
#include "Point.h"
#include "Passenger.h"
#include "TaxiCenter.h"

using namespace std;

class TestPassenger: public::testing::Test {
protected:
    Point start;
    Point end;
    int size;
    Listener* ls;
    Passenger passenger;

    virtual void SetUp() {
        cout << "Setting Up" << endl;
        size = 0;
    }

    virtual void TearDown() {
        cout << "Tear Down" << endl;
    }
//initializing the objects
public:
    TestPassenger() : start(1,1), end(1,3), /*listeners(list<Listener*>()),*/ls(NULL), passenger(start, end) {}
};
//testing if the start point isn't also the end point
TEST_F(TestPassenger, testStartNEend) {
    ASSERT_EQ((start == end), false);
}
//testing the satisfaction getter and if the value is between 1 to 5
TEST_F(TestPassenger, testGetSatisfaction) {
    EXPECT_GE(passenger.getSatisfaction(), 1);
    EXPECT_LE(passenger.getSatisfaction(), 5);
}
//testing the listener adder function
TEST_F(TestPassenger, testAddListener) {
    passenger.addListener(ls);
    //we change the size of the listeners counter (we added one now)
    size++;
    EXPECT_TRUE(size == 1);
}
//testing the listener remover function
TEST_F(TestPassenger, testRemoveListener) {
    passenger.removeListener(ls);
    //we change the size of the listeners counter (we removed one now)
    size--;
    EXPECT_TRUE(size == -1);
}
