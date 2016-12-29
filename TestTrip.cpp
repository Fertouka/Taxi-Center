// fertoud 316295005 amitayi 203839030

#include <iostream>
#include <gtest/gtest.h>
#include "Point.h"
#include "Trip.h"

using namespace std;

class TestTrip : public::testing::Test {
protected:
    Point start;
    Point end;
    Point start2;
    Point end2;
    int rideNum;
    int metersPassed;
    int numOfPassengers;
    double tariff;
    Trip trip;
    Trip trip2;

    virtual void SetUp() {
        cout << "Setting Up" << endl;
        rideNum = 1;
        metersPassed = 2;
        numOfPassengers = 3;
        tariff = 2;
    }

    virtual void TearDown() {
        cout << "Tear Down" << endl;
    }

public:
    TestTrip() : start(2, 3), end(0, 1), start2(1,1), end2(2,2),
                 trip(1,2,start,end,3,2), trip2(3,5,start2,end2,3,15) {}
};

TEST_F(TestTrip, testGetRideNum) {
    EXPECT_EQ(rideNum, trip.getRideNum());
}

TEST_F(TestTrip, testGetMetersPassed) {
    EXPECT_EQ(metersPassed, trip.getMetersPassed());
}
TEST_F(TestTrip, testGetStart) {
    EXPECT_EQ(start, trip.getStart());
}
TEST_F(TestTrip, testGetEnd) {
    EXPECT_EQ(end, trip.getEnd());
}
TEST_F(TestTrip, testGetnumOfPassengers) {
    EXPECT_EQ(numOfPassengers, trip.getNumOfPassengers());
}
TEST_F(TestTrip, testGetTariff) {
    EXPECT_EQ(tariff, trip.getTariff());
}
TEST_F(TestTrip, testSetRideNum) {
    trip.setRideNum(trip2.getRideNum());
    EXPECT_EQ(trip2.getRideNum(),trip.getRideNum());
}

TEST_F(TestTrip, testSetMetersPassed) {
    trip.setMetersPassed(trip2.getMetersPassed());
    EXPECT_EQ(trip2.getMetersPassed(),trip.getMetersPassed());
}
TEST_F(TestTrip, testSetStart) {
    trip.setStart(trip2.getStart());
    EXPECT_EQ(trip2.getStart(), trip.getStart());
}
TEST_F(TestTrip, testSetEnd) {
    trip.setEnd(trip2.getEnd());
    EXPECT_EQ(trip2.getEnd(), trip.getEnd());
}

TEST_F(TestTrip, testSetNumOfPassengers) {
    trip.setNumOfPassengers(trip2.getNumOfPassengers());
    EXPECT_EQ(trip2.getNumOfPassengers(), trip.getNumOfPassengers());
}

TEST_F(TestTrip, testSetTariff) {
    trip.setTariff(trip2.getTariff());
    EXPECT_EQ(trip2.getTariff(),trip.getTariff());
}
TEST_F(TestTrip, testMetersPassedInput) {
    ASSERT_GE(trip.getMetersPassed(),0);
}
TEST_F(TestTrip,testRideNumInput) {
    ASSERT_GE(trip.getRideNum(),0);
}
TEST_F(TestTrip,testStartPointInput) {
    ASSERT_GE(trip.getStart().getX(),0);
    ASSERT_GE(trip.getStart().getY(),0);
}
TEST_F(TestTrip,testEndPointInput) {
    ASSERT_GE(trip.getEnd().getX(),0);
    ASSERT_GE(trip.getEnd().getY(),0);
}
TEST_F(TestTrip,testNumOfPassengers) {
    ASSERT_GE(trip.getNumOfPassengers(), 0);
    ASSERT_LE(trip.getNumOfPassengers(), 4);
}
TEST_F(TestTrip,testTariffInput) {
    ASSERT_GE(trip.getTariff(), 1);
}
TEST_F(TestTrip, testStartIsNotEnd) {
    ASSERT_FALSE(trip.getEnd() == trip.getStart());
}

TEST_F(TestTrip, testOperatorEq) {
    trip.setTariff(trip2.getTariff());
    trip.setNumOfPassengers(trip2.getNumOfPassengers());
    trip.setStart(trip2.getStart());
    trip.setEnd(trip2.getEnd());
    trip.setMetersPassed(trip2.getMetersPassed());
    trip.setRideNum(trip2.getRideNum());

    EXPECT_EQ((trip == trip2), true);
}

/*TEST_F(TestPoint, testOperatorPrint) {
    EXPECT_EQ(cout << p1, cout << "(" << p1.getX() << " ," << p1.getY() << ")");
}
*/