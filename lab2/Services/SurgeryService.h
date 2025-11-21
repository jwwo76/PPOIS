#pragma once
#include "../pch.h"
#include "../Persons/Doctor.h"
#include "../Persons/Patient.h"

class SurgeryService {
private:
    int surgeryId_;
    Patient* patient_;
    Doctor* surgeon_;
    string surgeryType_;
    string date_;
    string time_;
    string status_;
    double cost_;
    int duration_;

public:
    SurgeryService(Patient* patient, Doctor* surgeon, const string& surgeryType,
                  const string& date, const string& time, double cost = 0.0, int duration = 60, int surgeryId = 0);
    
    int getSurgeryId() const { return surgeryId_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getSurgeon() const { return surgeon_; }
    string getSurgeryType() const { return surgeryType_; }
    string getDate() const { return date_; }
    string getTime() const { return time_; }
    string getStatus() const { return status_; }
    double getCost() const { return cost_; }
    int getDuration() const { return duration_; }

    void setSurgeryType(const string& type) { surgeryType_ = type; }
    void setDate(const string& date) { date_ = date; }
    void setTime(const string& time) { time_ = time; }
    void setStatus(const string& status) { status_ = status; }
    void setCost(double cost) { if(cost >= 0) cost_ = cost; }
    void setDuration(int duration) { if(duration > 0) duration_ = duration; }

    void scheduleSurgery();
    void performSurgery();
    void completeSurgery();
    void cancelSurgery();
    void print() const;
};

