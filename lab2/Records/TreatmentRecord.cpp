#include "TreatmentRecord.h"

TreatmentRecord::TreatmentRecord(Patient* patient, Doctor* doctor, const string& date,
                                 const string& treatmentType, const string& description, int treatmentId)
    : treatmentId_(treatmentId), patient_(patient), doctor_(doctor), date_(date),
      treatmentType_(treatmentType), description_(description), outcome_("") {}

void TreatmentRecord::recordOutcome(const string& outcome) {
    outcome_ = outcome;
    cout << "Treatment outcome recorded: " << outcome_ << endl;
}

void TreatmentRecord::print() const {
    cout << "=== Treatment Record #" << treatmentId_ << " ===" << endl;
    if (patient_ && doctor_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Doctor: " << doctor_->getFirstName() << " " << doctor_->getSurname() << endl;
    }
    cout << "Date: " << date_ << endl;
    cout << "Type: " << treatmentType_ << endl;
    cout << "Description: " << description_ << endl;
    if (!outcome_.empty())
        cout << "Outcome: " << outcome_ << endl;
}

