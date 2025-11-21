#pragma once
#include "../pch.h"

class Ambulance {
private:
    string vehicleId_;
    string driverName_;
    bool isAvailable_;
    string currentLocation_;
    int capacity_;

public:
    Ambulance(const string& vehicleId, const string& driverName, int capacity = 2);
    
    string getVehicleId() const { return vehicleId_; }
    string getDriverName() const { return driverName_; }
    bool getIsAvailable() const { return isAvailable_; }
    string getCurrentLocation() const { return currentLocation_; }
    int getCapacity() const { return capacity_; }

    void setVehicleId(const string& id) { vehicleId_ = id; }
    void setDriverName(const string& name) { driverName_ = name; }
    void setCurrentLocation(const string& location) { currentLocation_ = location; }
    void setCapacity(int capacity) { if(capacity > 0) capacity_ = capacity; }

    void dispatch(const string& destination);
    void returnToStation();
    void print() const;
};



