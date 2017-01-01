// fertoud 316295005 amitayi 203839030

#include <iostream>
#include "LuxuryCab.h"

LuxuryCab::LuxuryCab(int id, int kilometrage, char manu, char color, double tariff,
                     const Point &location, Trip *trip) : Cab(id, kilometrage, manu, color, tariff, location,
                                                              trip) {}

LuxuryCab::LuxuryCab() {}

void LuxuryCab::drive() {
    if (trail.empty()) {
        this->setHasTrip(false);
    } else {
        trail.pop();
        if (!trail.empty()) {
            trail.pop();
        }
        location = trail.top()->getPoint();
    }
}

LuxuryCab::~LuxuryCab() {
}

LuxuryCab::LuxuryCab(int id,int type, char manu, char color) : Cab(id, type, manu, color) {
    trip = NULL;
}
