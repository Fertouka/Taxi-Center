// fertoud 316295005 amitayi 203839030

#ifndef EX1_STANDARDCAB_H
#define EX1_STANDARDCAB_H

#include "Cab.h"

class StandardCab : public Cab {
public:
/**
 * class constructor
 * @param id - the cab's id
 * @param manu - the cab's manufacturer
 * @param color - the cab's color
 * @return - none
 */
    StandardCab(int id, char manu, char color);

/**
 * class constructor
 * @param id - the cab's id
 * @param kilometrage - the cab's kilometrage
 * @param manu - the cab's manufacturer
 * @param color - the cab's color
 * @param tariff - the cab's tariff for a drive
 * @param location - the cab's current location
 * @param trip - thed cab's trip
 * @return - none
 */
    StandardCab(int id, int kilometrage, char manu, char color, double tariff, const Point &location,
              Trip *trip);

/**
 * class destructor
 */
    virtual ~StandardCab();

/**
 * the drive function that moves the cab from one point to another
 */
    void drive();

};


#endif //EX1_STANDARDCAB_H
