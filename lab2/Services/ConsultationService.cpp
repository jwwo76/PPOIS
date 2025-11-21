#include "ConsultationService.h"

ConsultationService::ConsultationService(Patient* patient, Doctor* doctor, const string& date,
                                        const string& time, const string& complaint, double cost)
    : patient_(patient), doctor_(doctor), date_(date), time_(time), complaint_(complaint),
      diagnosis_(""), cost_(cost) {}

void ConsultationService::conductConsultation() {
    if (patient_ && doctor_) {
        cout << "Consultation conducted: " << doctor_->getFirstName() << " " << doctor_->getSurname()
             << " with " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Complaint: " << complaint_ << endl;
    }
}

void ConsultationService::provideDiagnosis(const string& diagnosis) {
    diagnosis_ = diagnosis;
    cout << "Diagnosis provided: " << diagnosis_ << endl;
}

void ConsultationService::print() const {
    cout << "=== Consultation Service ===" << endl;
    if (patient_ && doctor_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Doctor: " << doctor_->getFirstName() << " " << doctor_->getSurname() << endl;
    }
    cout << "Date: " << date_ << " at " << time_ << endl;
    cout << "Complaint: " << complaint_ << endl;
    if (!diagnosis_.empty())
        cout << "Diagnosis: " << diagnosis_ << endl;
    cout << "Cost: $" << cost_ << endl;
}



