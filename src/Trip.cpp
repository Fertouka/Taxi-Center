// fertoud 316295005 amitayi 203839030

#include "Trip.h"

Trip::Trip() {}

Trip::Trip(int rideNum, int metersPassed, const Point &start, const Point &end, int numOfPassengers, double tariff)
        : rideNum(rideNum), metersPassed(metersPassed), start(start), end(end), numOfPassengers(numOfPassengers),
          tariff(tariff) {}

int Trip::getRideNum() const {
    return rideNum;
}

int Trip::getMetersPassed() const {
    return metersPassed;
}

const Point &Trip::getStart() const {
    return start;
}

const Point &Trip::getEnd() const {
    return end;
}

int Trip::getNumOfPassengers() const {
    return numOfPassengers;
}

double Trip::getTariff() const {
    return tariff;
}

void Trip::setRideNum(int rideNum) {
    Trip::rideNum = rideNum;
}

void Trip::setMetersPassed(int metersPassed) {
    Trip::metersPassed = metersPassed;
}

void Trip::setStart(const Point &start) {
    Trip::start = start;
}

void Trip::setEnd(const Point &end) {
    Trip::end = end;
}

void Trip::setNumOfPassengers(int numOfPassengers) {
    Trip::numOfPassengers = numOfPassengers;
}

void Trip::setTariff(double tariff) {
    Trip::tariff = tariff;
}

bool Trip::operator==(const Trip &rhs) const {
    //we check if all the parameters in tre trips are equal
    return rideNum == rhs.rideNum &&
           metersPassed == rhs.metersPassed &&
           start == rhs.start &&
           end == rhs.end &&
           numOfPassengers == rhs.numOfPassengers &&
           tariff == rhs.tariff;
}

Trip::Trip(int rideNum, const Point &start, const Point &end, int numOfPassengers, double tariff, int timeOfStart) :
                                                                                                    rideNum(rideNum),
                                                                                                    metersPassed(0),
                                                                                                    start(start),
                                                                                                    end(end),
                                                                                                    numOfPassengers(
                                                                                                            numOfPassengers),
                                                                                                    tariff(tariff),
                                                                                                    timeOfStart(timeOfStart)
                                                                                                    {}

int Trip::getTimeOfStart() const {
    return timeOfStart;
}

void Trip::setTimeOfStart(int timeOfStart) {
    Trip::timeOfStart = timeOfStart;
}
