#include "Vehicle.h"
#include "../Exceptions/Exceptions.h"

Vehicle::Vehicle(int vehicleId, const string& licensePlate, const string& vehicleType)
    : vehicleId_(vehicleId), licensePlate_(licensePlate), vehicleType_(vehicleType), isAvailable_(true) {
    if (vehicleId <= 0) {
        Exceptions::throwInvalidArgument("Vehicle ID должен быть положительным");
    }
    if (licensePlate.empty()) {
        Exceptions::throwInvalidArgument("Номерной знак не может быть пустым");
    }
    if (vehicleType.empty()) {
        Exceptions::throwInvalidArgument("Тип транспорта не может быть пустым");
    }
}

void Vehicle::print() const {
    cout << "Vehicle ID: " << vehicleId_ << endl;
    cout << "License Plate: " << licensePlate_ << endl;
    cout << "Type: " << vehicleType_ << endl;
    cout << "Available: " << (isAvailable_ ? "Yes" : "No") << endl;
}


