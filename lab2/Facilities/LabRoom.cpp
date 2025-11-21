#include "LabRoom.h"

LabRoom::LabRoom(const string& roomNumber, const string& labType, int capacity,
                bool hasSafetyEquipment)
    : roomNumber_(roomNumber), labType_(labType), capacity_(capacity),
      hasSafetyEquipment_(hasSafetyEquipment) {}

void LabRoom::addEquipment(const string& equipment) {
    equipment_.push_back(equipment);
}

void LabRoom::removeEquipment(const string& equipment) {
    auto it = remove(equipment_.begin(), equipment_.end(), equipment);
    equipment_.erase(it, equipment_.end());
}

void LabRoom::print() const {
    cout << "=== Lab Room " << roomNumber_ << " ===" << endl;
    cout << "Type: " << labType_ << endl;
    cout << "Capacity: " << capacity_ << endl;
    cout << "Safety Equipment: " << (hasSafetyEquipment_ ? "Yes" : "No") << endl;
    cout << "Equipment: " << equipment_.size() << " items" << endl;
    for (size_t i = 0; i < equipment_.size(); ++i) {
        cout << "  " << (i + 1) << ". " << equipment_[i] << endl;
    }
}



