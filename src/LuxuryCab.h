// fertoud 316295005 amitayi 203839030

#ifndef EX1_LUXURYCAB_H
#define EX1_LUXURYCAB_H


#include "Cab.h"

class LuxuryCab : public Cab {
public:

/**
 * default constructor of Luxury cab
 */
    LuxuryCab();

/**
 * Luxury cab constructor
 * @param id of Luxury cab
 * @param manu
 * @param color
 */
    LuxuryCab(int id, int type, char manu, char color);

/**
 * Luxury cab constructor
 * @param id of Luxury cab
 * @param kilometrage
 * @param manu
 * @param color
 * @param tariff
 * @param location
 * @param trip
 */
    LuxuryCab(int id, int kilometrage, char manu, char color, double tariff, const Point &location,
              Trip *trip);

/**
 * the drive function that moves the cab from two points to another
 */
    void drive();

/**
 * destructor pf Luxury cab
 */
    virtual ~LuxuryCab();
};


#endif //EX1_LUXURYCAB_H
