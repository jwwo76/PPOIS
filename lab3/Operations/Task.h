#pragma once
#include "../pch.h"

class Employee;

class Task{
    private:
        int taskId_;
        string taskName_;
        string description_;
        Employee* assignedTo_;
        string dueDate_;
        string status_;
        int priority_;
    public:
        Task(int taskId, const string& taskName, const string& description, Employee* assignedTo, const string& dueDate, int priority);
        ~Task();

        int getTaskId() const { return taskId_; }
        string getTaskName() const { return taskName_; }
        string getDescription() const { return description_; }
        Employee* getAssignedTo() const { return assignedTo_; }
        string getDueDate() const { return dueDate_; }
        string getStatus() const { return status_; }
        int getPriority() const { return priority_; }

        void setTaskId(int id) { taskId_ = id; }
        void setTaskName(const string& name) { taskName_ = name; }
        void setDescription(const string& desc) { description_ = desc; }
        void setAssignedTo(Employee* employee);
        void setDueDate(const string& date) { dueDate_ = date; }
        void setStatus(const string& status) { status_ = status; }
        void setPriority(int priority) { priority_ = priority; }

        void print() const;
};


