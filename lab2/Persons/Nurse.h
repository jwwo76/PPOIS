#pragma once
#include "Employee.h"

class Department;

class Nurse : public Employee{
    private:
        Department* department_;
        string specialization_;
        int patientCapacity_;
    public:
        Nurse(const string& fName, const string& sName, int age,
           int id, double salary, int experience, Department* department,
           const string& specialization = "", int patientCapacity = 10)
        : Employee(fName, sName, age, id, "Nurse", salary, experience),
          department_(department),
          specialization_(specialization),
          patientCapacity_(patientCapacity){};
        
        void work() override;
        void print() const override;
        
        string getSpecialization() const { return specialization_; }
        int getPatientCapacity() const { return patientCapacity_; }
        Department* getDepartment() const { return department_; }
        
        void setSpecialization(const string& specialization) { specialization_ = specialization; }
        void setPatientCapacity(int capacity) { if(capacity > 0) patientCapacity_ = capacity; }
        void setDepartment(Department* department) { department_ = department; }
};



