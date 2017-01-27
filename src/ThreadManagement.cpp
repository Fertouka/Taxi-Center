//
// Created by della on 26/01/17.
//

#include "ThreadManagement.h"


ThreadManagement::ThreadManagement(TaxiCenter *tc, Tcp *socket, int clientDescriptor, list <string> *serCabs,
                                   list <string> *serLocation) : tc(tc), socket(socket),
                                                                 clientDescriptor(clientDescriptor), serCabs(serCabs),
                                                                 serLocation(serLocation) {}
