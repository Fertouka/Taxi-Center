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
    if (isNumber(id) && atoi( id) >= 0) {

        if (isNumber(startX) && atoi( startX) >= 0
            && atoi( startX) < grid->getWidth()) {

            if (isNumber(startX) && atoi( startX) >= 0
                && atoi( startX) < grid->getWidth()) {

                if (isNumber(startY) && atoi( startY) >= 0
                    && atoi( startY) < grid->getHeight()) {

                    if (isNumber(endX) && atoi( endX) >= 0
                        && atoi( endX) < grid->getWidth()) {

                        if (isNumber(endY) && atoi( endY) >= 0
                            && atoi(endY) < grid->getHeight()) {
                            if (isNumber(numOfPassenger) && atoi( numOfPassenger) >= 0) {

                                if (isNumber(timeOfStart) && atoi( timeOfStart) > 0) {

                                    if (isNumber(tariff) && atoi( tariff) >= 0) {
                                        Point startP = Point(atoi( startX), atoi( startY));
                                        Point endP = Point(atoi( endX), atoi( endY));
                                        stack<Node *> trail = BFS::bfs(grid, startP, endP);
                                        return !trail.empty();

                                    } else {
                                        cout << "-1\n";
                                        return false;
                                    }
                                }
                            }else {
                                cout << "-1\n";
                                return false;
                            }
                        } else {
                            cout << "-1\n";
                            return false;
                        }
                    } else {
                        cout << "-1\n";
                        return false;
                    }
                } else {
                    cout << "-1\n";
                    return false;
                }
            } else {
                cout << "-1\n";
                return false;
            }
        } else {
            cout << "-1\n";
            return false;
        }
    } else {
        cout << "-1\n";
        return false;
    }
    cout << "-1\n";
    return false;
}

bool Checker::CheckServerCabInput(char *input[4]) {
    char *id = input[0];
    char *typeOfCab = input[1];
    char *manufacturer = input[2];
    char *color = input[3];
    char manufacturers[4] = {'H','S','T','F'};
    char colors[5] = {'R','P','B','G','W'};
    if (isNumber(id) && atoi( id) >= 0) {
        if (isNumber(typeOfCab) && (atoi(typeOfCab) == 1 || atoi( typeOfCab) == 2)) {
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
    if (isNumber(id) && atoi( id) >= 0) {
        if (isNumber(age) && atoi(age) >= 0) {
            bool isEqual = false;
            char statuses [4] = {'S','M','W','D'};
            for (int i = 0; i < 4; ++i) {
                if (*status == statuses[i]) {
                    isEqual = true;
                    break;
                }
            }
            if (isEqual) {
                if (isNumber(exp) && atoi(exp) >= 0) {
                    return isNumber(cabId) && atoi(cabId) >= 0;
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

bool Checker::isNumber(std::string s) {
    std::string::iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) {
        ++it;
    }
    return !s.empty() && it == s.end();
}