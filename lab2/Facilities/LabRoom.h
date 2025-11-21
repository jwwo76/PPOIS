#pragma once
#include "../pch.h"

class LabRoom {
private:
    string roomNumber_;
    string labType_;
    int capacity_;
    bool hasSafetyEquipment_;
    vector<string> equipment_;

public:
    LabRoom(const string& roomNumber, const string& labType, int capacity = 10,
           bool hasSafetyEquipment = true);
    
    string getRoomNumber() const { return roomNumber_; }
    string getLabType() const { return labType_; }
    int getCapacity() const { return capacity_; }
    const vector<string>& getEquipment() const { return equipment_; }

    void setCapacity(int capacity) { if(capacity > 0) capacity_ = capacity; }

    void addEquipment(const string& equipment);
    void removeEquipment(const string& equipment);
    void print() const;
};



