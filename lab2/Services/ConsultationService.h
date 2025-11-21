#pragma once
#include "../pch.h"
#include "../Persons/Doctor.h"
#include "../Persons/Patient.h"

class ConsultationService {
private:
    Patient* patient_;
    Doctor* doctor_;
    string date_;
    string time_;
    string complaint_;
    string diagnosis_;
    double cost_;

public:
    ConsultationService(Patient* patient, Doctor* doctor, const string& date, 
                       const string& time, const string& complaint, double cost = 0.0);
    
    Patient* getPatient() const { return patient_; }
    Doctor* getDoctor() const { return doctor_; }
    string getDate() const { return date_; }
    string getDiagnosis() const { return diagnosis_; }
    double getCost() const { return cost_; }

    void setCost(double cost) { if(cost >= 0) cost_ = cost; }

    void conductConsultation();
    void provideDiagnosis(const string& diagnosis);
    void print() const;
};



