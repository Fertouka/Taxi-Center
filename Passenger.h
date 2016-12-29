// fertoud 316295005 amitayi 203839030

#ifndef EX1_PASSENGER_H
#define EX1_PASSENGER_H

#include <iostream>
#include <list>
#include "Point.h"
#include "Listener.h"
#include "Notifier.h"

using namespace std;

class Passenger : public Notifier{
private:
    Point start;
    Point end;
    list<Listener*> listeners;
public:
/**
 * class constructor
 * @param start - the start point
 * @param end - the end point
 * @param listeners - the listeners of the passenger
 * @return - none
 */
    Passenger(Point start, Point end, list<Listener*> listeners);

/**
 * class constructor
 * @param start - the start point
 * @param end - the end point
 * @return - none
 */
    Passenger(Point start, Point end);

/**
 * satisfaction getter
 * @return - the satisfaction (int)
 */
    int getSatisfaction();

/**
 * function that adds a listener to the list of listeners
 * @param listener - the listener to add
 */
    void addListener(Listener* listener);

/**
 * function that removes a listener from the listeners list
 * @param listener - the listener to remove
 */
    void removeListener(Listener* listener);

/**
 * the call notifier
 */
    void notifyCall();

/**
 * the == operator
 * @param rhs - the passenger we want to compare the current passenger
 * @return - if the passengers are equal or not (bool)
 */
    bool operator==(const Passenger &rhs) const;

/**
 * the !=operfator
 * @param rhs - the passenger we want to compare to
 * @return - if the passengers aren't equal (bool)
 */
    bool operator!=(const Passenger &rhs) const;
};


#endif //EX1_PASSENGER_H
