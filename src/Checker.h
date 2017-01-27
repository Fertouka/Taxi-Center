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
    bool CheckClientDriver(char *driver);
    bool CheckServerTripInput(Grid *grid,char *input);
    bool CheckServerCabInput(char *input);

};


#endif //EX2TESTS_CLIENTCHECKER_H
