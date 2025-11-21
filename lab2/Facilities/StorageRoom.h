#pragma once
#include "../pch.h"
#include "../Staff/InventoryItem.h"

class StorageRoom {
private:
    string roomNumber_;
    string storageType_;
    int capacity_;
    vector<InventoryItem*> items_;
    bool isTemperatureControlled_;
    double temperature_;

public:
    StorageRoom(const string& roomNumber, const string& storageType, int capacity = 100,
               bool isTemperatureControlled = false, double temperature = 20.0);
    
    string getRoomNumber() const { return roomNumber_; }
    string getStorageType() const { return storageType_; }
    int getCapacity() const { return capacity_; }
    const vector<InventoryItem*>& getItems() const { return items_; }
    double getTemperature() const { return temperature_; }

    void setCapacity(int capacity) { if(capacity > 0) capacity_ = capacity; }
    void setTemperature(double temp) { temperature_ = temp; }

    void addItem(InventoryItem* item);
    void removeItem(InventoryItem* item);
    bool isFull() const;
    void print() const;
};



