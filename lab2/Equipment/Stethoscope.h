#pragma once
#include "../pch.h"

class Department;

class Stethoscope {
private:
    string brand_;
    string type_;
    bool isElectronic_;
    Department* department_;

public:
    Stethoscope(const string& brand, const string& type, bool isElectronic, Department* department = nullptr);
    Stethoscope();

    string getBrand() const { return brand_; }
    string getType() const { return type_; }
    bool getIsElectronic() const { return isElectronic_; }
    Department* getDepartment() const { return department_; }

    void setBrand(const string& brand) { brand_ = brand; }
    void setType(const string& type) { type_ = type; }
    void setIsElectronic(bool electronic) { isElectronic_ = electronic; }
    void setDepartment(Department* department) { department_ = department; }

    void performAuscultation();
    void print() const;
};



