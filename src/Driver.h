// fertoud 316295005 amitayi 203839030

#ifndef EX1_DRIVER_H
#define EX1_DRIVER_H

#include <iostream>
#include "Cab.h"
#include "Passenger.h"
#include <pthread.h>
#include <string.h>
using namespace std;

class Driver {
private:
    int id;
    int age;
    char status;
    int experience;
    double satisfaction;
    int cabId;
    Cab *cab;
public:

/**
 * driver constructor
 * @param id of driver
 * @param age
 * @param status
 * @param experience of driving in taxi
 * @param passenger
 * @return
 */
    Driver(int id, int age, char status, int experience, int cabId);

/**
 * @return the tariff of total driving
 */
    double tariffOfTotalDriving();

/**
 * getting driver's id
 */
    int getId() const;

/**
 * setting driver's id
 */
    void setId(int id);

/**
 * getting driver's age
 */
    int getAge() const;

/**
 * setting driver's age
 */
    void setAge(int age);

/**
 * getting driver's status
 */
    char getStatus() const;

/**
 * setting driver's status
 */
    void setStatus(char status);

/**
 * getting driver's experience
 */
    int getExperience() const;

/**
 * setting driver's experience
 */
    void setExperience(int experience);

/**
 * getting driver's satisfaction
 */
    double getSatisfaction() const;

/**
 * setting driver's satisfaction
 */
    void setSatisfaction(double satisfaction);

/**
 * getting driver's cab
 */
    Cab *getCab() const;

/**
 * setting driver's cab
 */
    void setCab(Cab *cab);

/**
 * getting cab id
 */
    int getCabId();

/**
 * getting driver's current location
 */
    void getDriverLocation();

/**
 * default constructor of driver
 */
    Driver();


};


#endif //EX1_DRIVER_H
