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
    //we are checking if the received id is a number and greater than zero
    if (isNumber(id) && atoi( id) >= 0) {
        // we know that the id input is valid
        //we are checking if the x value of the start point is a number,
        // greater than zero, and not out of the grid limits
        if (isNumber(startX) && atoi( startX) >= 0
            && atoi( startX) < grid->getWidth()) {
                //we know that the x value of the start point is valid
                //we are checking if the y value of the start point is a number,
                // greater than zero, and not out of the grid limits

                if (isNumber(startY) && atoi( startY) >= 0
                    && atoi( startY) < grid->getHeight()) {
                    //we know that the y value of the start point is valid
                    //we are checking if the x value of the end point is a number,
                    // greater than zero, and not out of the grid limits

                    if (isNumber(endX) && atoi( endX) >= 0
                        && atoi( endX) < grid->getWidth()) {
                        //we know that the x value of the end point is valid
                        //we are checking if the y value of the end point is a number,
                        // greater than zero, and not out of the grid limits
                        if (isNumber(endY) && atoi( endY) >= 0
                            && atoi(endY) < grid->getHeight()) {
                            //we know that all the points are good
                            //we are checking if the number of passengers is a number and greater than zero
                            if (isNumber(numOfPassenger) && atoi( numOfPassenger) >= 0) {
                                // we know that the number of passengers is valid
                                //we are checking if the time of start is anumber and greater than zero
                                if (isNumber(timeOfStart) && atoi( timeOfStart) > 0) {
                                    //we know that the time of start is valid
                                    //we are checking if the tariff is a number and greater than zero

                                    if (isNumber(tariff) && atoi( tariff) >= 0) {
                                        Point startP = Point(atoi( startX), atoi( startY));
                                        Point endP = Point(atoi( endX), atoi( endY));
                                        //we are checking if there is a trail between the two inserted points
                                        stack<Node *> trail = BFS::bfs(grid, startP, endP);
                                        //if the there is a trail -> all the input is valid and we will return true
                                        return !trail.empty();

                                    } else {
                                        //invalid input
                                        cout << "-1\n";
                                        return false;
                                    }
                                } else {
                                    //invalid input
                                    cout << "-1\n";
                                    return false;
                                }
                            }else {
                                //invalid input
                                cout << "-1\n";
                                return false;
                            }
                        } else {
                            //invalid input
                            cout << "-1\n";
                            return false;
                        }
                    } else {
                        //invalid input
                        cout << "-1\n";
                        return false;
                    }
                } else {
                    //invalid input
                    cout << "-1\n";
                    return false;
                }

        } else {
            //invalid input
            cout << "-1\n";
            return false;
        }
    } else {
        //invalid input
        cout << "-1\n";
        return false;
    }

}

bool Checker::CheckServerCabInput(char *input[4]) {
    char *id = input[0];
    char *typeOfCab = input[1];
    char *manufacturer = input[2];
    char *color = input[3];
    //an array that contains all the valid manufacturers
    char manufacturers[4] = {'H','S','T','F'};
    //array that contains all the valid colors
    char colors[5] = {'R','P','B','G','W'};
    //we are checking if the received id is a number and greater than zero
    if (isNumber(id) && atoi( id) >= 0) {
        //we are checking if the type of cab is a number and equals 1 or 2
        if (isNumber(typeOfCab) && (atoi(typeOfCab) == 1 || atoi( typeOfCab) == 2)) {
            bool isInList = false;
            //we are checking if the received manufacturer equals one of the valid manufacturers
            for (int i = 0; i < 4; ++i) {
                if (*manufacturer == manufacturers[i]) {
                    //we know that the manufacturer is in the list -> is valid
                    isInList = true;
                    break;
                }
            }
            if (isInList) {
                 isInList = false;
                //we are checking if the received color equals one of the valid colors

                for (int i = 0; i < 5; ++i) {
                    if (*color == colors[i]) {
                        //we know that the color is in the list -> is valid
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
    //we are checking if the received id is a number and greater than zero
    if (isNumber(id) && atoi( id) >= 0) {
        //we are checking if the received age is a number and greater than zero
        if (isNumber(age) && atoi(age) >= 0) {
            bool isEqual = false;
            //array that contains the valid statuses
            char statuses [4] = {'S','M','W','D'};
            //we are checking if the received status equals one of the valid statuses
            for (int i = 0; i < 4; ++i) {
                if (*status == statuses[i]) {
                    //we know that the status is in the list -> is valid

                    isEqual = true;
                    break;
                }
            }
            if (isEqual) {
                //we are checking if the received experience is a number and not negative
                if (isNumber(exp) && atoi(exp) >= 0) {
                    //we are checking if the received cab id is a number and not negative

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
    // an iterator
    std::string::iterator it = s.begin();
    //we are going thrugh the input and check if every char is a number
    while (it != s.end() && std::isdigit(*it)) {
        ++it;
    }
    //we check her if the received input was not empty and if we succeeded passing all the string
    return !s.empty() && it == s.end();
}