// fertoud 316295005 amitayi 203839030

#ifndef EX1_TAXICENTER_H
#define EX1_TAXICENTER_H


#include <list>
#include "Driver.h"

class TaxiCenter : public Listener {
private:
    list<Driver*> *employees;
    list<Cab*> *cabs;
    list<Trip*> *trips;
    Grid *grid;
public:
/**
 * class constructor
 * @return  - none
 */
    TaxiCenter();

/**
 * class constructor
 * @param employees - pointer the drivers list
 * @param cabs - pointer to the cabs list
 * @param grid
 */
    TaxiCenter(list<Driver *> *employees, list<Cab *> *cabs);

    TaxiCenter(list<Driver *> *employees, list<Cab *> *cabs, list<Trip*> *trips);
/**
 * class constructor
 * @param employees - pointer the drivers list
 * @param cabs - pointer to the cabs list
 * @return - none
 */
    TaxiCenter(list<Driver *> *employees, list<Cab *> *cabs, list<Trip*> *trips, Grid *grid);

/**
 * function that assigns the current cab to the current driver
 * @return - none
 */
    void assignCabsToDrivers();

/**
 * function that assigns the trips from the trips list to ythe currect driver and cab
 * @param trips - the trips list
 */
    void assignTripsToDrivers();

/**
 * function tyhat tells a taxi to go pick a client that called
 */
    void event();

    list<Driver *> *getEmployees() const;

    void addDriver(Driver* d);

    void addTrip(Trip* trip);
};


#endif //EX1_TAXICENTER_H


