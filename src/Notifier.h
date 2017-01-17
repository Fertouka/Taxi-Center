// fertoud 316295005 amitayi 203839030

#ifndef EX2TESTS_NOTIFIER_H
#define EX2TESTS_NOTIFIER_H

#include <iostream>
#include <list>
#include "Listener.h"
using namespace std;

class Notifier {
public:
/**
 * function that adds a listener to the list of listeners
 * @param listener - the listener to add
 */
    virtual void addListener(Listener* listener) = 0;

/**
 * function that removes a listener from the listeners list
 * @param listener - the listener to remove
 */
    virtual void removeListener(Listener* listener) = 0;

/**
 * the call notifier
 */
    virtual void notifyCall() = 0;
};


#endif //EX2TESTS_NOTIFIER_H
