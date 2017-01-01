#include <iostream>
#include "Udp.h"
#include "Driver.h"
#include "StandardCab.h"
#include "LuxuryCab.h"
#include "TaxiCenter.h"
#include <cstdlib>
#include <boost/lexical_cast.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    Udp client(0, atoi(argv[1]));
    client.initialize();
    std::list <Driver*> drivers;
    std::list <Cab*> cabs;
    std::list <Trip*> trips;
    TaxiCenter tc = TaxiCenter(&drivers, &cabs);
    char buffer[1024];
    char choice[2];
    do {
        client.reciveData(choice, sizeof(choice));
        switch (choice[0]) {
            //create a driver
            case '1': {
                cout << 1;
                client.reciveData(buffer, sizeof(buffer));
                int numOfDrivers = atoi(buffer);
                while (numOfDrivers != 0) {
                    char dummy;
                    int id;
                    int age;
                    char status;
                    int exp;
                    int cabId;
                    cin >> id >> dummy >> age >> dummy >> status >> dummy >> exp >> dummy >> cabId;
                    Driver *d = new Driver(id, age, status, exp, cabId);
                    string str = boost::lexical_cast<string>(id) + "," + boost::lexical_cast<string>(age) + "," +
                                 status + "," + boost::lexical_cast<string>(exp) + "," +
                                 boost::lexical_cast<string>(cabId);
                    drivers.push_back(d);
                    client.sendData(str);
                    numOfDrivers--;
                }
                //receive the num of cabs he will get
                client.reciveData(buffer, sizeof(buffer));
                int numOfCabs = atoi(buffer);
                while (numOfCabs != 0) {
                    client.reciveData(buffer, sizeof(buffer));
                    char *cab[4];
                    int i = 0;
                    char *split;
                    split = strtok(buffer, ",");
                    while (split != NULL && i < 4) {
                        cab[i] = split;
                        i++;
                        split = strtok(NULL, ",");
                    }
                    if (*cab[1] == '1') {
                        StandardCab *c = new StandardCab(atoi(cab[0]), atoi(cab[1]), *cab[2], *cab[3]);
                        c->setLocation(Point(0, 0));
                        cabs.push_back(c);
                    } else {
                        LuxuryCab *c = new LuxuryCab(atoi(cab[0]), atoi(cab[1]), *cab[2], *cab[3]);
                        c->setLocation(Point(0, 0));
                        cabs.push_back(c);
                    }
                    numOfCabs--;
                }
                tc.assignCabsToDrivers();
                break;
            }
                //getting the location of a driver
            case '4':
                break;
                //all drivers are driving
            case '6':
                break;
            case '9':
                if (trips.empty()) {
                    client.reciveData(buffer, sizeof(buffer));
                    char *trip[9];
                    int i = 0;
                    char *split;
                    split = strtok(buffer, ",");
                    while (split != NULL && i < 9) {
                        trip[i] = split;
                        i++;
                        split = strtok(NULL, ",");
                    }
                    list<Cab *>::iterator cabsIteratorStart = cabs.begin();
                    list<Cab *>::iterator cabsIteratorEnd = cabs.end();
                    while (cabsIteratorStart != cabsIteratorEnd) {
                        if ((*cabsIteratorStart)->getId() == atoi(trip[0])) {
                            (*cabsIteratorStart)->setTrip(new Trip(atoi(trip[1]), Point(atoi(trip[2]), atoi(trip[3])),
                                                                   Point(atoi(trip[4]), atoi(trip[5])), atoi(trip[6]),
                                                                   atof(trip[7]), atoi(trip[8])));
                        }
                        cabsIteratorStart++;
                    }
                } else {
                    client.reciveData(buffer, sizeof(buffer));
                    char *point[3];
                    int i = 0;
                    char *split;
                    split = strtok(buffer, ",");
                    while (split != NULL && i < 3) {
                        point[i] = split;
                        i++;
                        split = strtok(NULL, ",");
                    }
                    list<Cab *>::iterator cabsIteratorStart = cabs.begin();
                    list<Cab *>::iterator cabsIteratorEnd = cabs.end();
                    while (cabsIteratorStart != cabsIteratorEnd) {
                        if ((*cabsIteratorStart)->getId() == atoi(point[0])) {
                            (*cabsIteratorStart)->setLocation(Point(atoi(point[1]), atoi(point[2])));
                        }
                        cabsIteratorStart++;
                    }
                }
                break;
        }
    } while (choice[0] != '7');
    drivers.clear();
    cabs.clear();
    trips.clear();
    client.~Socket();
    return 0;
}


