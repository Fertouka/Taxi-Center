// fertoud 316295005 amitayi 203839030

#include <iostream>
#include <cstdlib>
#include <boost/lexical_cast.hpp>
#include "Driver.h"
#include "StandardCab.h"
#include "LuxuryCab.h"
#include "Matrix.h"
#include "TaxiCenter.h"
#include "Tcp.h"
using namespace std;


class ThreadManagement {
public:
    TaxiCenter* tc;
    Tcp *socket;
    ThreadManagement(TaxiCenter* t, Tcp* sock){
        tc = t;
        socket = sock;
    }

    ~ThreadManagement();
};

void* connectionManager(void* socketDesc) {
    ThreadManagement* manager = (ThreadManagement*)socketDesc;
    char buffer[4096];
    int clientDescriptor = manager->socket->acceptOneClient();
    //int status = manager->socket->receiveData(){
    //recieving a serialized driver
    manager->socket->.receiveData(buffer, sizeof(buffer), clientDescriptor);
    char *driver[5];
    int i = 0;
    char* split;
    split = strtok(buffer, ",");
    //splitting the string to the relevant values of the driver
    while (split != NULL && i < 5) {
        driver[i] = split;
        i++;
        //splitting the string to the relevant values of the driver
        split = strtok (NULL, ",");
    }
    //creating the driver using the info from the string we recieved from the client
    Driver *d = new Driver(atoi(driver[0]), atoi(driver[1]), *driver[2], atoi(driver[3]), atoi(driver[4]));
    //pushing the driver we created to the drivers list
    manager->tc->addDriver(d);
    //assigning the cabs to the drivers
    manager->tc->.assignCabsToDrivers();
    //send the num of cabs the client will get.
    manager->socket->.sendData(boost::lexical_cast<string>(serCabs.size()), clientDescriptor);
    //initializing the the sercabs list iterator
    list<string>::iterator startC;
    list<string>::iterator endC;
    //initializing the start iterator to point to the start of the serialized cabs list
    startC = serCabs.begin();
    //initializing the end iterator to point to the end of the serialized cabs list
    endC = serCabs.end();
    while (endC != startC) {
        //initializing a string to be the current serialized cab from the list
        string str = *startC;
        //sending to the client the serialized cab
        manager->socket->.sendData(str, clientDescriptor);
        //advancing the cab's list iterator by one step
        std::advance(startC, 1);
    }
    pthread_exit(socketDesc);
}

    void sendChoiceToClients(Tcp* server, int choice,list <int> clientsDescriptors) {
        list <int>::iterator startC;
        list <int>::iterator endC;
        startC = clientsDescriptors.begin();
        //initializing the end iterator to point to the end of the serialized cabs list
        endC = clientsDescriptors.end();
        while (endC != startC) {
            int desc = *startC;
            (*server).sendData(boost::lexical_cast<string>(choice), desc);
            std::advance(startC, 1);
        }
    }

