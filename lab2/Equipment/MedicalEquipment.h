#pragma once
#include "../pch.h"

class Department;

class MedicalEquipment {
private:
    string name_;
    string model_;
    string serialNumber_;
    Department* department_;
    bool isFunctional_;
    string lastMaintenanceDate_;

public:
    MedicalEquipment(const string& name, const string& model, const string& serialNumber,
                    Department* department, bool isFunctional = true, const string& lastMaintenanceDate = "");
    MedicalEquipment();

    string getName() const { return name_; }
    Department* getDepartment() const { return department_; }
    bool getIsFunctional() const { return isFunctional_; }
    string getLastMaintenanceDate() const { return lastMaintenanceDate_; }

    void setDepartment(Department* department) { department_ = department; }
    void setIsFunctional(bool functional) { isFunctional_ = functional; }

    void performMaintenance();
    void reportMalfunction();
    virtual void print() const;
};



