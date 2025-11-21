#include "VaccinationService.h"

VaccinationService::VaccinationService(Patient* patient, Doctor* doctor, const string& vaccineName,
                                       const string& date, const string& batchNumber, int doseNumber, int vaccinationId)
    : vaccinationId_(vaccinationId), patient_(patient), doctor_(doctor), vaccineName_(vaccineName),
      date_(date), batchNumber_(batchNumber), nextDoseDate_(""), doseNumber_(doseNumber) {}

void VaccinationService::administerVaccine() {
    if (patient_ && doctor_) {
        cout << "Vaccine " << vaccineName_ << " (Dose " << doseNumber_ << ") administered" << endl;
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Doctor: " << doctor_->getFirstName() << " " << doctor_->getSurname() << endl;
        cout << "Batch Number: " << batchNumber_ << endl;
    }
}

void VaccinationService::scheduleNextDose(const string& date) {
    nextDoseDate_ = date;
    cout << "Next dose scheduled for: " << nextDoseDate_ << endl;
}

void VaccinationService::print() const {
    cout << "=== Vaccination Service #" << vaccinationId_ << " ===" << endl;
    if (patient_ && doctor_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Doctor: " << doctor_->getFirstName() << " " << doctor_->getSurname() << endl;
    }
    cout << "Vaccine: " << vaccineName_ << endl;
    cout << "Dose Number: " << doseNumber_ << endl;
    cout << "Date: " << date_ << endl;
    cout << "Batch Number: " << batchNumber_ << endl;
    if (!nextDoseDate_.empty())
        cout << "Next Dose: " << nextDoseDate_ << endl;
}

