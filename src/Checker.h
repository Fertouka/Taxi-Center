//
// Created by ido on 27/01/17.
//

#ifndef EX2TESTS_CLIENTCHECKER_H
#define EX2TESTS_CLIENTCHECKER_H


#include "Grid.h"

class Checker {
public:
    Checker();

public:
    bool CheckClientDriver(char *driver[5]);
    bool CheckServerTripInput(Grid *grid,char *input[8]);
    bool CheckServerCabInput(char *input[4]);

};


#endif //EX2TESTS_CLIENTCHECKER_H
