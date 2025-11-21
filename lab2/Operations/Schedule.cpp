#include "Schedule.h"

Schedule::Schedule(Doctor* doctor, const string& weekStartDate)
    : doctor_(doctor), weekStartDate_(weekStartDate) {}

void Schedule::addAppointment(const string& date, const string& time) {
    appointments_[date].push_back(time);
}

void Schedule::removeAppointment(const string& date, const string& time) {
    if (appointments_.find(date) != appointments_.end()) {
        auto& times = appointments_[date];
        auto it = remove(times.begin(), times.end(), time);
        times.erase(it, times.end());
        if (times.empty()) {
            appointments_.erase(date);
        }
    }
}

bool Schedule::isTimeSlotAvailable(const string& date, const string& time) const {
    if (appointments_.find(date) == appointments_.end()) {
        return true;
    }
    const auto& times = appointments_.at(date);
    return find(times.begin(), times.end(), time) == times.end();
}

void Schedule::print() const {
    cout << "=== Schedule ===" << endl;
    if (doctor_) {
        cout << "Doctor: " << doctor_->getFirstName() << " " << doctor_->getSurname() << endl;
    }
    cout << "Week Starting: " << weekStartDate_ << endl;
    cout << "Appointments: " << appointments_.size() << " days" << endl;
    for (const auto& day : appointments_) {
        cout << "  " << day.first << ": " << day.second.size() << " appointments" << endl;
    }
}



