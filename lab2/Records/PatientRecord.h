#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"

class PatientRecord {
private:
    int recordId_;
    Patient* patient_;
    string admissionDate_;
    string dischargeDate_;
    string chiefComplaint_;
    vector<string> treatments_;
    string status_;

public:
    PatientRecord(Patient* patient, const string& admissionDate, const string& chiefComplaint, int recordId = 0);
    
    int getRecordId() const { return recordId_; }
    Patient* getPatient() const { return patient_; }
    string getAdmissionDate() const { return admissionDate_; }
    string getDischargeDate() const { return dischargeDate_; }
    string getStatus() const { return status_; }

    void addTreatment(const string& treatment);
    void dischargePatient(const string& dischargeDate);
    void print() const;
};

