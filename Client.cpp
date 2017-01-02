
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
    Udp client(0, atoi(argv[2]));
    client.initialize();
    //lists for managing the information we get from the server
    std::list <Driver*> drivers;
    std::list <Cab*> cabs;
    std::list <Trip*> trips;
    //copy of the taxi center in the server without the ability for managing it
    TaxiCenter tc = TaxiCenter(&drivers, &cabs);
    //buffer for receiving data from the server
    char buffer[1024];
    //the choice the client should do according to the server
    char choice[2];
    do {
        //receive a choice from the server
        client.reciveData(choice, sizeof(choice));
        switch (choice[0]) {
            //create drivers and sent them to server
            case '1': {
                //receive a choice from the server
                client.reciveData(buffer, sizeof(buffer));
                //the num of drivers the client should send
                int numOfDrivers = atoi(buffer);
                //getting drivers as input and serializing them
                while (numOfDrivers != 0) {
                    //creating a driver
                    char dummy;
                    int id;
                    int age;
                    char status;
                    int exp;
                    int cabId;
                    cin >> id >> dummy >> age >> dummy >> status >> dummy >> exp >> dummy >> cabId;
                    Driver *d = new Driver(id, age, status, exp, cabId);
                    //serialize driver
                    string str = boost::lexical_cast<string>(id) + "," + boost::lexical_cast<string>(age) + "," +
                                 status + "," + boost::lexical_cast<string>(exp) + "," +
                                 boost::lexical_cast<string>(cabId);
                    drivers.push_back(d);
                    //send a driver to the server
                    client.sendData(str);
                    numOfDrivers--;
                }
                //receive the num of cabs he will get
                client.reciveData(buffer, sizeof(buffer));
                int numOfCabs = atoi(buffer);
                //getting cabs and deserializing them
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
                    //creating a cab
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
                //assign cabs to drivers
                tc.assignCabsToDrivers();
                break;
            }
                //getting the location of a driver
            case '4':
                break;
                //all drivers are driving
            case '6':
                break;
            //assign trips to drivers and advance them
            case '9':
                //assign trips to drivers
                if (trips.empty()) {
                    //receive a choice from the server
                    client.reciveData(buffer, sizeof(buffer));
                    char *trip[9];
                    int i = 0;
                    char *split;
                    split = strtok(buffer, ",");
                    //desrializing trips
                    while (split != NULL && i < 9) {
                        trip[i] = split;
                        i++;
                        split = strtok(NULL, ",");
                    }
                    list<Cab *>::iterator cabsIteratorStart = cabs.begin();
                    list<Cab *>::iterator cabsIteratorEnd = cabs.end();
                    //assign trips to cabs
                    while (cabsIteratorStart != cabsIteratorEnd) {
                        if ((*cabsIteratorStart)->getId() == atoi(trip[0])) {
                            (*cabsIteratorStart)->setTrip(new Trip(atoi(trip[1]), Point(atoi(trip[2]), atoi(trip[3])),
                                                                   Point(atoi(trip[4]), atoi(trip[5])), atoi(trip[6]),
                                                                   atof(trip[7]), atoi(trip[8])));
                            (*cabsIteratorStart)->setHasTrip(true);
                        }
                        cabsIteratorStart++;
                    }
                    //we advance drivers in their trips
                } else {
                    //receive a new location
                    client.reciveData(buffer, sizeof(buffer));
                    //desrialize a new location of driver
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
                    //update the location of the cabs after advance
                    while (cabsIteratorStart != cabsIteratorEnd) {
                        if ((*cabsIteratorStart)->getId() == atoi(point[0])) {
                            (*cabsIteratorStart)->setLocation(Point(atoi(point[1]), atoi(point[2])));
                        }
                        cabsIteratorStart++;
                    }
                }
                break;
            default:
                break;
        }
        //'7' should end the communication between the client and the server
    } while (choice[0] != '7');
    //clearing all the data
    drivers.clear();
    cabs.clear();
    trips.clear();
    //client.~Socket();
    return 0;
}