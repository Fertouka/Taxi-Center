

#include <iostream>
#include "Driver.h"
#include "gtest/gtest.h"
#include "LuxuryCab.h"

using namespace std;

class TestDriver : public::testing::Test {
protected:
    int id;
    int age;
    char status;
    char status2;
    int experience;
    int cabId;
    Cab *cab;
    double satisfaction;
    Driver driver;
    Driver driver2;

    virtual void SetUp() {
        cout << "Setting Up" << endl;
    }

    virtual void TearDown() {
        cout << "Tear Down" << endl;
    }

public:
    TestDriver() : id(44), age(46), status('S'), status2('M'), experience(10), cabId(3),
                   satisfaction(5), cab(new LuxuryCab()),
                   driver(id, age, status, experience, cabId),
                   driver2(19,33, status2,2, 5) {}
};

/**
 * testing that the tptal tariff is positive
 */
TEST_F(TestDriver, testForTotalTariff) {
    EXPECT_GE(driver.tariffOfTotalDriving(), 0);
}

/**
 * testing the getter of driver's id
 */
TEST_F(TestDriver, testGetId) {
    EXPECT_EQ(id, driver.getId());
}

/**
 * testing the getter of driver's age
 */
TEST_F(TestDriver, testGetAge) {
    EXPECT_EQ(age, driver.getAge());
}

/**
 * testing the getter of driver's status
 */
TEST_F(TestDriver, testGetStatus) {
    EXPECT_EQ(status, driver.getStatus());
}

/**
 * testing the getter of driver's experience
 */
TEST_F(TestDriver, testGetExperience) {
    EXPECT_EQ(experience, driver.getExperience());
}

/**
 * testing the getter of driver's satisfaction
 */
TEST_F(TestDriver, testGetSatisfaction) {
    EXPECT_EQ(0, driver.getSatisfaction());
}

/**
 * testing the getter and the setter of driver's cab
 */
TEST_F(TestDriver, testSetAndGetCab) {
    driver.setCab(cab);
    EXPECT_EQ(cab, driver.getCab());
}

/**
 * testing the setter of driver's id
 */
TEST_F(TestDriver,testSetId) {
    driver.setId(driver2.getId());
    EXPECT_EQ(driver2.getId(), driver.getId());
}

/**
 * testing the setter of driver's age
 */
TEST_F(TestDriver, testSetAge) {
    driver.setAge(driver2.getAge());
    EXPECT_EQ(driver2.getAge(), driver.getAge());
}

/**
 * testing the setter of driver's status
 */
TEST_F(TestDriver, testSetStatus) {
    driver.setStatus(driver2.getStatus());
    EXPECT_EQ(driver2.getStatus(), driver.getStatus());
}

/**
 * testing the setter of driver's experience
 */
TEST_F(TestDriver, testSetExperience) {
    driver.setExperience(driver2.getExperience());
    EXPECT_EQ(driver2.getExperience(), driver.getExperience());
}

/**
 * testing the setter of driver's satisfaction
 */
TEST_F(TestDriver, testSetSatisfaction) {
    driver.setSatisfaction(satisfaction);
    EXPECT_EQ(satisfaction,driver.getSatisfaction());
}

/**
 * testing that the driver has legal age for driving lisence
 */
TEST_F(TestDriver, testDriverAgeInput) {
    ASSERT_GE(driver.getAge(), 17);
}

/**
 * testing that the experience is positive and not bigger than tha age that a man can be a driver
 */
TEST_F(TestDriver, testExperienceInput) {
    ASSERT_GE(driver.getExperience(), 0);
    ASSERT_GE(driver.getAge() - driver.getExperience() ,17);
}

/**
 * testing that the satisfaction btween 1 to 5
 */
TEST_F(TestDriver, testSatisfactionInput) {
    driver.setSatisfaction(3);
    ASSERT_GE(driver.getSatisfaction(), 1);
    ASSERT_LE(driver.getSatisfaction(), 5);
}

/**
 * testing that the id of driver is not 0 - not exist
 */
TEST_F(TestDriver, testIdInput) {
    ASSERT_GE(driver.getId(), 0);
}

/**
 * testing that the cab id of driver is not 0 - not exist
 */
TEST_F(TestDriver, testcabIdInput) {
    ASSERT_GE(driver.getCabId(), 0);
}

/**
 * testing that the status of driver
 */
TEST_F(TestDriver, testStatusInput) {
    switch (status) {
        case 'S':
            EXPECT_EQ(status, 'S');
            break;
        case 'M':
            EXPECT_EQ(status, 'M');
            break;
        case 'D':
            EXPECT_EQ(status, 'D');
            break;
        case 'W':
            EXPECT_EQ(status, 'W');
            break;
        default:
            ASSERT_ANY_THROW("the input isnt correct");
            break;
    }
}

