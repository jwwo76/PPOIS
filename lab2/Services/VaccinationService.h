#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"
#include "../Persons/Doctor.h"

class VaccinationService {
private:
    int vaccinationId_;
    Patient* patient_;
    Doctor* doctor_;
    string vaccineName_;
    string date_;
    string batchNumber_;
    string nextDoseDate_;
    int doseNumber_;

public:
    VaccinationService(Patient* patient, Doctor* doctor, const string& vaccineName,
                      const string& date, const string& batchNumber, int doseNumber = 1, int vaccinationId = 0);
    
    int getVaccinationId() const { return vaccinationId_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getDoctor() const { return doctor_; }
    string getVaccineName() const { return vaccineName_; }
    string getDate() const { return date_; }
    string getBatchNumber() const { return batchNumber_; }
    string getNextDoseDate() const { return nextDoseDate_; }
    int getDoseNumber() const { return doseNumber_; }

    void setVaccineName(const string& name) { vaccineName_ = name; }
    void setDate(const string& date) { date_ = date; }
    void setBatchNumber(const string& batch) { batchNumber_ = batch; }
    void setNextDoseDate(const string& date) { nextDoseDate_ = date; }
    void setDoseNumber(int dose) { if(dose > 0) doseNumber_ = dose; }

    void administerVaccine();
    void scheduleNextDose(const string& date);
    void print() const;
};

