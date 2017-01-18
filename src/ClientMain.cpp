
#include <iostream>
#include "Driver.h"
#include "StandardCab.h"
#include "LuxuryCab.h"
#include "TaxiCenter.h"
#include "../sockets/Tcp.h"
#include <cstdlib>
#include <boost/lexical_cast.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    Tcp client(0, atoi(argv[2]));
    client.initialize();
    //client.sendData("im connected, bitch\n", 0);
    std::list <Driver*> drivers;
    std::list <Cab*> cabs;
    //std::list <Trip*> trips;
    TaxiCenter tc = TaxiCenter(&drivers, &cabs);
    char buffer[1024];
    //using for managing case 9
    bool hasANewTrip = true;
    char choice[2];
    do {
        client.receiveData(choice, sizeof(choice), 0);
        //client.sendData("bye", 0);
        switch (choice[0]) {
            //create a driver
            case '1': {
                //client.receiveData(buffer, sizeof(buffer), 0);
                int numOfDrivers = 1/*atoi(buffer)*/;
                int numOfCabs = 1/*atoi(buffer)*/;
                while (numOfDrivers != 0) {
                    char dummy;
                    int id;
                    int age;
                    char status;
                    int exp;
                    int cabId;
                    cin >> id >> dummy >> age >> dummy >> status >> dummy >> exp >> dummy >> cabId;
                    Driver *d = new Driver(id, age, status, exp, cabId);
                    //sending a serialized driver to server
                    string str = boost::lexical_cast<string>(id) + "," + boost::lexical_cast<string>(age) + "," +
                                 status + "," + boost::lexical_cast<string>(exp) + "," +
                                 boost::lexical_cast<string>(cabId);
                    drivers.push_back(d);
                    client.sendData(str, 0);
                    //client.sendData(str);
                    numOfDrivers--;
                }
                //receive the num of cabs he will get

                //int numOfCabs = atoi(buffer);
                while (numOfCabs != 0) {
                    //getting a serialized cab
                    client.receiveData(buffer, sizeof(buffer), 0);
                    char *cab[4];
                    int i = 0;
                    char *split;
                    split = strtok(buffer, ",");
                    while (split != NULL && i < 4) {
                        cab[i] = split;
                        i++;
                        split = strtok(NULL, ",");
                    }
                    //create a cab
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
                //updating that we have a new trip in delivery
            case '2':
                hasANewTrip = true;
                break;
            case '9':
                //checking if there are trips
                if (hasANewTrip) {
                    //getting a trip from server
                    /*client.receiveData(buffer, sizeof(buffer), 0);
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
                    //assigning trip to driver
                    while (cabsIteratorStart != cabsIteratorEnd) {
                        if ((*cabsIteratorStart)->getId() == atoi(trip[0])) {
                            (*cabsIteratorStart)->setTrip(new Trip(atoi(trip[1]), Point(atoi(trip[2]), atoi(trip[3])),
                                                                   Point(atoi(trip[4]), atoi(trip[5])), atoi(trip[6]),
                                                                   atof(trip[7]), atoi(trip[8])));
                            (*cabsIteratorStart)->setHasTrip(true);
                        }
                        cabsIteratorStart++;
                    }*/
                    //now we took care of the new trip. therefore  we are updating the hasANewTrip to false.
                    hasANewTrip = false;
                    //else we dont have a new trip
                } else {
                    for (int i = 0; i < cabs.size(); ++i) {
                        //client receive a new location of each driver
                        client.receiveData(buffer, sizeof(buffer), 0);
                        char *point[3];
                        int j = 0;
                        char *split;
                        split = strtok(buffer, ",");
                        while (split != NULL && j < 3) {
                            point[j] = split;
                            j++;
                            split = strtok(NULL, ",");
                        }
                        //client.sendData("hi", 0);
                        list<Cab *>::iterator cabsIteratorStart = cabs.begin();
                        list<Cab *>::iterator cabsIteratorEnd = cabs.end();
                        while (cabsIteratorStart != cabsIteratorEnd) {
                            //updating the location for the right cab
                            if ((*cabsIteratorStart)->getId() == atoi(point[0])) {
                                (*cabsIteratorStart)->setLocation(Point(atoi(point[1]), atoi(point[2])));
                                //if a cab finished its trip, we update his status of hasTrip.
                                if ((*cabsIteratorStart)->getTrip()->getEnd() == (*cabsIteratorStart)->getLocation()) {
                                    (*cabsIteratorStart)->setHasTrip(false);
                                }
                            }
                            cabsIteratorStart++;
                        }
                    }
                }
                break;
            default:
                break;
        }
    } while (choice[0] != '7');
    drivers.clear();
    cabs.clear();
    //trips.clear();
    return 0;
}


