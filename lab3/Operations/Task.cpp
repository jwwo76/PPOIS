#include "Task.h"
#include "../Persons/Employee.h"

Task::Task(int taskId, const string& taskName, const string& description, Employee* assignedTo, const string& dueDate, int priority)
    : taskId_(taskId), taskName_(taskName), description_(description), assignedTo_(assignedTo), dueDate_(dueDate), status_("Pending"), priority_(priority) {}

Task::~Task() {
    assignedTo_ = nullptr;
}

void Task::setAssignedTo(Employee* employee) {
    assignedTo_ = employee;
}

void Task::print() const {
    cout << "Task ID: " << taskId_ << endl;
    cout << "Task Name: " << taskName_ << endl;
    cout << "Description: " << description_ << endl;
    cout << "Due Date: " << dueDate_ << endl;
    cout << "Status: " << status_ << endl;
    cout << "Priority: " << priority_ << endl;
}


