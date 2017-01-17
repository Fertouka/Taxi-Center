// fertoud 316295005 amitayi 203839030

#include <iostream>
#include <gtest/gtest.h>
#include "Point.h"
#include "Trip.h"
#include "StandardCab.h"

using namespace std;

class TestStandardCab : public::testing::Test {
protected:
    int id;
    int kilometrage;
    char color;
    char color2;
    char manufacturer;
    char manufacturer2;
    double tariff;
    Point location;
    Point start;
    Point end;
    Point location2;
    Point start2;
    Point end2;
    Trip trip;
    Trip trip2;
    StandardCab cab;
    StandardCab cab2;

    virtual void SetUp() {
        cout << "Setting Up" << endl;
    }

    virtual void TearDown() {
        cout << "Tear Down" << endl;
    }

//initializing the objects
public:
    TestStandardCab() : id(3), kilometrage(2), color('G'), color2('W'), tariff(2),
                        manufacturer('T'), manufacturer2('S'),
                        location(2, 3), start(1, 1), end(2, 3), location2(5, 5) ,start2(8, 0) ,end2(2, 3),
                        trip2(5, 1, start2, end2, 3, 4), trip(1, 2, start, end, 5, 2),
                        cab(id, kilometrage, manufacturer, color, tariff, location, &trip),
                        cab2(33, 44, manufacturer2, color2, 7, location2, &trip2) {}
};
//checking the getid getter
TEST_F(TestStandardCab, testGetId) {
    EXPECT_EQ(id, cab.getId());
}
//testing the kilometrage getter
TEST_F(TestStandardCab, testGetKilometrage) {
    EXPECT_EQ(kilometrage, cab.getKilometrage());
}
//testing the manufacturer getter
TEST_F(TestStandardCab, testGetManufacturer) {
    EXPECT_EQ(manufacturer, cab.getManufacturer());
}
//testing the color getter
TEST_F(TestStandardCab, testGetColor) {
    EXPECT_EQ(color, cab.getColor());
}
//testing the tariff getter
TEST_F(TestStandardCab, testGettariff) {
    EXPECT_EQ(tariff, cab.getTariff());
}
//testing the trip getter
TEST_F(TestStandardCab, testGetTrip) {
    EXPECT_EQ(trip.getRideNum(),cab.getTrip()->getRideNum());
}
//testing the location getter
TEST_F(TestStandardCab, testGetLocation) {
    EXPECT_EQ(location, cab.getLocation());
}
//testing the id setter
TEST_F(TestStandardCab, testSetId) {
    cab.setId(cab2.getId());
    EXPECT_EQ(cab2.getId(),cab.getId());
}
//testing the kilometrage setter
TEST_F(TestStandardCab, testSetKilometrage) {
    cab.setKilometrage(cab2.getKilometrage());
    EXPECT_EQ(cab2.getKilometrage(),cab.getKilometrage());
}
//testing the manufacturer setter
TEST_F(TestStandardCab, testSetManufacturer) {
    cab.setManufacturer(cab2.getManufacturer());
    EXPECT_EQ(cab2.getManufacturer(), cab.getManufacturer());
}
//testing the color setter
TEST_F(TestStandardCab, testSetColor) {
    cab.setColor(cab2.getColor());
    EXPECT_EQ(cab2.getColor(),cab.getColor());
}
//testing the tariff setter
TEST_F(TestStandardCab, testSetTariff) {
   cab.setTariff(cab2.getTariff());
    EXPECT_EQ(cab2.getTariff(), cab.getTariff());
}
//testing the trip setter
TEST_F(TestStandardCab, testSetTrip) {
    cab.setTrip(cab2.getTrip());
    EXPECT_EQ(cab2.getTrip(),cab.getTrip());
}
//testing the loation setter
TEST_F(TestStandardCab, testSetLocation) {
    cab.setLocation(cab2.getLocation());
    EXPECT_EQ(cab2.getLocation(),cab.getLocation());
}
//testing if the input of the manufacturer is one of the legal values
TEST_F(TestStandardCab, testInputOfManufacturer) {
    switch (manufacturer) {
        case 'S':
            EXPECT_EQ(manufacturer, 'S');
            break;
        case 'F':
            EXPECT_EQ(manufacturer, 'F');
            break;
        case 'H':
            EXPECT_EQ(manufacturer, 'H');
            break;
        case 'T':
            EXPECT_EQ(manufacturer, 'T');
            break;
        default:
            ASSERT_ANY_THROW("the input isnt correct");
            break;
    }
}

//testing if the input of the color is one of the legal values
TEST_F(TestStandardCab, testInputOfColor) {
    switch (color) {
        case 'B':
            EXPECT_EQ(color, 'B');
            break;
        case 'P':
            EXPECT_EQ(color, 'P');
            break;
        case 'G':
            EXPECT_EQ(color, 'G');
            break;
        case 'R':
            EXPECT_EQ(color, 'R');
            break;
        case 'W':
            EXPECT_EQ(color, 'W');
            break;
        default:
            ASSERT_ANY_THROW("the input isnt correct");
            break;
    }
}
//testing if the input of the manufacturer is one of the legal valuesid isn't negative
TEST_F(TestStandardCab, testIdInput) {
    ASSERT_GE(cab.getId(),0);
}
//testing if the input of the tariff is at least 1
TEST_F(TestStandardCab, testTariffInput) {
    ASSERT_GE(cab.getTariff(),1);
}
//testing if the input of the location isn't a negative point
TEST_F(TestStandardCab, testLocationInput) {
    ASSERT_GE(cab.getLocation().getX(),0);
    ASSERT_GE(cab.getLocation().getY(),0);
}

//testing that the passenger arrived to his destination
TEST_F(TestStandardCab, testDrive) {
    EXPECT_EQ(location, end);
}

