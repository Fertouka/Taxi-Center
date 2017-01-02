// fertoud 316295005 amitayi 203839030

#include <iostream>
#include "StandardCab.h"

StandardCab::StandardCab(int id, int kilometrage, char manu, char color, double tariff,
                         const Point &location, Trip *trip) :
        Cab::Cab(id, kilometrage, manu, color, tariff, location, trip) {}

StandardCab::~StandardCab() {

}

void StandardCab::drive() {
    cout << "the next step in the trail is" << trail.top()->getPoint() << "\n";
    location = trail.top()->getPoint();
    trail.pop();
    if (trail.empty())
        hasTrip = false;
    trip->setTimeOfStart(trip->getTimeOfStart() + 1);
}

StandardCab::StandardCab(int id, int type, char manu, char color) : Cab(id, type, manu, color) {}
