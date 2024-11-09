#include "DataStorage.h"
#include "MobilityHandler.h"

namespace inet {

Define_Module(MobilityHandler);

void MobilityHandler::initialize() {
    timer = new omnetpp::cMessage("PositionReadTimer");

    scheduleAt(omnetpp::simTime() + 0.1, timer);
}

MobilityHandler::~MobilityHandler() {
    if (timer) {
        cancelAndDelete(timer);
        timer = nullptr;
    }
}

void MobilityHandler::handleMessage(omnetpp::cMessage *msg) {
    if (msg == timer) {
        //sendAllData();

        //readData();

        receiveData();

        scheduleAt(omnetpp::simTime() + 0.1, timer);
    }
}

void MobilityHandler::receiveData() {
    DataStorage::receiveDataFromSharedMemory();
}


void MobilityHandler::finish() {
}

}
