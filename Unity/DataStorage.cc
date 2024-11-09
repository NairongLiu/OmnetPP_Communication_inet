#include "DataStorage.h"
#include <iostream>
#include <sstream>

std::unordered_map<int, std::tuple<double, double, double>> DataStorage::positionMap;

const std::string DataStorage::SHARED_MEMORY_RECEIVE_NAME = "Omnetpp_MobilityReceive";

SharedMemoryReceiver DataStorage::sharedMemoryReceive(DataStorage::SHARED_MEMORY_RECEIVE_NAME);

void DataStorage::receiveDataFromSharedMemory() {
    std::string memoryData = sharedMemoryReceive.readData();
    std::istringstream stream(memoryData);
    std::string line;

    int id;
    double x, y, z;

    while (std::getline(stream, line)) {
        std::istringstream lineStream(line);
        if (lineStream >> id && lineStream.get() == ':' && lineStream >> x >> y >> z) {
            positionMap[id] = std::make_tuple(x, y, z);
        } else {
            std::cerr << "Wrong format: " << line << std::endl;
        }
    }
}

std::tuple<double, double, double>* DataStorage::getPositionById(int id) {
    auto it = positionMap.find(id);
    if (it != positionMap.end()) {
        return &it->second;
    }
    return nullptr;
}
