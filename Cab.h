// fertoud 316295005 amitayi 203839030

#ifndef EX1_CAB_H
#define EX1_CAB_H

#include <iostream>
#include <stack>
#include "Point.h"
#include "Trip.h"
#include "Node.h"
#include "Grid.h"

using namespace std;

class Cab {
protected:
    int id;
    int kilometrage;
    char manu;
    char color;
    double tariff;
    int type;
    Point location;
    bool hasTrip;
    stack<Node*> trail;
    Trip* trip;
public:
    /**
     * default constructor of cab.
     */
    Cab();

    /**
     * Cab's constructor
     * @param id rof a cab
     * @param manufacturer
     * @param color
     */
    Cab(int id, int type, char manu, char color);

    /**
     * Cab's constructor
     * @param id rof a cab
     * @param kilometrage
     * @param manufacturer
     * @param color
     * @param tariff
     * @param location
     * @param trip
     */
    Cab(int id, int kilometrage, char manu, char color, double tariff, const Point &location,
        Trip *trip);

    /**
     * the drive function that moves the cab from one point to another
     */
    virtual void drive() = 0;

    /**
     * getting the cab's id
     */
    virtual int getId() const;
    /**
     * getting the cab's kilometrage
     */
    virtual int getKilometrage() const;

    /**
     * getting the cab's manufacturer
     */
    virtual char getManufacturer() const;

    /**
     * getting the cab's color
     */
    virtual char getColor() const;

    /**
     * getting the cab's tariff
     */
    virtual double getTariff() const;

    /**
     * getting the cab's current location
     */
    virtual const Point &getLocation() const;

    /**
     * getting the cab's trip
     */
    virtual Trip *getTrip() const;

    /**
     * checking if a cab has a trip
     */
    bool isHasTrip() const;

    /**
     * setting if a cab has a trip
     * @param hasTrip - true if has a trip, otherwise false.
     */
    void setHasTrip(bool hasTrip);

    /**
     * setting the cab's id
     */
    virtual void setId(int id);

    /**
     * setting the cab's kilometrage
     */
    virtual void setKilometrage(int kilometrage);

    /**
     * setting the cab's manufacturer
     */
    virtual void setManufacturer(char manu);

    /**
     * setting the cab's color
     */
    virtual void setColor(char color);

    /**
     * setting the cab's tariff
     */
    virtual void setTariff(double tariff);

    /**
     * setting the cab's current location
     */
    virtual void setLocation(const Point &location);

    /**
     * setting the cab's trip
     */
    virtual void setTrip(Trip* trip);

    int getType() const;

    void creaTrail(Grid grid);
};


#endif //EX1_CAB_H
