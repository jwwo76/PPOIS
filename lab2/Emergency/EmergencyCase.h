#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"
#include "../Persons/Doctor.h"

class EmergencyCase {
private:
    int caseId_;
    Patient* patient_;
    Doctor* attendingDoctor_;
    string arrivalTime_;
    string condition_;
    int severityLevel_;
    string status_;

public:
    EmergencyCase(Patient* patient, Doctor* attendingDoctor, const string& arrivalTime,
                 const string& condition, int severityLevel = 1, int caseId = 0);
    
    int getCaseId() const { return caseId_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getAttendingDoctor() const { return attendingDoctor_; }
    string getArrivalTime() const { return arrivalTime_; }
    string getCondition() const { return condition_; }
    int getSeverityLevel() const { return severityLevel_; }
    string getStatus() const { return status_; }

    void setArrivalTime(const string& time) { arrivalTime_ = time; }
    void setCondition(const string& condition) { condition_ = condition; }
    void setSeverityLevel(int level) { if(level > 0 && level <= 5) severityLevel_ = level; }
    void setStatus(const string& status) { status_ = status; }

    void triage();
    void treat();
    void discharge();
    void print() const;
};

