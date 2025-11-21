#include "MedicalCard.h"

MedicalCard::MedicalCard(int id, Patient* patient) 
    : cardId_(id), patient_(patient), bloodType_("Unknown"), allergies_("None") {}

void MedicalCard::addMedicalRecord(const string& record) {
    medicalHistory_.push_back(record);
}

void MedicalCard::addMedication(const string& medication) {
    currentMedications_.push_back(medication);
}

void MedicalCard::removeMedication(const string& medication) {
    auto it = remove(currentMedications_.begin(), currentMedications_.end(), medication);
    currentMedications_.erase(it, currentMedications_.end());
}

void MedicalCard::clearHistory() {
    medicalHistory_.clear();
}

void MedicalCard::print() const {
    cout << "=== Medical Card #" << cardId_ << " ===" << endl;
    if (patient_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
    }
    cout << "Blood Type: " << bloodType_ << endl;
    cout << "Allergies: " << allergies_ << endl;
    cout << "Current Medications: " << currentMedications_.size() << endl;
    cout << "Medical History Records: " << medicalHistory_.size() << endl;
}