#include "SurgeryService.h"

SurgeryService::SurgeryService(Patient* patient, Doctor* surgeon, const string& surgeryType,
                               const string& date, const string& time, double cost, int duration, int surgeryId)
    : surgeryId_(surgeryId), patient_(patient), surgeon_(surgeon), surgeryType_(surgeryType),
      date_(date), time_(time), status_("Scheduled"), cost_(cost), duration_(duration) {}

void SurgeryService::scheduleSurgery() {
    status_ = "Scheduled";
    if (patient_ && surgeon_) {
        cout << "Surgery #" << surgeryId_ << " scheduled: " << surgeryType_ << endl;
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Surgeon: " << surgeon_->getFirstName() << " " << surgeon_->getSurname() << endl;
    }
}

void SurgeryService::performSurgery() {
    status_ = "In Progress";
    cout << "Surgery #" << surgeryId_ << " in progress..." << endl;
}

void SurgeryService::completeSurgery() {
    status_ = "Completed";
    cout << "Surgery #" << surgeryId_ << " completed successfully" << endl;
}

void SurgeryService::cancelSurgery() {
    status_ = "Cancelled";
    cout << "Surgery #" << surgeryId_ << " cancelled" << endl;
}

void SurgeryService::print() const {
    cout << "=== Surgery Service #" << surgeryId_ << " ===" << endl;
    if (patient_ && surgeon_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Surgeon: " << surgeon_->getFirstName() << " " << surgeon_->getSurname() << endl;
    }
    cout << "Type: " << surgeryType_ << endl;
    cout << "Date: " << date_ << " at " << time_ << endl;
    cout << "Duration: " << duration_ << " minutes" << endl;
    cout << "Status: " << status_ << endl;
    cout << "Cost: $" << cost_ << endl;
}

