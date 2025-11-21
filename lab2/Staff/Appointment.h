#pragma once
#include "../Persons/Doctor.h"
#include "../Persons/Patient.h"

class Appointment {
private:
    int appointmentId_;
    Patient* patient_;
    Doctor* doctor_;
    string dateTime_;
    string reason_;
    bool isCompleted_;
    double cost_;
public:
    Appointment(Patient* patient, Doctor* doctor, const string& dateTime, const string& reason, int appointmentId = 0);
    
    int getAppointmentId() const { return appointmentId_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getDoctor() const { return doctor_; }
    string getDateTime() const { return dateTime_; }
    string getReason() const { return reason_; }
    bool getIsCompleted() const { return isCompleted_; }
    double getCost() const { return cost_; }
    
    void setDateTime(const string& dateTime) { dateTime_ = dateTime; }
    void setReason(const string& reason) { reason_ = reason; }
    void setCost(double cost) { if(cost >= 0) cost_ = cost; }
    
    void reschedule(const string& newDateTime);
    void completeAppointment(const string& diagnosis);
    void cancelAppointment();
    void print() const;
};