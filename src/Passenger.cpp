

#include "Passenger.h"

using namespace std;

Passenger::Passenger(Point start, Point end) : start(start), end(end) {}

Passenger::Passenger(Point start, Point end, list<Listener*> listeners) {
    //initializing the values
    Passenger::start = Point(start.getX(), start.getY());
    Passenger::end = Point(end.getX(), end.getY());
    Passenger::listeners = listeners;
}

int Passenger::getSatisfaction() {
    return 1;
}

void Passenger::addListener(Listener *listener) {
    std::cout << "adding call listener";
    listeners.push_back(listener);
}

void Passenger::removeListener(Listener *listener) {
    std::cout << "removing call listener";
    listeners.remove(listener);
}

void Passenger::notifyCall() {
}

bool Passenger::operator==(const Passenger &rhs) const {
    return
        //checking if all the parameters of the two passengers are equal
           start == rhs.start &&
           end == rhs.end &&
           listeners == rhs.listeners;
}

bool Passenger::operator!=(const Passenger &rhs) const {
    //using the == operator to check i they are equal or not
    return !(rhs == *this);
}
