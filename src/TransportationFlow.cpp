


#include "TransportationFlow.h"

TransportationFlow::TransportationFlow(Grid grid, const TaxiCenter &taxiCenter) : grid(grid),
                                                                                  taxiCenter(taxiCenter) {
    //creating the grid
    grid.create();
}

void TransportationFlow::randomPassenger() {
    std::cout << "choosing random passenger";
}

void TransportationFlow::trajectory(Point start, Point end) {
    //computing the trajectory using the bfs
    BFS::bfs(&grid, start, end);
}
