#include "inet/mobility/base/StationaryMobilityBase.h"
#include "inet/common/ModuleAccess.h"

namespace inet {

void StationaryMobilityBase::initialize(int stage)
{
    MobilityBase::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        selfTimer = new cMessage("selfTimer");
        scheduleAt(omnetpp::simTime() + 0.1, selfTimer);
    }
}

void StationaryMobilityBase::handleSelfMessage(cMessage *message)
{
    if (message == selfTimer) {
        if (hasPar("readPositionFile") && par("readPositionFile")) {
            int mobilityNodeId = par("mobilityNodeId");
            std::cout << "mobilityNodeId: " << mobilityNodeId << std::endl;
            auto* position = DataStorage::getPositionById(mobilityNodeId);

            if (position) {
                auto [x, y, z] = *position;
                std::cout << "Position for id " << mobilityNodeId << ": (" << x << ", " << y << ", " << z << ")\n";
                Coord newPosition(x, y, z);
                handlePositionUpdate(newPosition);
            } else {
                std::cout << "No position found for id " << mobilityNodeId << "\n";
            }
        }

        scheduleAt(omnetpp::simTime() + 0.1, selfTimer);
    } else {
        delete message;
    }
}

StationaryMobilityBase::~StationaryMobilityBase() {
    cancelAndDelete(selfTimer);
}

}
