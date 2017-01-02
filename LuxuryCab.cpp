// fertoud 316295005 amitayi 203839030

#include <iostream>
#include "LuxuryCab.h"

LuxuryCab::LuxuryCab(int id, int kilometrage, char manu, char color, double tariff,
                     const Point &location, Trip *trip) : Cab(id, kilometrage, manu, color, tariff, location,
                                                              trip) {}

LuxuryCab::LuxuryCab() {}

void LuxuryCab::drive() {
    location = trail.top()->getPoint();
    trail.pop();
    if (!trail.empty()) {
        location = trail.top()->getPoint();
        trail.pop();
    }
    if (trail.empty())
        hasTrip = false;
    trip->setTimeOfStart(trip->getTimeOfStart() + 1);
}

LuxuryCab::~LuxuryCab() {
}

LuxuryCab::LuxuryCab(int id,int type, char manu, char color) : Cab(id, type, manu, color) {
    trip = NULL;
}
