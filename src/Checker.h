//
// Created by ido on 27/01/17.
//

#ifndef EX2TESTS_CLIENTCHECKER_H
#define EX2TESTS_CLIENTCHECKER_H


#include "Grid.h"

class Checker {
public:
    /**
     * a class constructor
     * @return  - none
     */
    Checker();
    /**
     * function that checks if the driver received in the client
     * @param driver  - the driver input
     * @return  - if the input is valid (boolean)
     */
    bool CheckClientDriver(char *driver[5]);
    /**
     * function that checks if the trip received in the server
     * @param input  - the trip input
     * @param grid - the grid
     * @return  - if the input is valid (boolean)
     */
    bool CheckServerTripInput(Grid *grid,char *input[8]);
    /**
     * function that checks if the cab received in the server
     * @param input  - the cab input
     * @return  - if the input is valid (boolean)
     */
    bool CheckServerCabInput(char *input[4]);
    /**
     * function that checks if an input is a number
     * @param s - the input
     * @return - if the input is number (boolean)
     */
    bool isNumber(std::string s);

};


#endif //EX2TESTS_CLIENTCHECKER_H
