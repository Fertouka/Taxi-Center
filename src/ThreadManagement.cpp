//
// Created by della on 26/01/17.
//

#include "ThreadManagement.h"

ThreadManagement::ThreadManagement(TaxiCenter* t, Tcp* sock , int clientDesc,
        list <string> *sercabs, list <string> *serLocations){
        tc = t;
        socket = sock;
        clientDescriptor = clientDesc;
        serCabs = sercabs;
        serLocation = serLocations;
}