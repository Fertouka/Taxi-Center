// fertoud 316295005 amitayi 203839030
#include <iostream>
#include "Driver.h"
#include "StandardCab.h"
#include "LuxuryCab.h"
#include "Grid.h"
#include "Matrix.h"
#include "TaxiCenter.h"
#include "Udp.h"

using namespace std;

int main() {
    std::cout << "Hello, from server" << std::endl;
    Udp server(1, 5555);
    server.initialize();
    char buffer[1024];
    server.reciveData(buffer, sizeof(buffer));
    cout << buffer << endl;
    server.sendData("sup?");
/*

    //dummy for signs we ignore in the input
    char dummy;
    //in this line we creating the grid
    Grid grid;
    //the size of the grid
    int size[2];
    cin >> size[0] >> size[1];
    int numOfObstacles;
    list <Point> obstacles;
    cin >> numOfObstacles;
    //creating a list of obstacles
    if (numOfObstacles != 0) {
        //Point p = Point();
        for (int i = 0; i < numOfObstacles; i++) {
            int x;
            int y;
            cin >> x >> dummy >> y;
            obstacles.push_back(Point(x,y));
        }
        //creating a grid with obstacles
        grid = Matrix(size[0], size[1], obstacles);
    } else {
        //creating a grid without obstacles
        grid = Matrix(size[0], size[1]);
    }
    std::list <Driver*> drivers;
    std::list <Trip*> trips;
    std::list <Cab*> cabs;
    int id;
    //choice of the user
    int choice;
    TaxiCenter tc = TaxiCenter(&drivers, &cabs);
    //menu for the user
    do {
        cin >> choice;
        switch (choice) {
            //create a driver
            case 1: {
                /**int age;
                char status;
                int exp;
                int cabId;
                cin >> id >> dummy >> age >> dummy >> status >> dummy >> exp >> dummy >> cabId;
                Driver *d = new Driver(id, age, status, exp, cabId);
                drivers.push_back(d);
                tc.assignCabsToDrivers();

                int numOfDrivers;
                cin >> numOfDrivers;
                char buffer[1024];
                server.reciveData(buffer, sizeof(buffer));
                break;
            }
            //create a trip
            case 2: {
                int startX;
                int startY;
                int endX;
                int endY;
                int numOfPassenger;
                double tariff;
                cin >> id >> dummy >> startX >> dummy >> startY >> dummy
                    >> endX >> dummy >> endY >> dummy >> numOfPassenger >> dummy >> tariff;
                trips.push_back(new Trip(id, Point(startX, startY), Point(endX, endY), numOfPassenger, tariff));
                break;
            }
            //create a cab
            case 3: {
                int typeOfCab;
                char manufacturer;
                char color;
                cin >> id >> dummy >> typeOfCab >> dummy >> manufacturer >> dummy >> color;
                if (typeOfCab == 1) {
                    StandardCab *cab = new StandardCab(id, manufacturer, color);
                    cab->setLocation(Point(0,0));
                    cabs.push_back( cab);
                } else {
                    LuxuryCab *cab = new LuxuryCab(id, manufacturer, color);
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
                tc.assignTripsToDrivers(trips);
                list<Cab*>::iterator cabsIteratorStart = cabs.begin();
                list<Cab*>::iterator cabsIteratorEnd = cabs.end();
                while (cabsIteratorStart != cabsIteratorEnd) {
                    (*cabsIteratorStart)->drive();
                    (*cabsIteratorStart)->setHasTrip(false);
                    cabsIteratorStart++;
                }
                break;
            }
        }

    } while (choice != 7);
    drivers.clear();
    cabs.clear();
    trips.clear();*/

    return 0;
}