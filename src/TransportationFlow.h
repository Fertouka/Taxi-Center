

#ifndef EX1_TRANSPORTATIONMAP_H
#define EX1_TRANSPORTATIONMAP_H


#include "Grid.h"
#include "TaxiCenter.h"
#include "BFS.h"

class TransportationFlow {
private:
    Grid grid;
    TaxiCenter taxiCenter;
public:
/**
 * class constructor
 * @param grid - the grid we work on
 * @param taxiCenter - the taxi center
 * @return - none
 */
    TransportationFlow(Grid grid, const TaxiCenter &taxiCenter);

/**
 * function that chooses radnom passenger
 */
    void randomPassenger();

/**
 * function that compute the trajectory between two points using the bfs class
 * @param start - the start point
 * @param end - the end point
 */
    void trajectory(Point start, Point end);
};


#endif //EX1_TRANSPORTATIONMAP_H
