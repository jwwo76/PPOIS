#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"
#include "../Persons/Doctor.h"

class SurgeryReport {
private:
    int reportId_;
    Patient* patient_;
    Doctor* surgeon_;
    string surgeryDate_;
    string surgeryType_;
    string procedure_;
    string complications_;
    string recoveryNotes_;
    bool wasSuccessful_;

public:
    SurgeryReport(Patient* patient, Doctor* surgeon, const string& surgeryDate,
                 const string& surgeryType, const string& procedure, int reportId = 0);
    
    int getReportId() const { return reportId_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getSurgeon() const { return surgeon_; }
    string getSurgeryDate() const { return surgeryDate_; }
    string getSurgeryType() const { return surgeryType_; }
    string getProcedure() const { return procedure_; }
    string getComplications() const { return complications_; }
    string getRecoveryNotes() const { return recoveryNotes_; }
    bool getWasSuccessful() const { return wasSuccessful_; }

    void setSurgeryDate(const string& date) { surgeryDate_ = date; }
    void setSurgeryType(const string& type) { surgeryType_ = type; }
    void setProcedure(const string& procedure) { procedure_ = procedure; }
    void setComplications(const string& complications) { complications_ = complications; }
    void setRecoveryNotes(const string& notes) { recoveryNotes_ = notes; }
    void setWasSuccessful(bool success) { wasSuccessful_ = success; }

    void addComplications(const string& complications);
    void addRecoveryNotes(const string& notes);
    void markSuccessful();
    void print() const;
};

