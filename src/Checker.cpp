//
// Created by ido on 27/01/17.
//

#include <cctype>
#include <cstdlib>
#include "Checker.h"



Checker::Checker() {}

bool Checker::CheckServerTripInput(Grid *grid, char *input) {
    char id = input[0];
    char startX = input[1];
    char startY = input[2];
    char endX = input[3];
    char endY = input[4];
    char numOfPassenger = input[5];
    char timeOfStart = input[6];
    char tariff = input[7];
    if (isdigit(id) && atoi((const char *) id) >= 0) {

        if (isdigit(startX) && atoi((const char *) startX) >= 0
            && atoi((const char *) startX) < grid->getWidth()) {

            if (isdigit(startX) && atoi((const char *) startX) >= 0
                && atoi((const char *) startX) < grid->getWidth()) {

                if (isdigit(startY) && atoi((const char *) startY) >= 0
                    && atoi((const char *) startY) < grid->getHeight()) {

                    if (isdigit(endX) && atoi((const char *) endX) >= 0
                        && atoi((const char *) endX) < grid->getWidth()) {

                        if (isdigit(endY) && atoi((const char *) endY) >= 0
                            && atoi((const char *) endY) < grid->getHeight()) {

                            if (isdigit(timeOfStart) && atoi((const char *) timeOfStart) > 0) {

                                if (isdigit(tariff) && atoi((const char *) tariff) >= 0) {
                                    return true;
                                } else {
                                    return false;
                                }
                            } else {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool Checker::CheckServerCabInput(char *input) {
    char id = input[0];
    char typeOfCab = input[1];
    char manufacturer = input[2];
    char color = input[3];



    return false;
}

bool Checker::CheckClientDriver(char *driver) {
    char id = driver[0];
    char age = driver[1];
    char status = driver[2];
    char exp = driver[3];
    char cabId = driver[4];
    if (isdigit(id) && atoi((const char *) id) >= 0) {
        if (isdigit(age) && atoi((const char *) age) >= 0) {
            bool isEqual = false;
            char statuses [4] = {'S','M','W','D'};
            for (int i = 0; i < 4; ++i) {
                if (status == statuses[i]) {
                    isEqual = true;
                    break;
                }
            }
            if (isEqual) {
                if (isdigit(exp) && atoi((const char *) exp) >= 0) {
                    return isdigit(cabId) && atoi((const char *) cabId) >= 0;
                } else {
                    return false;
                }

            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}


