// fertoud 316295005 amitayi 203839030

#include "Cab.h"
#include "Grid.h"
#include "BFS.h"


Cab::Cab() {}

Cab::Cab(int id, int kilometrage, char manufacturer, char color, double tariff, const Point &location,
         Trip *trip) : id(id), kilometrage(kilometrage), manu(manufacturer), color(color), tariff(tariff),
                       location(location), hasTrip(true), trip(trip) {}

int Cab::getId() const {
    return id;
}

int Cab::getKilometrage() const {
    return kilometrage;
}

char Cab::getManufacturer() const {
    return manu;
}

char Cab::getColor() const {
    return color;
}

double Cab::getTariff() const {
    return tariff;
}

const Point &Cab::getLocation() const {
    return location;
}

Trip *Cab::getTrip() const {
    return trip;
}

void Cab::setId(int id) {
    Cab::id = id;
}

void Cab::setKilometrage(int kilometrage) {
    Cab::kilometrage = kilometrage;
}

void Cab::setManufacturer(char manufacturer) {
    Cab::manu = manufacturer;
}

void Cab::setColor(char color) {
    Cab::color = color;
}

void Cab::setTariff(double tariff) {
    Cab::tariff = tariff;
}

void Cab::setLocation(const Point &location) {
    Cab::location = location;
}

void Cab::setTrip(Trip* trip) {
    Cab::trip = trip;
}

Cab::Cab(int id, int type, char manu, char color) : id(id), type(type), kilometrage(0), manu(manu), color(color), tariff(0.0), hasTrip(
        false) {}

bool Cab::isHasTrip() const {
    return hasTrip;
}

void Cab::setHasTrip(bool hasTrip) {
    Cab::hasTrip = hasTrip;
}

int Cab::getType() const {
    return type;
}

void Cab::creaTrail(Grid *grid) {
    cout << "now in the createTrail of Cab.cpp\n";
    trail = BFS::bfs(grid, trip->getStart(), trip->getEnd());
}