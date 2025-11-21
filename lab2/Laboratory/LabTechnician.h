#pragma once
#include "../Persons/Employee.h"

class LabTechnician : public Employee {
private:
    string specialization_;
    int testsPerformed_;

public:
    LabTechnician(const string& fName, const string& sName, int age, int id,
                 double salary, int experience, const string& specialization);
    
    string getSpecialization() const { return specialization_; }
    int getTestsPerformed() const { return testsPerformed_; }

    void setSpecialization(const string& specialization) { specialization_ = specialization; }

    void work() override;
    void performTest();
    void print() const override;
};



