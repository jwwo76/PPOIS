#pragma once
#include "../pch.h"
#include "../Core/Department.h"

class OperatingRoom {
private:
    string roomNumber_;
    Department* department_;
    bool isAvailable_;
    string equipmentList_;
    int roomSize_;
    bool hasVentilation_;

public:
    OperatingRoom(const string& roomNumber, Department* department, int roomSize = 50,
                 bool hasVentilation = true);
    
    string getRoomNumber() const { return roomNumber_; }
    Department* getDepartment() const { return department_; }
    bool getIsAvailable() const { return isAvailable_; }
    int getRoomSize() const { return roomSize_; }

    void setDepartment(Department* dept) { department_ = dept; }
    void setIsAvailable(bool available) { isAvailable_ = available; }

    void reserveRoom();
    void releaseRoom();
    void print() const;
};



