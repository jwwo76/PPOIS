#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"
#include "../Persons/Doctor.h"

class TherapyService {
private:
    int therapyId_;
    Patient* patient_;
    Doctor* therapist_;
    string therapyType_;
    string date_;
    int sessionNumber_;
    int totalSessions_;
    string notes_;

public:
    TherapyService(Patient* patient, Doctor* therapist, const string& therapyType,
                  const string& date, int totalSessions = 10, int therapyId = 0);
    
    int getTherapyId() const { return therapyId_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getTherapist() const { return therapist_; }
    string getTherapyType() const { return therapyType_; }
    string getDate() const { return date_; }
    int getSessionNumber() const { return sessionNumber_; }
    int getTotalSessions() const { return totalSessions_; }
    string getNotes() const { return notes_; }

    void setTherapyType(const string& type) { therapyType_ = type; }
    void setDate(const string& date) { date_ = date; }
    void setTotalSessions(int sessions) { if(sessions > 0) totalSessions_ = sessions; }
    void setNotes(const string& notes) { notes_ = notes; }

    void conductSession();
    void addNotes(const string& notes);
    void completeSession();
    bool isCompleted() const;
    void print() const;
};

