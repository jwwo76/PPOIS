#include "DiagnosisRecord.h"

DiagnosisRecord::DiagnosisRecord(Patient* patient, Doctor* doctor, const string& date,
                                 const string& diagnosis, const string& symptoms, int diagnosisId)
    : diagnosisId_(diagnosisId), patient_(patient), doctor_(doctor), date_(date),
      diagnosis_(diagnosis), symptoms_(symptoms), recommendations_("") {}

void DiagnosisRecord::addRecommendations(const string& recommendations) {
    if (!recommendations_.empty()) recommendations_ += "\n";
    recommendations_ += recommendations;
}

void DiagnosisRecord::print() const {
    cout << "=== Diagnosis Record #" << diagnosisId_ << " ===" << endl;
    if (patient_ && doctor_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Doctor: " << doctor_->getFirstName() << " " << doctor_->getSurname() << endl;
    }
    cout << "Date: " << date_ << endl;
    cout << "Diagnosis: " << diagnosis_ << endl;
    cout << "Symptoms: " << symptoms_ << endl;
    if (!recommendations_.empty())
        cout << "Recommendations: " << recommendations_ << endl;
}

