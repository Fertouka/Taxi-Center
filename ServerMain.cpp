// fertoud 316295005 amitayi 203839030

#include <iostream>
#include <boost/lexical_cast.hpp>
#include "src/Driver.h"
#include "src/StandardCab.h"
#include "src/LuxuryCab.h"
#include "src/Matrix.h"
#include "src/TaxiCenter.h"
#include "sockets/Tcp.h"
#include "src/ThreadManagement.h"
#include "src/Checker.h"
#include "src/ThreadPool.h"

using namespace std;

/**
 * global variables
 */
//the choice of the user that the server get
int choice;
//used to know if we can send a location to the driver
bool currentLocationInTripFlag = false;

/**
 * the threads connect to the clients via this function that create a dialog between them
 * @param socketDesc threadmanagement that contain the args that thread need
 */
void* connectClient(void* socketDesc) {
    //manager contains the args that thread need
    ThreadManagement* manager = (ThreadManagement*)socketDesc;
    char buffer[4096];
    //receiving a serialized driver
    manager->socket->receiveData(buffer, sizeof(buffer), manager->clientDescriptor);
    //mutex for deserializing a driver
    pthread_mutex_t driverMutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&driverMutex);
    //deserializing a driver
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
    manager->tc->assignCabsToDrivers();
    pthread_mutex_unlock(&driverMutex);
    //initializing the the sercabs list iterator
    list<string>::iterator startC;
    list<string>::iterator endC;
    //initializing the start iterator to point to the start of the serialized cabs list
    startC = manager->serCabs->begin();
    //initializing the end iterator to point to the end of the serialized cabs list
    endC = manager->serCabs->end();
    while (endC != startC) {
        //initializing a string to be the current serialized cab from the list
        string str = *startC;
        if (d->getCabId() == (str[0] - '0')) {
            //sending to the client the serialized cab
            manager->socket->sendData(str, manager->clientDescriptor);
        }
        //advancing the cab's list iterator by one step
        startC++;
    }
    //loop for the 9 and 7 option
    while (choice != 7) {
        if (choice == 9 && currentLocationInTripFlag) {
            //send 9 to client
            manager->socket->sendData("9", manager->clientDescriptor);
            //getting some message to see that the client and server are communicating
            manager->socket->receiveData(buffer, sizeof(buffer), manager->clientDescriptor);
            //mutex for sending location to client
            pthread_mutex_t locationMutex = PTHREAD_MUTEX_INITIALIZER;
            pthread_mutex_lock(&locationMutex);
            list<string>::iterator startL;
            list<string>::iterator endL;
            //initializing the start iterator to point to the start of the serialized points list
            startL = manager->serLocation->begin();
            //initializing the end iterator to point to the end of the serialized points list
            endL = manager->serLocation->end();
            while (endL != startL) {
                //initializing a string to be the current serialized point from the list
                string str = *startL;
                //if its the right cab, we send her location
                if (d->getCabId() == (str[0] - '0')) {
                    //sending to the client the serialized location
                    manager->socket->sendData(str, manager->clientDescriptor);
                    manager->serLocation->erase(startL);
                    break;
                }
                //advancing the cab's list iterator by one step
                startL++;
            }
            pthread_mutex_unlock(&locationMutex);
        }
    }
    pthread_exit(socketDesc);
}

/**
 * function that calculate the bfs by thread
 * @param socketDesc socketDesc threadmanagement that contain the args that thread need
 */
void* connectBFS(void* socketDesc) {
    ThreadManagement* manager = (ThreadManagement*)socketDesc;
    //assign trip to driver and calculate his bfs
    manager->tc->assignTripToDriver();
}

/**
 * sending a choice to the clients
 * @param server
 * @param sendFlag that tells us if we can send now the choice
 * @param choice
 * @param clientsDescriptors
 */
void sendChoiceToClients(Tcp* server,bool &sendFlag, int choice, list <int> clientsDescriptors) {
    list <int>::iterator startC;
    list <int>::iterator endC;
    startC = clientsDescriptors.begin();
    //initializing the end iterator to point to the end of the serialized cabs list
    endC = clientsDescriptors.end();
    if(sendFlag) {
        while (endC != startC) {
            int desc = *startC;
            (*server).sendData(boost::lexical_cast<string>(choice), desc);
            startC++;
        }
    }
    //to be sure that the clients get the choice before the sever is closed
    sleep(2);
}

