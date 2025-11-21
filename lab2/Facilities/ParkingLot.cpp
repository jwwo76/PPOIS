#include "ParkingLot.h"

ParkingLot::ParkingLot(const string& lotId, int totalSpots, bool isCovered, double hourlyRate)
    : lotId_(lotId), totalSpots_(totalSpots), occupiedSpots_(0),
      isCovered_(isCovered), hourlyRate_(hourlyRate) {}

void ParkingLot::parkVehicle() {
    if (hasAvailableSpots()) {
        occupiedSpots_++;
        cout << "Vehicle parked. Spots available: " << getAvailableSpots() << endl;
    } else {
        cout << "Parking lot is full" << endl;
    }
}

void ParkingLot::releaseSpot() {
    if (occupiedSpots_ > 0) {
        occupiedSpots_--;
        cout << "Spot released. Spots available: " << getAvailableSpots() << endl;
    }
}

bool ParkingLot::hasAvailableSpots() const {
    return occupiedSpots_ < totalSpots_;
}

void ParkingLot::print() const {
    cout << "=== Parking Lot " << lotId_ << " ===" << endl;
    cout << "Total Spots: " << totalSpots_ << endl;
    cout << "Occupied: " << occupiedSpots_ << endl;
    cout << "Available: " << getAvailableSpots() << endl;
    cout << "Covered: " << (isCovered_ ? "Yes" : "No") << endl;
    if (hourlyRate_ > 0)
        cout << "Hourly Rate: $" << hourlyRate_ << endl;
}



