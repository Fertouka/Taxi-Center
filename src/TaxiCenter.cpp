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


void TaxiCenter::addDriver(Driver* d) {
    employees->push_back(d);
}

void TaxiCenter::event() {

}

TaxiCenter::TaxiCenter() {
}
