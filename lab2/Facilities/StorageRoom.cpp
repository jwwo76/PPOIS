#include "StorageRoom.h"

StorageRoom::StorageRoom(const string& roomNumber, const string& storageType, int capacity,
                        bool isTemperatureControlled, double temperature)
    : roomNumber_(roomNumber), storageType_(storageType), capacity_(capacity),
      isTemperatureControlled_(isTemperatureControlled), temperature_(temperature) {}

void StorageRoom::addItem(InventoryItem* item) {
    if (item && !isFull()) {
        items_.push_back(item);
    }
}

void StorageRoom::removeItem(InventoryItem* item) {
    auto it = remove(items_.begin(), items_.end(), item);
    items_.erase(it, items_.end());
}

bool StorageRoom::isFull() const {
    return items_.size() >= capacity_;
}

void StorageRoom::print() const {
    cout << "=== Storage Room " << roomNumber_ << " ===" << endl;
    cout << "Type: " << storageType_ << endl;
    cout << "Capacity: " << capacity_ << endl;
    cout << "Items: " << items_.size() << endl;
    cout << "Temperature Controlled: " << (isTemperatureControlled_ ? "Yes" : "No") << endl;
    if (isTemperatureControlled_)
        cout << "Temperature: " << temperature_ << "°C" << endl;
}



