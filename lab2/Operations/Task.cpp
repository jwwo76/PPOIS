#include "Task.h"

Task::Task(const string& title, const string& description, Employee* assignedTo,
           const string& dueDate, int priority, int taskId)
    : taskId_(taskId), title_(title), description_(description), assignedTo_(assignedTo),
      dueDate_(dueDate), status_("Pending"), priority_(priority) {}

void Task::completeTask() {
    status_ = "Completed";
    cout << "Task #" << taskId_ << " marked as completed" << endl;
}

void Task::print() const {
    cout << "=== Task #" << taskId_ << " ===" << endl;
    cout << "Title: " << title_ << endl;
    cout << "Description: " << description_ << endl;
    if (assignedTo_) {
        cout << "Assigned To: " << assignedTo_->getFirstName() << " " << assignedTo_->getSurname() << endl;
    }
    cout << "Due Date: " << dueDate_ << endl;
    cout << "Status: " << status_ << endl;
    cout << "Priority: " << priority_ << endl;
}

