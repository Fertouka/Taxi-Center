// fertoud 316295005 amitayi 203839030

#include <iostream>
#include "LuxuryCab.h"

LuxuryCab::LuxuryCab(int id, int kilometrage, char manu, char color, double tariff,
                     const Point &location, Trip *trip) : Cab(id, kilometrage, manu, color, tariff, location,
                                                              trip) {}

LuxuryCab::LuxuryCab() {}

void LuxuryCab::drive() {
    //advance the driver twice
    location = trail.top()->getPoint();
    trail.pop();
    if (!trail.empty()) {
        location = trail.top()->getPoint();
        trail.pop();
    }
    //if we finished the trip, we update the "hasTrip" to false
    if (trail.empty())
        hasTrip = false;
    //update the time in the driver
    trip->setTimeOfStart(trip->getTimeOfStart() + 1);
}

LuxuryCab::~LuxuryCab() {
}

LuxuryCab::LuxuryCab(int id,int type, char manu, char color) : Cab(id, type, manu, color) {
    trip = NULL;
}
