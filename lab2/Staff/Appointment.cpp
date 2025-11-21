#include "Appointment.h"

Appointment::Appointment(Patient* patient, Doctor* doctor, const string& dateTime, const string& reason, int appointmentId)
    : appointmentId_(appointmentId), patient_(patient), doctor_(doctor),
      dateTime_(dateTime), reason_(reason), isCompleted_(false), cost_(0.0) {}

void Appointment::reschedule(const string& newDateTime) {
    dateTime_ = newDateTime;
    cout << "Appointment #" << appointmentId_ << " rescheduled to " << newDateTime << endl;
}

void Appointment::completeAppointment(const string& diagnosis) {
    isCompleted_ = true;
    cout << "Appointment #" << appointmentId_ << " completed. Diagnosis: " << diagnosis << endl;
}

void Appointment::cancelAppointment() {
    cout << "Appointment #" << appointmentId_ << " cancelled" << endl;
}

void Appointment::print() const {
    cout << "=== Appointment #" << appointmentId_ << " ===" << endl;
    if (patient_ && doctor_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Doctor: " << doctor_->getFirstName() << " " << doctor_->getSurname() << endl;
    }
    cout << "Date/Time: " << dateTime_ << endl;
    cout << "Reason: " << reason_ << endl;
    cout << "Status: " << (isCompleted_ ? "Completed" : "Scheduled") << endl;
    cout << "Cost: $" << cost_ << endl;
}