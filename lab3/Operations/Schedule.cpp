#include "Schedule.h"
#include "../Persons/Employee.h"

Schedule::Schedule(int scheduleId, Employee* employee, const string& weekStartDate)
    : scheduleId_(scheduleId), employee_(employee), weekStartDate_(weekStartDate) {}

Schedule::~Schedule() {
    employee_ = nullptr;
}

void Schedule::addWorkDay(const string& day, const string& hours) {
    workDays_.push_back(day);
    workHours_.push_back(hours);
}

void Schedule::removeWorkDay(const string& day) {
    workDays_.erase(remove(workDays_.begin(), workDays_.end(), day), workDays_.end());
}

void Schedule::print() const {
    cout << "Schedule ID: " << scheduleId_ << endl;
    cout << "Week Start: " << weekStartDate_ << endl;
    cout << "Work Days: " << workDays_.size() << endl;
}


