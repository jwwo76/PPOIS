#pragma once
#include "../pch.h"
#include "../Persons/Employee.h"

class Task {
private:
    int taskId_;
    string title_;
    string description_;
    Employee* assignedTo_;
    string dueDate_;
    string status_;
    int priority_;

public:
    Task(const string& title, const string& description, Employee* assignedTo,
         const string& dueDate, int priority = 1, int taskId = 0);
    
    int getTaskId() const { return taskId_; }
    string getTitle() const { return title_; }
    Employee* getAssignedTo() const { return assignedTo_; }
    string getStatus() const { return status_; }

    void setAssignedTo(Employee* employee) { assignedTo_ = employee; }
    void setStatus(const string& status) { status_ = status; }

    void completeTask();
    void print() const;
};

