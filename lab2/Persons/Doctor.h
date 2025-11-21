#pragma once

#include "Employee.h"

class Department;

class Doctor : public Employee{
    private:
        Department* department_;
        string specialization_;
    public:
        Doctor(const string& fName, const string& sName, int age,
           int id, double salary, int experience, Department* department,
           const string& specialization = "", const string& schedule = "",
           int patientsPerDay = 0)
        : Employee(fName, sName, age, id, "Doctor", salary, experience),
          department_(department),
          specialization_(specialization){};
        
        void work() override;
        void print() const override;
};