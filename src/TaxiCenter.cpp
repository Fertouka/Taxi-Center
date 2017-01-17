// fertoud 316295005 amitayi 203839030
#include <tgmath.h>
#include "TaxiCenter.h"

TaxiCenter::TaxiCenter(std::list < Driver * > *employees,std:: list < Cab * > *cabs): employees(employees),
                                                                                      cabs(cabs), trips(NULL),
                                                                                      grid(new Grid()){}

TaxiCenter::TaxiCenter(std::list < Driver * > *employees,std:: list < Cab * > *cabs, list<Trip*> *trips):
        employees(employees),
        cabs(cabs), trips(trips),
        grid(new Grid()){}

TaxiCenter::TaxiCenter(std::list < Driver * > *employees,std:: list < Cab * > *cabs, list<Trip*> *trips, Grid *grid):
        employees(employees),
        cabs(cabs), trips(trips),
        grid(grid){}

void TaxiCenter::assignCabsToDrivers() {
    //initializing the the cabs list iterator
    list<Cab*>::iterator startC;
    list<Cab*>::iterator endC;
   // initializing the drivers list iterator
    list<Driver*>::iterator startE;
    list<Driver*>::iterator endE;
   //setting the employees iterator
    startE = employees->begin();
    endE = employees->end();
    //we are moving on the drivers list
    while (startE != endE) {
        //setting the cabs list iterator
        startC = cabs->begin();
        endC = cabs->end();
        //moving on the cabs list
        while (startC != endC) {
            //setting the current driver and thew current cab using the iterators
            Driver *d = *startE;
            Cab *c = *startC;
            //checking if there is a match between the current cab's id and the driver's cab id
            if(d->getCabId() == c->getId()) {
                //setting the cab for the current driver
                d->setCab(c);
                break;
            }
            //advancing the cab's list iterator by one step
            std::advance(startC, 1);
        }
        //advancing the driver's list iterator by one step
        std::advance(startE, 1);
    }
}
/*
void TaxiCenter::assignTripsToDrivers() {
    //flag that tells us if we have set the current trip to a cab already
    bool isTripDeleted = false;
    //initializing the trip's list iterator
    list<Trip*>::iterator start;
    list<Trip*>::iterator end;
    //setting the trip's list iterator
    //start = trips->begin();
    //end = trips->end();
    bool assignedFlag = false;
   // initializing thew cab's list iterator
    list<Cab*>::iterator startC;
    list<Cab*>::iterator endC;
   // initializing the driver's list iterator
    list<Driver *>::iterator employeesIteratorStart;
    list<Driver *>::iterator employeesIteratorEnd;
    //moving on the trip's list
    while (start != end && !assignedFlag && !trips->empty()) {
        //setting the current trip that we are checking
        Trip *t = start //trips->front();
        //setting the driver's list iterator

        employeesIteratorStart = employees->begin();
        employeesIteratorEnd = employees->end();
        //moving on the driver's list
        while (employeesIteratorEnd != employeesIteratorStart) {
            //setting the current driver using the iterator
            Driver *emp = *employeesIteratorStart;
            //checking if the current driver already has a trip
            if (!(emp->getCab()->isHasTrip())) {
                //the current driver does not have a trip, so we'll start searching the relevant cab to him
                //setting the cab's list iterator
                startC = cabs->begin();
                endC = cabs->end();
                //moving on the cab's list iterator
                while (startC != endC) {
                    //setting the current cab that we check using the iterator
                    Cab *c = *startC;
                    //checking by id if the current driver is matching the current cab
                    if (emp->getCabId() == c->getId()) {
                        //we know that the driver and the cab matches
                        //checking if the current location of the cab is matching the start point of the trip
                        if (c->getLocation() == t->getStart()) {
                            //setting the trip to the current driver and cab
                            c->setTrip(t);
                            //creating the trail of the current trip
                            if ((*grid).getHeight() != 0 && (*grid).getWidth() != 0) {
                                c->creaTrail(grid);
                            }
                            //setting that the current driver has a trip now
                            c->setHasTrip(true);
                            //erasing the current trip from the list and advancing it right after
                            trips->.pop_front();
                            //start++;
                            assignedFlag = true;
                            //we know that we've deleted a trip
                            isTripDeleted = true;
                            break;
                        }
                    }
                    //advancing the cab's list iterator
                    startC++;
                }
                //checking if we have deleted a trip from the list
                if (isTripDeleted) {
                    //we are breaking the loop, because we can just move now to the next trip in the list
                    break;
                }
            }
            //advancing the driver's list iterator
            employeesIteratorStart++;
        }
        if (!isTripDeleted) {
            //we know that we haven't deleted the a trip from the list, so we're advancing the iterator
            start++;
        } else {
            //initializing the flag
            isTripDeleted = false;
        }
    }
}
*/

void TaxiCenter::assignTripToDriver() {
    list<Driver *>::iterator it;
    it = employees->begin();
    //assign trip to driver
    if (!trips->empty()) {
        for (int i = 0; i < employees->size(); ++i) {
            if (!(*it)->getCab()->isHasTrip() && (*it)->getCab()->getLocation() == trips->front()->getStart()) {
                (*it)->getCab()->setTrip(trips->front());
                //setting that the current driver has a trip now
                (*it)->getCab()->setHasTrip(true);
                //creating the trail of the current trip
                if ((*grid).getHeight() != 0 && (*grid).getWidth() != 0) {
                    (*it)->getCab()->creaTrail(grid);
                }
                //erasing the current trip from the list and advancing it right after
                trips->pop_front();
                break;
            }
            std::advance(it, 1);
        }
    }
}

void TaxiCenter::event() {
    std::cout << "event";
}

list<Driver *> *TaxiCenter::getEmployees() const {
    return employees;
}

void TaxiCenter::addDriver(Driver* d) {
    employees->push_back(d);
}

void TaxiCenter::addTrip(Trip* t) {
    trips->push_back(t);
}

TaxiCenter::TaxiCenter() {
}
