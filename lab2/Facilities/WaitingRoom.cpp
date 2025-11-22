#include "WaitingRoom.h"
#include "../Exceptions/Exceptions.h"

WaitingRoom::WaitingRoom(const string& roomNumber, Department* department, int capacity,
                        bool hasAirConditioning, bool hasTelevision)
    : roomNumber_(roomNumber), department_(department), capacity_(capacity),
      hasAirConditioning_(hasAirConditioning), hasTelevision_(hasTelevision) {
    if (capacity <= 0) {
        Exceptions::throwInvalidArgument("Capacity must be positive");
    }
}

void WaitingRoom::addPatient(Patient* patient) {
    if (!patient) {
        Exceptions::throwInvalidArgument("Patient cannot be null");
    }
    if (isFull()) {
        Exceptions::throwCapacityExceeded("Waiting room is at full capacity");
    }
    patients_.push_back(patient);
}
void WaitingRoom::removePatient(Patient* patient) {
    auto it = remove(patients_.begin(), patients_.end(), patient);
    patients_.erase(it, patients_.end());
}

bool WaitingRoom::isFull() const {
    return patients_.size() >= capacity_;
}

void WaitingRoom::print() const {
    cout << "=== Waiting Room " << roomNumber_ << " ===" << endl;
    if (department_) {
        cout << "Department: " << department_->getName() << endl;
    }
    cout << "Capacity: " << capacity_ << endl;
    cout << "Current Patients: " << patients_.size() << endl;
    cout << "Air Conditioning: " << (hasAirConditioning_ ? "Yes" : "No") << endl;
    cout << "Television: " << (hasTelevision_ ? "Yes" : "No") << endl;
}



