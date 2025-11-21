#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"
#include "../Persons/Doctor.h"

class TreatmentRecord {
private:
    int treatmentId_;
    Patient* patient_;
    Doctor* doctor_;
    string date_;
    string treatmentType_;
    string description_;
    string outcome_;

public:
    TreatmentRecord(Patient* patient, Doctor* doctor, const string& date,
                   const string& treatmentType, const string& description, int treatmentId = 0);
    
    int getTreatmentId() const { return treatmentId_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getDoctor() const { return doctor_; }
    string getOutcome() const { return outcome_; }

    void recordOutcome(const string& outcome);
    void print() const;
};

