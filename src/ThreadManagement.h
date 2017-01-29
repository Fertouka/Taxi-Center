//
// Created by della on 26/01/17.
//

#ifndef EX2TESTS_THREADMANAGEMENT_H
#define EX2TESTS_THREADMANAGEMENT_H

#include "TaxiCenter.h"
#include "../sockets/Tcp.h"

/**
 * class that hold the arguments that thread need to his job
 */
class ThreadManagement {
public:
    TaxiCenter* tc;
    Tcp *socket;
    int clientDescriptor;
    list <string> *serCabs;
    list <string> *serLocation;

/**
 * ThreadManagement constructor
 * @param tc taxi center
 * @param socket
 * @param clientDescriptor
 * @param serCabs list of serialized cabs
 * @param serLocation list of serialized locations
 */
    ThreadManagement(TaxiCenter *tc, Tcp *socket, int clientDescriptor, list <string> *serCabs,
                     list <string> *serLocation);

/**
 * ThreadManagement destructor
 */
    ~ThreadManagement();
};
#endif //EX2TESTS_THREADMANAGEMENT_H
