#include "TherapyService.h"

TherapyService::TherapyService(Patient* patient, Doctor* therapist, const string& therapyType,
                               const string& date, int totalSessions, int therapyId)
    : therapyId_(therapyId), patient_(patient), therapist_(therapist), therapyType_(therapyType),
      date_(date), sessionNumber_(0), totalSessions_(totalSessions), notes_("") {}

void TherapyService::conductSession() {
    if (sessionNumber_ >= totalSessions_) {
        cout << "All therapy sessions completed" << endl;
        return;
    }
    sessionNumber_++;
    if (patient_ && therapist_) {
        cout << "Therapy session " << sessionNumber_ << "/" << totalSessions_ << " conducted" << endl;
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Therapist: " << therapist_->getFirstName() << " " << therapist_->getSurname() << endl;
    }
}

void TherapyService::addNotes(const string& notes) {
    if (!notes_.empty()) notes_ += "\n";
    notes_ += notes;
}

void TherapyService::completeSession() {
    cout << "Session " << sessionNumber_ << " completed" << endl;
}

bool TherapyService::isCompleted() const {
    return sessionNumber_ >= totalSessions_;
}

void TherapyService::print() const {
    cout << "=== Therapy Service #" << therapyId_ << " ===" << endl;
    if (patient_ && therapist_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Therapist: " << therapist_->getFirstName() << " " << therapist_->getSurname() << endl;
    }
    cout << "Type: " << therapyType_ << endl;
    cout << "Date: " << date_ << endl;
    cout << "Progress: " << sessionNumber_ << "/" << totalSessions_ << " sessions" << endl;
    if (!notes_.empty())
        cout << "Notes: " << notes_ << endl;
}

