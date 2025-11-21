#include "EmergencyCase.h"

EmergencyCase::EmergencyCase(Patient* patient, Doctor* attendingDoctor, const string& arrivalTime,
                            const string& condition, int severityLevel, int caseId)
    : caseId_(caseId), patient_(patient), attendingDoctor_(attendingDoctor),
      arrivalTime_(arrivalTime), condition_(condition), severityLevel_(severityLevel),
      status_("Arrived") {}

void EmergencyCase::triage() {
    status_ = "Triaged";
    cout << "Emergency case #" << caseId_ << " triaged. Severity: " << severityLevel_ << endl;
}

void EmergencyCase::treat() {
    status_ = "Under Treatment";
    if (patient_ && attendingDoctor_) {
        cout << "Patient " << patient_->getFirstName() << " " << patient_->getSurname()
             << " is being treated by Dr. " << attendingDoctor_->getFirstName() << " " << attendingDoctor_->getSurname() << endl;
    }
}

void EmergencyCase::discharge() {
    status_ = "Discharged";
    cout << "Emergency case #" << caseId_ << " discharged" << endl;
}

void EmergencyCase::print() const {
    cout << "=== Emergency Case #" << caseId_ << " ===" << endl;
    if (patient_ && attendingDoctor_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Attending Doctor: " << attendingDoctor_->getFirstName() << " " << attendingDoctor_->getSurname() << endl;
    }
    cout << "Arrival Time: " << arrivalTime_ << endl;
    cout << "Condition: " << condition_ << endl;
    cout << "Severity Level: " << severityLevel_ << "/5" << endl;
    cout << "Status: " << status_ << endl;
}

