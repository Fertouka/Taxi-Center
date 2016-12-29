// fertoud 316295005 amitayi 203839030

#include <iostream>
#include "LuxuryCab.h"

LuxuryCab::LuxuryCab(int id, int kilometrage, char manu, char color, double tariff,
                     const Point &location, Trip *trip) : Cab(id, kilometrage, manu, color, tariff, location,
                                                              trip) {}

LuxuryCab::LuxuryCab() {}

void LuxuryCab::drive() {
    location = Point(trip->getEnd());
    this->setHasTrip(false);
}

LuxuryCab::~LuxuryCab() {
}

LuxuryCab::LuxuryCab(int id, char manu, char color) : Cab(id, manu, color) {
    trip = NULL;
}
