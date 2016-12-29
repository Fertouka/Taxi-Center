// fertoud 316295005 amitayi 203839030

#ifndef EX1_TRIP_H
#define EX1_TRIP_H


#include "Point.h"

class Trip {
private:
    int rideNum;
    int metersPassed;
    Point start;
    Point end;
    int numOfPassengers;
    double tariff;
public:
/**
 * default constructor of trip
 */
    Trip();

/**
 * the class constructor
 * @param rideNum - the number of the ride
 * @param metersPassed - the meters passed until now in the trip
 * @param start - the start point of the trip
 * @param end - the end point of the trail
 * @param numOfPassengers - the number of passengers in the trip
 * @param tariff  - the tariff of the drive
 * @return - none
 */
    Trip(int rideNum, int metersPassed, const Point &start, const Point &end, int numOfPassengers, double tariff);
/**
 * class constructor
 * @param rideNum - the ride num
 * @param start - the start point of the trip
 * @param end - the end point of the trip
 * @param numOfPassengers - the number of passengers
 * @param tariff - the tariff
 * @return - none
 */
    Trip(int rideNum, const Point &start, const Point &end, int numOfPassengers, double tariff);

/**
 * ride num getter
 * @return - the number of the ride (int)
 */
    int getRideNum() const;

/**
 * metersPassed getter
 * @return - the value of the meters passed in the current trip (int)
 */
    int getMetersPassed() const;

/**
 * start point getter
 * @return - the value of the start point (Point)
 */
    const Point &getStart() const;

/**
 * end point getter
 * @return - the value of the end point (Point)
 */
    const Point &getEnd() const;

/**
 * number of [passengers gettr
 * @return - the number of passengers in the trip (int)
 */
    int getNumOfPassengers() const;

/**
 * tariff getter
 * @return - the value of the tariff (double)
 */
    double getTariff() const;

/**
 * ride number setter
 * @param rideNum - the number of the ride
 */
    void setRideNum(int rideNum);

/**
 * meters passed setter
 * @param metersPassed - the meters passed
 */
    void setMetersPassed(int metersPassed);

/**
 * start point setter
 * @param start - the start point
 */
    void setStart(const Point &start);

/**
* end point setter
* @param end - the end point
*/
    void setEnd(const Point &end);

/**
 * number of passengers setter
 * @param numOfPassengers - the number of passengers
 */
    void setNumOfPassengers(int numOfPassengers);

/**
 * tariff setter
 * @param tariff - the tariff
 */
    void setTariff(double tariff);

/**
 * the equal operator
 * @param rhs - the trip we want to compare the current trip
 * @return - if the trips are equal or not (bool)
 */
    bool operator==(const Trip &rhs) const;

};


#endif //EX1_TRIP_H
