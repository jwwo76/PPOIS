#pragma once
#include "../pch.h"

class Employee;

class WorkLog{
    private:
        int logId_;
        Employee* employee_;
        string logDate_;
        string startTime_;
        string endTime_;
        int hoursWorked_;
        string activities_;
    public:
        WorkLog(int logId, Employee* employee, const string& logDate, const string& startTime, const string& endTime, int hoursWorked);
        ~WorkLog();

        int getLogId() const { return logId_; }
        Employee* getEmployee() const { return employee_; }
        int getHoursWorked() const { return hoursWorked_; }

        void setEndTime(const string& time);
        void calculateHours();

        void print() const;
};


