#pragma once
#include "../pch.h"
#include "../Persons/Employee.h"

class Shift {
private:
    string date_;
    string startTime_;
    string endTime_;
    vector<Employee*> employees_;
    string shiftType_;

public:
    Shift(const string& date, const string& startTime, const string& endTime, const string& shiftType = "Day");
    
    string getDate() const { return date_; }
    string getStartTime() const { return startTime_; }
    string getEndTime() const { return endTime_; }
    const vector<Employee*>& getEmployees() const { return employees_; }
    string getShiftType() const { return shiftType_; }

    void setDate(const string& date) { date_ = date; }
    void setStartTime(const string& time) { startTime_ = time; }
    void setEndTime(const string& time) { endTime_ = time; }
    void setShiftType(const string& type) { shiftType_ = type; }

    void addEmployee(Employee* employee);
    void removeEmployee(Employee* employee);
    void print() const;
};



