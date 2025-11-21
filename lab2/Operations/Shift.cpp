#include "Shift.h"

Shift::Shift(const string& date, const string& startTime, const string& endTime, const string& shiftType)
    : date_(date), startTime_(startTime), endTime_(endTime), shiftType_(shiftType) {}

void Shift::addEmployee(Employee* employee) {
    if (employee) {
        employees_.push_back(employee);
    }
}

void Shift::removeEmployee(Employee* employee) {
    auto it = remove(employees_.begin(), employees_.end(), employee);
    employees_.erase(it, employees_.end());
}

void Shift::print() const {
    cout << "=== Shift ===" << endl;
    cout << "Date: " << date_ << endl;
    cout << "Time: " << startTime_ << " - " << endTime_ << endl;
    cout << "Type: " << shiftType_ << endl;
    cout << "Employees: " << employees_.size() << endl;
}



