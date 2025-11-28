#include "WorkLog.h"
#include "../Persons/Employee.h"

WorkLog::WorkLog(int logId, Employee* employee, const string& logDate, const string& startTime, const string& endTime, int hoursWorked)
    : logId_(logId), employee_(employee), logDate_(logDate), startTime_(startTime), endTime_(endTime), hoursWorked_(hoursWorked) {}

WorkLog::~WorkLog() {
    employee_ = nullptr;
}

void WorkLog::setEndTime(const string& time) {
    endTime_ = time;
}

void WorkLog::calculateHours() {
    // Calculate hours based on start and end time
}

void WorkLog::print() const {
    cout << "Log ID: " << logId_ << endl;
    cout << "Date: " << logDate_ << endl;
    cout << "Time: " << startTime_ << " - " << endTime_ << endl;
    cout << "Hours Worked: " << hoursWorked_ << endl;
    if (!activities_.empty()) {
        cout << "Activities: " << activities_ << endl;
    }
}


