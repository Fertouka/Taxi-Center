#include <iostream>
#include "Udp.h"
#include "Driver.h"
#include <unistd.h>
#include <cstdlib>
#include <boost/lexical_cast.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    cout << argv[1] << endl;
    Udp udp(0, atoi(argv[1]));
    udp.initialize();
    char dummy;
    int id;
    int age;
    char status;
    int exp;
    int cabId;
    cin >> id >> dummy >> age >> dummy >> status >> dummy >> exp >> dummy >> cabId;
    Driver *d = new Driver(id, age, status, exp, cabId);
    string str = boost::lexical_cast<string>(id) + "," + boost::lexical_cast<string>(age) + "," +
            status + "," + boost::lexical_cast<string>(exp) + "," + boost::lexical_cast<string>(cabId);
    char buffer[1024];
    udp.sendData(str);

    udp.reciveData(buffer, sizeof(buffer));
    //cout << buffer << endl;


    return 0;
}


