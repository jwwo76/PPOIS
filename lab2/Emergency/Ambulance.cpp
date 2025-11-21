#include "Ambulance.h"

Ambulance::Ambulance(const string& vehicleId, const string& driverName, int capacity)
    : vehicleId_(vehicleId), driverName_(driverName), isAvailable_(true),
      currentLocation_("Station"), capacity_(capacity) {}

void Ambulance::dispatch(const string& destination) {
    isAvailable_ = false;
    currentLocation_ = destination;
    cout << "Ambulance " << vehicleId_ << " dispatched to " << destination << endl;
}

void Ambulance::returnToStation() {
    isAvailable_ = true;
    currentLocation_ = "Station";
    cout << "Ambulance " << vehicleId_ << " returned to station" << endl;
}

void Ambulance::print() const {
    cout << "=== Ambulance ===" << endl;
    cout << "Vehicle ID: " << vehicleId_ << endl;
    cout << "Driver: " << driverName_ << endl;
    cout << "Status: " << (isAvailable_ ? "Available" : "On Call") << endl;
    cout << "Current Location: " << currentLocation_ << endl;
    cout << "Capacity: " << capacity_ << endl;
}



