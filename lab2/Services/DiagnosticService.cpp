#include "DiagnosticService.h"

DiagnosticService::DiagnosticService(Patient* patient, Doctor* doctor, const string& testType, const string& date, int serviceId)
    : serviceId_(serviceId), patient_(patient), doctor_(doctor), testType_(testType),
      date_(date), result_(""), isCompleted_(false) {}

void DiagnosticService::performTest() {
    if (patient_ && doctor_) {
        cout << "Diagnostic test " << testType_ << " performed for patient "
             << patient_->getFirstName() << " " << patient_->getSurname() << endl;
    }
}

void DiagnosticService::completeTest(const string& result) {
    result_ = result;
    isCompleted_ = true;
    cout << "Test #" << serviceId_ << " completed. Result: " << result_ << endl;
}

void DiagnosticService::print() const {
    cout << "=== Diagnostic Service #" << serviceId_ << " ===" << endl;
    if (patient_ && doctor_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Doctor: " << doctor_->getFirstName() << " " << doctor_->getSurname() << endl;
    }
    cout << "Test Type: " << testType_ << endl;
    cout << "Date: " << date_ << endl;
    cout << "Status: " << (isCompleted_ ? "Completed" : "Pending") << endl;
    if (!result_.empty())
        cout << "Result: " << result_ << endl;
}

