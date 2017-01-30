
#include <iostream>
#include "src/Driver.h"
#include "src/StandardCab.h"
#include "src/LuxuryCab.h"
#include "src/TaxiCenter.h"
#include "sockets/Tcp.h"
#include "src/Checker.h"
#include <boost/lexical_cast.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    Tcp client(0, atoi(argv[2]));
    std::list <Driver*> drivers;
    std::list <Cab*> cabs;
    TaxiCenter tc = TaxiCenter(&drivers, &cabs);
    char buffer[4096];
    //using for managing case 9
    bool hasANewTrip = true;
    //using to know when the client is initialized
    bool clientInitialized = false;
    char choice[2];
    choice[0] = '1';
    do {
        //client is initialized after we see that the input is valid, and then he can receive data.
        if(clientInitialized) {
            client.receiveData(choice, sizeof(choice), 0);
        }
        switch (choice[0]) {
        //create a driver
        case '1': {
            int numOfDrivers = 1;
            int numOfCabs = 1;
            //getting input of driver
            while (numOfDrivers != 0) {
                string stringDriver;
                getline(cin,stringDriver);
                //checking the length of a driver input, otherwise, we close the client.
                if (std::count(stringDriver.begin(),stringDriver.end(),',') != 4) {
                    exit(0);
                }
                char *input[5];
                int i = 0;
                char *split;
                char *stringDriverConvert = (char *) stringDriver.c_str();
                split = strtok(stringDriverConvert, ",");
                while (split != NULL && i < 5) {
                    input[i] = split;
                    i++;
                    split = strtok(NULL, ",");
                }
                Checker checker;
                //checking if the input is valid, otherwise, we close the client.
                if (!checker.CheckClientDriver(input)) {
                    exit(0);
                }
                int id = atoi(input[0]);
                int age = atoi(input[1]);
                char status = *input[2];
                int exp =  atoi(input[3]);
                int cabId =  atoi(input[4]);
                Driver *d = new Driver(id, age, status, exp, cabId);
                //sending a serialized driver to server
                string str = boost::lexical_cast<string>(id) + "," + boost::lexical_cast<string>(age) + "," +
                             status + "," + boost::lexical_cast<string>(exp) + "," +
                             boost::lexical_cast<string>(cabId);
                drivers.push_back(d);
                //client is initialized after we see that the input is valid.
                client.initialize();
                clientInitialized = true;
                client.sendData(str, 0);
                numOfDrivers--;

            }
            //getting the cab of this driver from the server
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
            //assign cab to driver
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
                //now we took care of the new trip. therefore  we are updating the hasANewTrip to false.
                hasANewTrip = false;
                //else we dont have a new trip
            } else {
                client.sendData("a", 0);
                //client receive a new location of each driver
                client.receiveData(buffer, sizeof(buffer), 0);
                //deserialize a location of cab
                char *point[3];
                int j = 0;
                char *split;
                split = strtok(buffer, ",");
                while (split != NULL && j < 3) {
                    point[j] = split;
                    j++;
                    split = strtok(NULL, ",");
                }
                //assign the location to the cab
                list<Cab *>::iterator cabsIteratorStart = cabs.begin();
                list<Cab *>::iterator cabsIteratorEnd = cabs.end();
                while (cabsIteratorStart != cabsIteratorEnd) {
                    //updating the location for the right cab
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
    } while (choice[0] != '7');
    sleep(2);
    drivers.clear();
    cabs.clear();
    return 0;
}


