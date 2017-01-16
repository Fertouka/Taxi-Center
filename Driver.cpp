// fertoud 316295005 amitayi 203839030

#include <cstdio>
#include "Driver.h"

Driver::Driver(int id, int age, char status, int experience, int cabId) : id(id), age(age), status(status),
                                                                  experience(experience), satisfaction(0),
                                                                  cab(NULL), cabId(cabId) {}

double Driver::tariffOfTotalDriving() {
    return 0.0;

}

int Driver::getId() const {
    return id;

}

void Driver::setId(int id) {
    Driver::id = id;
}

int Driver::getAge() const {
    return age;
}

void Driver::setAge(int age) {
    Driver::age = age;
}

char Driver::getStatus() const {
    return status;
}

void Driver::setStatus(char status) {
    Driver::status = status;
}

int Driver::getExperience() const {
    return experience;
}

void Driver::setExperience(int experience) {
    Driver::experience = experience;
}

double Driver::getSatisfaction() const {
    return satisfaction;
}

void Driver::setSatisfaction(double satisfaction) {
    Driver::satisfaction = satisfaction;
}

Cab *Driver::getCab() const {
    return cab;
}

void Driver::setCab(Cab *cab) {
    Driver::cab = cab;
}

int Driver::getCabId() {
    return cabId;
}

void Driver::getDriverLocation() {
    cout << cab->getLocation();
}

Driver::Driver() {

}



