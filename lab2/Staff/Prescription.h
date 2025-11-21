#pragma once
#include "../Persons/Doctor.h"
#include "../Persons/Patient.h"

class Prescription {
private:
    int prescriptionId_;
    Patient* patient_;
    Doctor* doctor_;
    string date_;
    vector<string> medications_;
    string dosage_;
    string instructions_;
    bool isFilled_;

public:
    Prescription(Patient* patient, Doctor* doctor, const string& date, 
                 const vector<string>& medications, const string& dosage, 
                 const string& instructions, int prescriptionId = 0);
    
    int getPrescriptionId() const { return prescriptionId_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getDoctor() const { return doctor_; }
    string getDate() const { return date_; }
    const vector<string>& getMedications() const { return medications_; }
    string getDosage() const { return dosage_; }
    string getInstructions() const { return instructions_; }
    bool getIsFilled() const { return isFilled_; }
    
    void setDate(const string& date) { date_ = date; }
    void setDosage(const string& dosage) { dosage_ = dosage; }
    void setInstructions(const string& instructions) { instructions_ = instructions; }
    
    void addMedication(const string& medication);
    void removeMedication(const string& medication);
    void fillPrescription();
    void print() const;
};

