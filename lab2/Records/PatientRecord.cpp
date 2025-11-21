#include "PatientRecord.h"

PatientRecord::PatientRecord(Patient* patient, const string& admissionDate, const string& chiefComplaint, int recordId)
    : recordId_(recordId), patient_(patient), admissionDate_(admissionDate),
      dischargeDate_(""), chiefComplaint_(chiefComplaint), status_("Active") {}

void PatientRecord::addTreatment(const string& treatment) {
    treatments_.push_back(treatment);
}

void PatientRecord::dischargePatient(const string& dischargeDate) {
    dischargeDate_ = dischargeDate;
    status_ = "Discharged";
    cout << "Patient discharged on " << dischargeDate_ << endl;
}

void PatientRecord::print() const {
    cout << "=== Patient Record #" << recordId_ << " ===" << endl;
    if (patient_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
    }
    cout << "Admission Date: " << admissionDate_ << endl;
    if (!dischargeDate_.empty())
        cout << "Discharge Date: " << dischargeDate_ << endl;
    cout << "Chief Complaint: " << chiefComplaint_ << endl;
    cout << "Status: " << status_ << endl;
    cout << "Treatments: " << treatments_.size() << endl;
    for (size_t i = 0; i < treatments_.size(); ++i) {
        cout << "  " << (i + 1) << ". " << treatments_[i] << endl;
    }
}

