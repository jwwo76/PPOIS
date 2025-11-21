#pragma once

#include "../pch.h"

class Department;

class Polyclinic {
private:
    std::string address_;
    std::string name_;
    std::vector<Department*> departments_;

public:
    Polyclinic() = default;
    Polyclinic(const std::string& name, const std::string& address);

    std::string getName() const { return name_; }
    std::string getAddress() const { return address_; }
    std::vector<Department*> getDepartments() const { return departments_; }

    void setName(const std::string& newName) { name_ = newName; }
    void setAddress(const std::string& newAddress) { address_ = newAddress; }

    void addDepartment(Department* department);
    void removeDepartment(Department* department);
    void printInfo() const;

    virtual ~Polyclinic() = default;
};
