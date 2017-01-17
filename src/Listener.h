// fertoud 316295005 amitayi 203839030

#ifndef EX2TESTS_LISTENER_H
#define EX2TESTS_LISTENER_H


class Listener {
public:
    /**
     * when ocurred an event of passenger's call, the taxi center send a taxi for the passenger
     */
    virtual void event() = 0;
};


#endif //EX2TESTS_LISTENER_H
