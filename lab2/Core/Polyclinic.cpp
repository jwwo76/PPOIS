#include "Polyclinic.h"
#include "Department.h"
#include "../Exceptions/Exceptions.h"   

Polyclinic::Polyclinic(const std::string& name, const std::string& address)
    : name_(name), address_(address) {}

void Polyclinic::addDepartment(Department* department) {
    if (department)
        departments_.push_back(department);
}

void Polyclinic::removeDepartment(Department* department) {
    auto it = std::find(departments_.begin(), departments_.end(), department);
    if (it == departments_.end()) {
        Exceptions::throwDepartmentNotFound("Department not found in polyclinic");
    }
    departments_.erase(it);
}

void Polyclinic::printInfo() const {
    std::cout << "Polyclinic name: " << name_ << std::endl;
    std::cout << "Address: " << address_ << std::endl;
    std::cout << "Departments: " << std::endl;

    if (departments_.empty()) {
        std::cout << "  No departments available." << std::endl;
    } else {
        for (const auto& dep : departments_) {
            std::cout << "  - " << dep->getName() << std::endl;
        }
    }
}
