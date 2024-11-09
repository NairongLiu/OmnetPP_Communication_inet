#ifndef MOBILITYHANDLER_H
#define MOBILITYHANDLER_H

#include "MobilityHandler.h"

#include <omnetpp.h>


namespace inet {

class MobilityHandler : public omnetpp::cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(omnetpp::cMessage *msg) override;
    virtual void finish() override;
    virtual ~MobilityHandler();

private:
    omnetpp::cMessage *timer;

    //void sendAllData();
    //void readData();
    void receiveData();
};
}
#endif
