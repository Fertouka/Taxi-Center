// fertoud 316295005 amitayi 203839030

#include <iostream>
#include "StandardCab.h"

StandardCab::StandardCab(int id, int kilometrage, char manu, char color, double tariff,
                         const Point &location, Trip *trip) :
        Cab::Cab(id, kilometrage, manu, color, tariff, location, trip) {}

StandardCab::~StandardCab() {

}

void StandardCab::drive() {
    location = Point(trip->getEnd());
    this->setHasTrip(false);
}

StandardCab::StandardCab(int id, char manu, char color) : Cab(id, manu, color) {}
