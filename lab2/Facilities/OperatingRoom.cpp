#include "OperatingRoom.h"

OperatingRoom::OperatingRoom(const string& roomNumber, Department* department, int roomSize,
                            bool hasVentilation)
    : roomNumber_(roomNumber), department_(department), isAvailable_(true),
      equipmentList_(""), roomSize_(roomSize), hasVentilation_(hasVentilation) {}

void OperatingRoom::reserveRoom() {
    isAvailable_ = false;
    cout << "Operating Room " << roomNumber_ << " reserved" << endl;
}

void OperatingRoom::releaseRoom() {
    isAvailable_ = true;
    cout << "Operating Room " << roomNumber_ << " released" << endl;
}

void OperatingRoom::print() const {
    cout << "=== Operating Room " << roomNumber_ << " ===" << endl;
    if (department_) {
        cout << "Department: " << department_->getName() << endl;
    }
    cout << "Status: " << (isAvailable_ ? "Available" : "Occupied") << endl;
    cout << "Room Size: " << roomSize_ << " sqm" << endl;
    cout << "Ventilation: " << (hasVentilation_ ? "Yes" : "No") << endl;
    if (!equipmentList_.empty())
        cout << "Equipment: " << equipmentList_ << endl;
}



