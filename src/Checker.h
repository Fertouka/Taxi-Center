//
// Created by ido on 27/01/17.
//

#ifndef EX2TESTS_CLIENTCHECKER_H
#define EX2TESTS_CLIENTCHECKER_H


#include "Grid.h"

class Checker {
public:
    Checker();
    bool CheckClientDriver(char *driver[5]);
    bool CheckServerTripInput(Grid *grid,char *input[8]);
    bool CheckServerCabInput(char *input[4]);
    bool isNumber(std::string s);

};


#endif //EX2TESTS_CLIENTCHECKER_H
