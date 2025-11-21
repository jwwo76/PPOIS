#pragma once
#include "Employee.h"

class Department;

class Cleaner : public Employee {
private:
    string workShift_;           
    vector<Department*> assignedDepartments_; 
    string equipment_;           

public:
    Cleaner(const string& fName, const string& sName, int age,
            int id, double salary, int experience,
            const string& workShift, const vector<Department*>& assignedDepartments,
            const string& equipment)
        : Employee(fName, sName, age, id, "Cleaner", salary, experience),
          workShift_(workShift), assignedDepartments_(assignedDepartments), equipment_(equipment) {}

    Cleaner() : Employee("", "", 0, 0, "Cleaner", 0.0, 0),
                workShift_(""), equipment_("") {}

    void work() override;
    
    void assignDepartment(Department* dept);

    void clearDepartments();

    const vector<Department*>& getAssignedDepartments() const;


    string getWorkShift() const { return workShift_; }
    string getEquipment() const { return equipment_; }

    void setWorkShift(const string& shift) { workShift_ = shift; }
    void setEquipment(const string& equipment) { equipment_ = equipment; }

    void print() const override;
};