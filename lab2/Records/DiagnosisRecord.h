#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"
#include "../Persons/Doctor.h"

class DiagnosisRecord {
private:
    int diagnosisId_;
    Patient* patient_;
    Doctor* doctor_;
    string date_;
    string diagnosis_;
    string symptoms_;
    string recommendations_;

public:
    DiagnosisRecord(Patient* patient, Doctor* doctor, const string& date,
                   const string& diagnosis, const string& symptoms, int diagnosisId = 0);
    
    int getDiagnosisId() const { return diagnosisId_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getDoctor() const { return doctor_; }
    string getDate() const { return date_; }
    string getDiagnosis() const { return diagnosis_; }
    string getSymptoms() const { return symptoms_; }
    string getRecommendations() const { return recommendations_; }

    void setDate(const string& date) { date_ = date; }
    void setDiagnosis(const string& diagnosis) { diagnosis_ = diagnosis; }
    void setSymptoms(const string& symptoms) { symptoms_ = symptoms; }
    void setRecommendations(const string& recommendations) { recommendations_ = recommendations; }

    void addRecommendations(const string& recommendations);
    void print() const;
};

