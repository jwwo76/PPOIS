#pragma once
#include "../Persons/Employee.h"

class Pharmacist : public Employee {
private:
    string licenseNumber_;
    int prescriptionsDispensed_;

public:
    Pharmacist(const string& fName, const string& sName, int age, int id,
              double salary, int experience, const string& licenseNumber);
    
    string getLicenseNumber() const { return licenseNumber_; }
    int getPrescriptionsDispensed() const { return prescriptionsDispensed_; }

    void setLicenseNumber(const string& license) { licenseNumber_ = license; }

    void work() override;
    void dispensePrescription();
    void print() const override;
};