int main(int argc, char *argv[]) {
    ThreadPool threadPool(5);
    Checker checker;
    Tcp server(1, atoi(argv[1]));
    server.initialize();
    list <int> clientDescriptors;
    char dummy;
    bool validGridInputFlag;
    bool validObstacle = true;
    //in this line we creating the grid
    Grid *grid = NULL;
    //the size of the grid
    int size[2];
    do {
        validGridInputFlag = true;
        cin >> size[0] >> size[1];
        while (cin.fail() || size[0] <= 0 || size[1] <= 0) {
            cout << -1 << '\n';
            cin.clear();
            cin.ignore(256, '\n');
            cin >> size[0] >> size[1];
        }
        int numOfObstacles;
        list <Point> obstacles;
        cin >> numOfObstacles;
        if (cin.fail() || numOfObstacles < 0) {
            cout << -1 << '\n';
            cin.clear();
            cin.ignore(256, '\n');
            validGridInputFlag = false;
            continue;
        }
        //creating a list of obstacles
        if (numOfObstacles != 0) {
            //Point p = Point();
            for (int i = 0; i < numOfObstacles; i++) {
                int x, y;
                cin >> x >> dummy >> y;
                if (cin.fail() || x <= 0 || y <= 0 || x > size[0] || y > size[1]) {
                    cout << -1 << '\n';
                    validObstacle = false;
                    break;
                }
                obstacles.push_back(Point(x, y));
            }
        } else {
           // validGridInputFlag = false;
            //creating a grid without obstacles
            grid = new Matrix(size[0], size[1]);
        }

        if (validObstacle) {
            //creating a grid with obstacles
            grid = new Matrix(size[0], size[1], obstacles);
        } else {
            validGridInputFlag = false;
        }
    } while (!validGridInputFlag);

    std::list <Driver*> drivers;
    std::list <Trip*> trips;
    std::list <Cab*> cabs;
    std::list <string> serCabs;
    std::list <string> serLocations;
    int id;
    //choice of the user
    int time = 0;
    bool sendFlag = false;
    //creating the taxi center of the server
    TaxiCenter tc = TaxiCenter(&drivers, &cabs, &trips, grid);
    int numOfDrivers;
    //menu for the user
    do {
        //receiving an operation from the user
        cin >> choice;
        switch (choice) {
            //create a driver
            case 1: {
                //recieving from the user how many drivers he wants
                string driversNum;
                char *driversNumConvert;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, driversNum);
                driversNumConvert = (char *) driversNum.c_str();
                if (!isdigit(*driversNumConvert) || atoi(driversNumConvert) <= 0) {
                    cout << "-1\n";
                    cin.clear();
                    break;
                }
                numOfDrivers = atoi(driversNumConvert);
                for (int i = 0; i < numOfDrivers; i++) {
                    pthread_t thread;
                    int clientDescriptor = server.acceptOneClient();
                    ThreadManagement *manager = new ThreadManagement(&tc, &server, clientDescriptor, &serCabs,
                                                                     &serLocations);
                    clientDescriptors.push_back(clientDescriptor);
                    pthread_create(&thread, NULL, connectClient, manager);

                }
                sendFlag = true;
                break;
            }
                //create a trip
            case 2: {
                //sending the client that option 2 was chosen
                sendChoiceToClients(&server, sendFlag, choice, clientDescriptors);
                string tripStr;
                int startX;
                int startY;
                int endX;
                int endY;
                int numOfPassenger;
                int timeOfStart;
                double tariff;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, tripStr);
                if (std::count(tripStr.begin(), tripStr.end(), ',') != 7) {
                    cout << "-1\n";
                    break;
                }
                char *input[8];
                int i = 0;
                char *split;
                char *tripStrConvert = (char *) tripStr.c_str();
                split = strtok(tripStrConvert, ",");
                while (split != NULL && i < 8) {
                    input[i] = split;
                    i++;
                    split = strtok(NULL, ",");
                }

                if (!checker.CheckServerTripInput(grid, input)) {
                    break;
                }
                id = atoi(input[0]);
                startX = atoi(input[1]);
                startY = atoi(input[2]);
                endX = atoi(input[3]);
                endY = atoi(input[4]);
                numOfPassenger = atoi(input[5]);
                timeOfStart = atoi(input[7]);
                tariff = atoi(input[6]);
                trips.push_front(new Trip(id, Point(startX, startY), Point(endX, endY),
                                          numOfPassenger, tariff, timeOfStart));
                break;
            }
                //create a cab
            case 3: {
                int typeOfCab;
                char manufacturer;
                char color;
                string cabString;
                char *input[4];
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, cabString);
                if (std::count(cabString.begin(), cabString.end(), ',') != 3) {
                    cout << "-1\n";
                    break;
                }
                int i = 0;
                char *split;
                char *cabStrConvert = (char *) cabString.c_str();
                split = strtok(cabStrConvert, ",");
                while (split != NULL && i < 4) {
                    input[i] = split;
                    i++;
                    split = strtok(NULL, ",");
                }
                if (!checker.CheckServerCabInput(input)) {
                    cout << "-1\n";
                    break;
                }
                id = atoi(input[0]);
                typeOfCab = atoi(input[1]);
                manufacturer = *input[2];
                color = *input[3];
                //creating a serialized cab string from the users input
                string str = boost::lexical_cast<string>(id) + "," + boost::lexical_cast<string>(typeOfCab)
                             + "," + manufacturer + "," + color;
                //pushing the serialized cab to the serialized cabs list
                serCabs.push_back(str);
                //checking if the type of the cab is standard cab
                if (typeOfCab == 1) {
                    //creating a standard cab from the user's input
                    StandardCab *cab = new StandardCab(id, typeOfCab, manufacturer, color);
                    cab->setLocation(Point(0, 0));
                    //pushing the cab to the list
                    cabs.push_back(cab);
                } else {
                    //creating a luxury cab from the user's input
                    LuxuryCab *cab = new LuxuryCab(id, typeOfCab, manufacturer, color);
                    cab->setLocation(Point(0, 0));
                    //pushing the cab to their cabs list
                    cabs.push_back(cab);
                }
                break;
            }
                //getting the location of a driver
            case 4: {
                string idString;
                char *idStringConvert;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, idString);
                idStringConvert = (char *) idString.c_str();
                while (!checker.isNumber(idStringConvert) || atoi(idStringConvert) < 0) {
                    cout << "-1\n";
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(cin, idString);
                    idStringConvert = (char *) idString.c_str();
                }
                id = atoi(idStringConvert);
                //creating and initializing iterator for the drivers list
                list<Driver *>::iterator start;
                list<Driver *>::iterator end;
                start = drivers.begin();
                end = drivers.end();
                bool isInList = false;
                //here we start iterating on the drivers list
                while (start != end) {
                    Driver *d = *start;
                    //comparing the current driver's id to the recieved id
                    if (id == d->getId()) {
                        //the id's are equal-> we are getting the current drivers position
                        d->getDriverLocation();
                        isInList = true;
                        break;
                    }
                    //advancing the iterator
                    start++;
                }
                if (!isInList) {
                    cout << "-1\n";
                }
                break;
            }
                //all drivers are driving
            case 6: {
                //creating and initializing the cabs list iterator
                list<Cab *>::iterator cabsIteratorStart = cabs.begin();
                list<Cab *>::iterator cabsIteratorEnd = cabs.end();
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
                currentLocationInTripFlag = false;
                //checking if there are trips
                if (!trips.empty()) {
                    //sending the client that option 9 was chosen
                    sendChoiceToClients(&server, sendFlag, choice, clientDescriptors);
                    int size = trips.size();
                    for (int i = 0; i < size; i++) {
                        ThreadManagement *manager = new ThreadManagement(&tc, &server,
                                                                         0, NULL, NULL);
                        threadPool.addJob(new Job(connectBFS, manager));
                        threadPool.ThreadPoolJoin();
                    }
                    //there are no trips
                } else {
                    //cresating and initializing the cab's list iterator
                    list<Cab *>::iterator cabsIteratorStart = cabs.begin();
                    list<Cab *>::iterator cabsIteratorEnd = cabs.end();
                    //moving on the cab's list
                    while (cabsIteratorStart != cabsIteratorEnd) {
                        //checking if the current cab has a trip
                        if ((*cabsIteratorStart)->isHasTrip()) {
                            //checking if now is the time to advance the trip
                            if ((*cabsIteratorStart)->getTrip()->getTimeOfStart() == time) {
                                //advancing the trip
                                (*cabsIteratorStart)->drive();
                            }
                        }
                        //updating the cabs new location
                        Point newLocation = (*cabsIteratorStart)->getLocation();
                        //serializing the cab's new location'
                        serLocations.push_back(boost::lexical_cast<string>((*cabsIteratorStart)->getId())
                                               + "," + boost::lexical_cast<string>(newLocation.getX()) + "," +
                                               boost::lexical_cast<string>(newLocation.getY()));
                        //advancing the iterator
                        cabsIteratorStart++;
                    }
                    currentLocationInTripFlag = true;
                }
                //advancig the time
                time++;
                break;
            }
            default:
                if (choice != 7) {
                cout << -1 << '\n';
        }
                break;
        }
    } while (choice != 7);
    //tell to client to get close
    threadPool.terminate();
    sendChoiceToClients(&server, sendFlag, choice, clientDescriptors);
    drivers.clear();
    cabs.clear();
    trips.clear();
    return 0;
}


