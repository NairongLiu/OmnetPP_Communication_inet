#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <map>
#include <string>
#include <unordered_map>
#include <tuple>
//#include "SharedMemorySender.h"
#include "SharedMemoryReceiver.h"

class DataStorage {
public:
    //static void setData(const std::string& key, const std::string& value);
    //static std::string getData(const std::string& key);
    static std::string readMemory();
    //static void sendAllDataToSharedMemory();
    static void receiveDataFromSharedMemory();
    //static std::string getReceivedData(const std::string& key);
    static std::tuple<double, double, double>* getPositionById(int id);

private:
    //static std::map<std::string, std::string> dataStore;
    //static std::map<std::string, std::string> receivedDataStore;
    static std::unordered_map<int, std::tuple<double, double, double>> positionMap;
    //static const std::string SHARED_MEMORY_SEND_NAME;
    static const std::string SHARED_MEMORY_RECEIVE_NAME;


    //static SharedMemorySender sharedMemorySend;
    static SharedMemoryReceiver sharedMemoryReceive;
};

#endif
