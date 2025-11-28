#pragma once
#include "../pch.h"

class Vehicle{
    private:
        int vehicleId_;
        string licensePlate_;
        string vehicleType_;
        bool isAvailable_;
    public:
        Vehicle(int vehicleId, const string& licensePlate, const string& vehicleType);

        int getVehicleId() const { return vehicleId_; }
        string getLicensePlate() const { return licensePlate_; }
        string getVehicleType() const { return vehicleType_; }
        bool getIsAvailable() const { return isAvailable_; }

        void setIsAvailable(bool available) { isAvailable_ = available; }

        void print() const;
};


