#pragma once
#include "../Persons/Patient.h"

class MedicalCard {
private:
    int cardId_;
    Patient* patient_;
    vector<string> medicalHistory_;
    vector<string> currentMedications_;
    string bloodType_;
    string allergies_;
public:
    MedicalCard(int id, Patient* patient);
    
    int getCardId() const { return cardId_; }
    Patient* getPatient() const { return patient_; }
    const vector<string>& getMedicalHistory() const { return medicalHistory_; }
    const vector<string>& getCurrentMedications() const { return currentMedications_; }
    string getBloodType() const { return bloodType_; }
    string getAllergies() const { return allergies_; }
    
    void setBloodType(const string& bloodType) { bloodType_ = bloodType; }
    void setAllergies(const string& allergies) { allergies_ = allergies; }
    
    void addMedicalRecord(const string& record);
    void addMedication(const string& medication);
    void removeMedication(const string& medication);
    void clearHistory();
    void print() const;
};