int main(int argc, char *argv[]) {
    Tcp server(1, atoi(argv[1]));
    server.initialize();
    list <pthread_t> threads;
    cout <<"initialized\n";
    char buffer[1024];
    //int clientDescriptor;
    //clientDescriptor = server.acceptOneClient();
    //server.receiveData(buffer, sizeof(buffer), clientDescriptor);
    //cout << buffer;
    //dummy for signs we ignore in the input
    list <int> clientDescriptors;
    char dummy;
    //in this line we creating the grid
    Grid *grid;
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
        grid =new Matrix(size[0], size[1], obstacles);
    } else {
        //creating a grid without obstacles
        grid = new Matrix(size[0], size[1]);
    }
    std::list <Driver*> drivers;
    std::list <Trip*> trips;
    std::list <Cab*> cabs;
    std::list <string> serCabs;
    int id;
    //choice of the user
    int choice;
    int time = 0;
    //creating the taxi center of the server
    TaxiCenter tc = TaxiCenter(&drivers, &cabs, grid);
    int numOfDrivers;
    //menu for the user
    do {
        //receiving an operation from the user
        cin >> choice;
        switch (choice) {
            //create a driver
            case 1: {
                sendChoiceToClients(&server, choice, clientDescriptors);
                //int clientDescriptor = server.acceptOneClient();
                //sending to the client the operation
                //server.sendData(boost::lexical_cast<string>(choice), clientDescriptor);

                //recieving from the user how many drivers he wants
                cin >> numOfDrivers;
                for(int i = 0; i < numOfDrivers; i++) {
                    pthread_t thread;
                    ThreadManagement* manager = new ThreadManagement(&tc, &server);
                    int clientDescriptor = server.acceptOneClient();
                    clientDescriptors.push_back(clientDescriptor);
                    pthread_create(&thread, NULL, connectionManager, manager);
                    //threads.push_back(thread);

                }

                //sending to the client the number of drivers
                //server.sendData(boost::lexical_cast<string>(numOfDrivers), clientDescriptor);
                //we are creating the drivers from the serialized drivers that the server recieves from the client
                /*while (numOfDrivers != 0) {
                    char buffer[1024];
                    //recieving a serialized driver
                    server.receiveData(buffer, sizeof(buffer), clientDescriptor);
                    char *driver[5];
                    int i = 0;
                    char* split;
                    split = strtok(buffer, ",");
                    //splitting the string to the relevant values of the driver
                    while (split != NULL && i < 5) {
                        driver[i] = split;
                        i++;
                        //splitting the string to the relevant values of the driver
                        split = strtok (NULL, ",");
                    }
                    //creating the driver using the info from the string we recieved from the client
                    Driver *d = new Driver(atoi(driver[0]), atoi(driver[1]),
                                           *driver[2], atoi(driver[3]), atoi(driver[4]));
                    //pushing the driver we created to the drivers list
                    drivers.push_back(d);
                    //assigning the cabs to the drivers
                    tc.assignCabsToDrivers();
                    //decreasing the number of driveres we should create
                    numOfDrivers--;
                }
                //send the num of cabs the client will get.
                server.sendData(boost::lexical_cast<string>(serCabs.size()), clientDescriptor);
                //initializing the the sercabs list iterator
                list<string>::iterator startC;
                list<string>::iterator endC;
                //initializing the start iterator to point to the start of the serialized cabs list
                startC = serCabs.begin();
                //initializing the end iterator to point to the end of the serialized cabs list
                endC = serCabs.end();
                while (endC != startC) {
                    //initializing a string to be the current serialized cab from the list
                    string str = *startC;
                    //sending to the client the serialized cab
                    server.sendData(str, clientDescriptor);
                    //advancing the cab's list iterator by one step
                    std::advance(startC, 1);
                }*/
                break;
            }
            //create a trip
            case 2: {
                //sending the client that option 2 was chosen
                sendChoiceToClients(&server, choice, clientDescriptors);
                //server.sendData(boost::lexical_cast<string>(choice), clientDescriptor);
                int startX;
                int startY;
                int endX;
                int endY;
                int numOfPassenger;
                int timeOfStart;
                double tariff;
                cin >> id >> dummy >> startX >> dummy >> startY >> dummy
                    >> endX >> dummy >> endY >> dummy >> numOfPassenger >> dummy >> tariff >> dummy >> timeOfStart;
                //creating and pushing the trip to the trips list
                trips.push_back(new Trip(id, Point(startX, startY), Point(endX, endY),
                                         numOfPassenger, tariff, timeOfStart));
                break;
            }
            //create a cab
            case 3: {
                int typeOfCab;
                char manufacturer;
                char color;
                cin >> id >> dummy >> typeOfCab >> dummy >> manufacturer >> dummy >> color;
                //creating a serialized cab string from the users input
                string str = boost::lexical_cast<string>(id) + "," + boost::lexical_cast<string>(typeOfCab)
                             + "," + manufacturer + "," + color;
                //pushing the serialized cab to the serialized cabs list
                serCabs.push_back(str);
                //checking if the type of the cab is standard cab
                if (typeOfCab == 1) {
                    //creating a standard cab from the user's input
                    StandardCab *cab = new StandardCab(id, typeOfCab, manufacturer, color);
                    cab->setLocation(Point(0,0));
                    //pushing the cab to the list
                    cabs.push_back(cab);
                } else {
                    //creating a luxury cab from the user's input
                    LuxuryCab *cab = new LuxuryCab(id, typeOfCab, manufacturer, color);
                    cab->setLocation(Point(0,0));
                    //pushing the cab to ther cabs list
                    cabs.push_back(cab);
                }
                break;
            }
            //getting the location of a driver
            case 4: {
                cin >> id;
                //creating and initializing iterator for the drivers list
                list<Driver *>::iterator start;
                list<Driver *>::iterator end;
                start = drivers.begin();
                end = drivers.end();
                //here we start iterating on the drivers list
                while (start != end) {
                    Driver *d = *start;
                    //comparing the current driver's id to the recieved id
                    if (id == d->getId()) {
                        //the id's are equal-> we are getting the current drivers position
                        d->getDriverLocation();
                        break;
                    }
                    //advancing the iterator
                    start++;
                }
                break;
            }
            //all drivers are driving
            case 6: {
                //creating and initializing the cabs list iterator
                list<Cab*>::iterator cabsIteratorStart = cabs.begin();
                list<Cab*>::iterator cabsIteratorEnd = cabs.end();
                //moving on the cabs list
                while (cabsIteratorStart != cabsIteratorEnd) {
                    //"telling" the current cab to drive
                    (*cabsIteratorStart)->drive();
                    //setting that the current cab has no trip
                    (*cabsIteratorStart)->setHasTrip(false);
                    //advancing the iterator
                    cabsIteratorStart++;
                }
                break;
            }
            //advancing the clock and the cabs by one step (if it's the time to advance them)
            case 9: {
                //sending the client that option 9 was chosen
                sendChoiceToClients(&server, choice, clientDescriptors);
                //server.sendData(boost::lexical_cast<string>(choice), clientDescriptor);
                //checking if there are trips
                if (!trips.empty()) {
                    //assigning the trips to the drivers
                    tc.assignTripsToDrivers(trips);
                    //creating and initializing the cabs list iterator
                    list<Cab*>::iterator cabsIteratorStart = cabs.begin();
                    list<Cab*>::iterator cabsIteratorEnd = cabs.end();
                    //moving on the cabs list
                    while (cabsIteratorStart != cabsIteratorEnd) {
                        //checking if the current cab has trip
                        if ((*cabsIteratorStart)->isHasTrip()) {
                            //serializing the trip of the cab
                            string str = boost::lexical_cast<string>((*cabsIteratorStart)->getId()) + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getRideNum()) + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getStart().getX())
                                         + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getStart().getY())
                                         + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getEnd().getX())
                                         + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getEnd().getY())
                                         + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getNumOfPassengers())
                                         + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getTariff()) + "," +
                                    boost::lexical_cast<string>((*cabsIteratorStart)->getTrip()->getTimeOfStart());
                            //sending to the client the serialized trip
                            server.sendData(str, clientDescriptor);
                        }
                        //advancing the iterator
                        cabsIteratorStart++;
                    }
                    //there are no trips
                } else {
                    //cresating and initializing the cab's list iterator
                    list<Cab*>::iterator cabsIteratorStart = cabs.begin();
                    list<Cab*>::iterator cabsIteratorEnd = cabs.end();
                    //moving on the cab's list
                    while (cabsIteratorStart != cabsIteratorEnd) {
                        //checking if the current cab has a trip
                        if((*cabsIteratorStart)->isHasTrip()) {
                            //checking if now is the time to advance the trip
                            if ((*cabsIteratorStart)->getTrip()->getTimeOfStart() == time) {
                                //advancing the trip
                                (*cabsIteratorStart)->drive();
                            }
                        }
                        //updating the cabs new location
                        Point newLocation = (*cabsIteratorStart)->getLocation();
                        //serializing the cab's new location'
                        string str = boost::lexical_cast<string>((*cabsIteratorStart)->getId())
                                     + "," + boost::lexical_cast<string>(newLocation.getX()) + "," +
                                     boost::lexical_cast<string>(newLocation.getY());
                        //sending to the client the cab's new location
                        server.sendData(str, clientDescriptor);
                        //advancing the iterator
                        cabsIteratorStart++;
                    }
                }
                //advancig the time
                time++;
                break;
            }
            default:
                break;
        }

    } while (choice != 7);
    //tell to client to get close
    sendChoiceToClients(&server, choice, clientDescriptors);
    //server.sendData(boost::lexical_cast<string>(choice), clientDescriptor);
    drivers.clear();
    cabs.clear();
    trips.clear();
    return 0;
}


