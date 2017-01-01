// fertoud 316295005 amitayi 203839030
#include <iostream>
#include <cstdlib>
#include <boost/lexical_cast.hpp>
#include "Driver.h"
#include "StandardCab.h"
#include "LuxuryCab.h"
#include "Matrix.h"
#include "TaxiCenter.h"
#include "Udp.h"

using namespace std;

int main() {
    Udp server(1, 5555);
    server.initialize();
    cout << "initialized\n";
    //dummy for signs we ignore in the input
    char dummy;
    //in this line we creating the grid
    Grid grid;
    //the size of the grid
    int size[2];
    char b[1024];
    server.reciveData(b, sizeof(b));
    cout << b;
    cin >> size[0] >> size[1];
    int numOfObstacles;
    list <Point> obstacles;
    cin >> numOfObstacles;
    cout << "recieved" << numOfObstacles << "obstacles";
    //creating a list of obstacles
    if (numOfObstacles != 0) {
        //Point p = Point();
        for (int i = 0; i < numOfObstacles; i++) {
            int x;
            int y;
            cin >> x >> dummy >> y;
            obstacles.push_back(Point(x,y));
            cout << "created the point" << Point(x,y) ;
        }
        //creating a grid with obstacles
        grid = Matrix(size[0], size[1], obstacles);
        cout << "\n created a grid of" << size[0] << "X" << size[1];
    } else {
        //creating a grid without obstacles
        grid = Matrix(size[0], size[1]);
    }
    std::list <Driver*> drivers;
    std::list <Trip*> trips;
    std::list <Cab*> cabs;
    std::list <string> serCabs;
    int id;
    //choice of the user
    int choice;
    int time = 0;
    TaxiCenter tc = TaxiCenter(&drivers, &cabs, grid);
    //menu for the user
    do {
        cin >> choice;
        server.sendData(boost::lexical_cast<string>(choice));
        cout << "\nserver sent the choice:" << choice;
        switch (choice) {
            //create a driver
            case 1: {
                int numOfDrivers;
                cin >> numOfDrivers;
                cout <<"\nrecievef num of drivers:" << numOfDrivers;
                server.sendData(boost::lexical_cast<string>(numOfDrivers));
                cout << "\nsent to the client the num of drivers:" << numOfDrivers;
                while (numOfDrivers != 0) {
                    char buffer[1024];
                    server.reciveData(buffer, sizeof(buffer));
                    char *driver[5];
                    int i = 0;
                    char* split;
                    split = strtok(buffer, ",");
                    while (split != NULL && i < 5) {
                        driver[i] = split;
                        i++;
                        split = strtok (NULL, ",");
                    }
                    Driver *d = new Driver(atoi(driver[0]), atoi(driver[1]),
                                           *driver[2], atoi(driver[3]), atoi(driver[4]));
                    drivers.push_back(d);
                    tc.assignCabsToDrivers();
                    numOfDrivers--;
                }
                //send the num of cabs the client will get.
                server.sendData(boost::lexical_cast<string>(serCabs.size()));
                //initializing the the sercabs list iterator
                list<string>::iterator startC;
                list<string>::iterator endC;
                startC = serCabs.begin();
                endC = serCabs.end();
                while (endC != startC) {
                    string str = *startC;
                    server.sendData(str);
                    //advancing the cab's list iterator by one step
                    std::advance(startC, 1);
                }
                break;
            }
            //create a trip
            case 2: {
                int startX;
                int startY;
                int endX;
                int endY;
                int numOfPassenger;
                int timeOfStart;
                double tariff;
                cin >> id >> dummy >> startX >> dummy >> startY >> dummy
                    >> endX >> dummy >> endY >> dummy >> numOfPassenger >> dummy >> tariff >> dummy >> timeOfStart;
                trips.push_back(new Trip(id, Point(startX, startY), Point(endX, endY),
                                         numOfPassenger, tariff, timeOfStart));
                cout << "\ntrip created and pushed";
                break;
            }
            //create a cab
            case 3: {
                int typeOfCab;
                char manufacturer;
                char color;
                cin >> id >> dummy >> typeOfCab >> dummy >> manufacturer >> dummy >> color;
                string str = boost::lexical_cast<string>(id) + "," + boost::lexical_cast<string>(typeOfCab)
                             + "," + manufacturer + "," + color;
                cout << "\ncreated the string:" << str;
                serCabs.push_back(str);
                if (typeOfCab == 1) {
                    StandardCab *cab = new StandardCab(id, typeOfCab, manufacturer, color);
                    cab->setLocation(Point(0,0));
                    cabs.push_back(cab);
                } else {
                    LuxuryCab *cab = new LuxuryCab(id, typeOfCab, manufacturer, color);
                    cab->setLocation(Point(0,0));
                    cabs.push_back(cab);
                }
                break;
            }
            //getting the location of a driver
            case 4: {
                cin >> id;
                list<Driver *>::iterator start;
                list<Driver *>::iterator end;
                start = drivers.begin();
                end = drivers.end();
                while (start != end) {
                    Driver *d = *start;
                    if (id == d->getId()) {
                        d->getDriverLocation();
                        break;
                    }
                    start++;
                }
                break;
            }
            //all drivers are driving
            case 6: {
                list<Cab*>::iterator cabsIteratorStart = cabs.begin();
                list<Cab*>::iterator cabsIteratorEnd = cabs.end();
                while (cabsIteratorStart != cabsIteratorEnd) {
                    (*cabsIteratorStart)->drive();
                    (*cabsIteratorStart)->setHasTrip(false);
                    cabsIteratorStart++;
                }
                break;
            }
            case 9: {
                if (!trips.empty()) {
                    tc.assignTripsToDrivers(trips);
                    list<Cab*>::iterator cabsIteratorStart = cabs.begin();
                    list<Cab*>::iterator cabsIteratorEnd = cabs.end();
                    while (cabsIteratorStart != cabsIteratorEnd) {
                        if ((*cabsIteratorStart)->isHasTrip()) {
                            string str = boost::lexical_cast<string>((*cabsIteratorStart)->getId()) + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getRideNum()) + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getStart().getX()) + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getStart().getY()) + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getEnd().getX()) + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getEnd().getY()) + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getNumOfPassengers()) + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getTariff()) + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getTimeOfStart());
                            server.sendData(str);
                        }
                        cabsIteratorStart++;
                    }
                } else {
                    list<Cab*>::iterator cabsIteratorStart = cabs.begin();
                    list<Cab*>::iterator cabsIteratorEnd = cabs.end();
                    while (cabsIteratorStart != cabsIteratorEnd) {
                        if((*cabsIteratorStart)->isHasTrip()) {
                            if ((*cabsIteratorStart)->getTrip()->getTimeOfStart() == time) {
                                (*cabsIteratorStart)->drive();
                                Point newLocation = (*cabsIteratorStart)->getLocation();
                                string str = boost::lexical_cast<string>((*cabsIteratorStart)->getId()) + "," +
                                        boost::lexical_cast<string>(newLocation.getX()) + "," +
                                        boost::lexical_cast<string>(newLocation.getY());
                                server.sendData(str);
                            }
                        }
                        cabsIteratorStart++;
                    }
                }
                time++;
                break;
            }
        }

    } while (choice != 7);
    drivers.clear();
    cabs.clear();
    trips.clear();
    server.~Socket();
    return 0;
}