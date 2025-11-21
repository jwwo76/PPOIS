#pragma once
#include "../pch.h"
#include "../Persons/Doctor.h"

class Schedule {
private:
    Doctor* doctor_;
    string weekStartDate_;
    map<string, vector<string>> appointments_;  

public:
    Schedule(Doctor* doctor, const string& weekStartDate);
    
    Doctor* getDoctor() const { return doctor_; }
    string getWeekStartDate() const { return weekStartDate_; }
    const map<string, vector<string>>& getAppointments() const { return appointments_; }

    void setDoctor(Doctor* doctor) { doctor_ = doctor; }
    void setWeekStartDate(const string& date) { weekStartDate_ = date; }

    void addAppointment(const string& date, const string& time);
    void removeAppointment(const string& date, const string& time);
    bool isTimeSlotAvailable(const string& date, const string& time) const;
    void print() const;
};



