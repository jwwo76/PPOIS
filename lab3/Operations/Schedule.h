#pragma once
#include "../pch.h"

class Employee;

class Schedule{
    private:
        int scheduleId_;
        Employee* employee_;
        string weekStartDate_;
        vector<string> workDays_;
        vector<string> workHours_;
    public:
        Schedule(int scheduleId, Employee* employee, const string& weekStartDate);
        ~Schedule();

        int getScheduleId() const { return scheduleId_; }
        Employee* getEmployee() const { return employee_; }
        vector<string> getWorkDays() const { return workDays_; }

        void addWorkDay(const string& day, const string& hours);
        void removeWorkDay(const string& day);

        void print() const;
};


