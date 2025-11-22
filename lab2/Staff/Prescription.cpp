#include "Prescription.h"
#include "../Exceptions/Exceptions.h"

Prescription::Prescription(Patient* patient, Doctor* doctor, const string& date, 
                         const vector<string>& medications, const string& dosage, 
                         const string& instructions, int prescriptionId)
    : prescriptionId_(prescriptionId), patient_(patient), doctor_(doctor),
      date_(date), medications_(medications), dosage_(dosage), 
      instructions_(instructions), isFilled_(false) {
    if (medications.empty()) {
        Exceptions::throwInvalidPrescription("Prescription must have at least one medication");
    }
}

void Prescription::addMedication(const string& medication) {
    medications_.push_back(medication);
}

void Prescription::removeMedication(const string& medication) {
    auto it = remove(medications_.begin(), medications_.end(), medication);
    medications_.erase(it, medications_.end());
}

void Prescription::fillPrescription() {
    isFilled_ = true;
    cout << "Prescription #" << prescriptionId_ << " has been filled." << endl;
}

void Prescription::print() const {
    cout << "=== Prescription #" << prescriptionId_ << " ===" << endl;
    if (patient_ && doctor_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Doctor: " << doctor_->getFirstName() << " " << doctor_->getSurname() << endl;
    }
    cout << "Date: " << date_ << endl;
    cout << "Medications: ";
    for (size_t i = 0; i < medications_.size(); ++i) {
        cout << medications_[i];
        if (i < medications_.size() - 1) cout << ", ";
    }
    cout << endl;
    cout << "Dosage: " << dosage_ << endl;
    cout << "Instructions: " << instructions_ << endl;
    cout << "Status: " << (isFilled_ ? "Filled" : "Pending") << endl;
}

