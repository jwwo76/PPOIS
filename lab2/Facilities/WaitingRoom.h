#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"
#include "../Core/Department.h"

class WaitingRoom {
private:
    string roomNumber_;
    Department* department_;
    int capacity_;
    vector<Patient*> patients_;
    bool hasAirConditioning_;
    bool hasTelevision_;

public:
    WaitingRoom(const string& roomNumber, Department* department, int capacity,
                bool hasAirConditioning = true, bool hasTelevision = true);
    
    string getRoomNumber() const { return roomNumber_; }
    Department* getDepartment() const { return department_; }
    int getCapacity() const { return capacity_; }
    const vector<Patient*>& getPatients() const { return patients_; }

    void setDepartment(Department* dept) { department_ = dept; }
    void setCapacity(int capacity) { if(capacity > 0) capacity_ = capacity; }

    void addPatient(Patient* patient);
    void removePatient(Patient* patient);
    bool isFull() const;
    void print() const;
};



