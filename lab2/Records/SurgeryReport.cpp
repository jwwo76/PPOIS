#include "SurgeryReport.h"

SurgeryReport::SurgeryReport(Patient* patient, Doctor* surgeon, const string& surgeryDate,
                             const string& surgeryType, const string& procedure, int reportId)
    : reportId_(reportId), patient_(patient), surgeon_(surgeon), surgeryDate_(surgeryDate),
      surgeryType_(surgeryType), procedure_(procedure), complications_(""), recoveryNotes_(""),
      wasSuccessful_(false) {}

void SurgeryReport::addComplications(const string& complications) {
    if (!complications_.empty()) complications_ += "\n";
    complications_ += complications;
}

void SurgeryReport::addRecoveryNotes(const string& notes) {
    if (!recoveryNotes_.empty()) recoveryNotes_ += "\n";
    recoveryNotes_ += notes;
}

void SurgeryReport::markSuccessful() {
    wasSuccessful_ = true;
    cout << "Surgery marked as successful" << endl;
}

void SurgeryReport::print() const {
    cout << "=== Surgery Report #" << reportId_ << " ===" << endl;
    if (patient_ && surgeon_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Surgeon: " << surgeon_->getFirstName() << " " << surgeon_->getSurname() << endl;
    }
    cout << "Date: " << surgeryDate_ << endl;
    cout << "Type: " << surgeryType_ << endl;
    cout << "Procedure: " << procedure_ << endl;
    cout << "Success: " << (wasSuccessful_ ? "Yes" : "No") << endl;
    if (!complications_.empty())
        cout << "Complications: " << complications_ << endl;
    if (!recoveryNotes_.empty())
        cout << "Recovery Notes: " << recoveryNotes_ << endl;
}

