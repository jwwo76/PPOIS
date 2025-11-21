#pragma once
#include "../pch.h"
#include "../Persons/Doctor.h"
#include "Department.h"
#include "../Staff/InventoryItem.h"


class Cabinet {
private:
    string number_;
    Doctor* doctor_;
    Department* department_;
    vector<InventoryItem*> inventory_;  

public:
    Cabinet(const string& number, Doctor* doctor, Department* department);
    Cabinet(); 

    string getNumber() const { return number_; }
    Doctor* getDoctor() const { return doctor_; }
    Department* getDepartment() const { return department_; }
    const vector<InventoryItem*>& getInventory() const { return inventory_; }

    void setNumber(const string& number) { number_ = number; }
    void setDoctor(Doctor* doctor) { doctor_ = doctor; }
    void setDepartment(Department* department) { department_ = department; }

    void addInventoryItem(InventoryItem* item);
    void removeInventoryItem(InventoryItem* item);
    void print() const;
};