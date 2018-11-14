
#include <iostream>
#include "gtest/gtest.h"
#include "Point.h"
#include "Grid.h"
#include "Driver.h"
#include "TaxiCenter.h"
#include "LuxuryCab.h"

using namespace std;

class TestTaxiCenter : public::testing::Test {
protected:
    list<Driver *> employees;
    list<Cab *> cabs;
    list<Trip *> trips;
    TaxiCenter center;

    virtual void SetUp() {
        cout << "Setting Up" << endl;
    }

    virtual void TearDown() {
        cout << "Tear Down" << endl;
    }

//initializing the objects
public:
    TestTaxiCenter() : employees(1,new Driver(30,40,'D',10,5)),
                       cabs(1,new LuxuryCab()), center(&employees, &cabs),
                       trips(1, new Trip(1, 2, Point(0, 0), Point(1, 2), 5, 2)) {}
};

//checking that driver get a car
TEST_F(TestTaxiCenter, testAssignCabToDriver) {
    center.assignCabsToDrivers();
    EXPECT_EQ(employees.front()->getCabId(), cabs.front()->getId());
}

//checking that driver get a trip
TEST_F(TestTaxiCenter, testAssignTripToDriver) {
    center.assignTripsToDrivers(trips);
    EXPECT_EQ(employees.front()->getCab()->getTrip()->getRideNum(), trips.front()->getRideNum());
}
