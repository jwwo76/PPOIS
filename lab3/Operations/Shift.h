#pragma once
#include "../pch.h"

class Employee;

class Shift{
    private:
        int shiftId_;
        Employee* employee_;
        string shiftDate_;
        bool isCompleted_;
    public:
        Shift(int shiftId, Employee* employee, const string& shiftDate);
        ~Shift();

        int getShiftId() const { return shiftId_; }
        Employee* getEmployee() const { return employee_; }
        string getShiftDate() const { return shiftDate_; }
        bool getIsCompleted() const { return isCompleted_; }

        void complete() { isCompleted_ = true; }

        void print() const;
};


