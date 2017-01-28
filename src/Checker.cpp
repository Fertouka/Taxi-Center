//
// Created by ido on 27/01/17.
//

#include <cctype>
#include <cstdlib>
#include "Checker.h"
#include "BFS.h"


Checker::Checker() {}

bool Checker::CheckServerTripInput(Grid *grid, char *input[8]) {
    char *id = input[0];
    char *startX = input[1];
    char *startY = input[2];
    char *endX = input[3];
    char *endY = input[4];
    char *numOfPassenger = input[5];
    char *timeOfStart = input[7];
    char *tariff = input[6];
    if (isdigit(*id) && atoi( id) >= 0) {

        if (isdigit(*startX) && atoi( startX) >= 0
            && atoi( startX) < grid->getWidth()) {

            if (isdigit(*startX) && atoi( startX) >= 0
                && atoi( startX) < grid->getWidth()) {

                if (isdigit(*startY) && atoi( startY) >= 0
                    && atoi( startY) < grid->getHeight()) {

                    if (isdigit(*endX) && atoi( endX) >= 0
                        && atoi( endX) < grid->getWidth()) {

                        if (isdigit(*endY) && atoi( endY) >= 0
                            && atoi(endY) < grid->getHeight()) {
                            if (isdigit(*numOfPassenger) && atoi( numOfPassenger) >= 0) {

                                if (isdigit(*timeOfStart) && atoi( timeOfStart) > 0) {

                                    if (isdigit(*tariff) && atoi( tariff) >= 0) {
                                        Point startP = Point(atoi( startX), atoi( startY));
                                        Point endP = Point(atoi( endX), atoi( endY));
                                        stack<Node *> trail = BFS::bfs(grid, startP, endP);
                                        return !trail.empty();

                                    } else {
                                        return false;
                                    }
                                }
                            }else {
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
    return false;
}

bool Checker::CheckServerCabInput(char *input[4]) {
    char *id = input[0];
    char *typeOfCab = input[1];
    char *manufacturer = input[2];
    char *color = input[3];
    char manufacturers[4] = {'H','S','T','F'};
    char colors[5] = {'R','P','B','G','W'};
    if (isdigit(*id) && atoi( id) >= 0) {
        if (isdigit(*typeOfCab) && (atoi(typeOfCab) == 1 || atoi( typeOfCab) == 2)) {
            bool isInList = false;
            for (int i = 0; i < 4; ++i) {
                if (*manufacturer == manufacturers[i]) {
                    isInList = true;
                    break;
                }
            }
            if (isInList) {
                 isInList = false;
                for (int i = 0; i < 5; ++i) {
                    if (*color == colors[i]) {
                        isInList = true;
                        break;
                    }
                }
                return isInList;
            } else {
                return  false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool Checker::CheckClientDriver(char *driver[5]) {
    char *id = driver[0];
    char *age = driver[1];
    char *status = driver[2];
    char *exp = driver[3];
    char *cabId = driver[4];
    if (isdigit(*id) && atoi( id) >= 0) {
        if (isdigit(*age) && atoi(age) >= 0) {
            bool isEqual = false;
            char statuses [4] = {'S','M','W','D'};
            for (int i = 0; i < 4; ++i) {
                if (*status == statuses[i]) {
                    isEqual = true;
                    break;
                }
            }
            if (isEqual) {
                if (isdigit(*exp) && atoi(exp) >= 0) {
                    return isdigit(*cabId) && atoi(cabId) >= 0;
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


