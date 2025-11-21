#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"
#include "../Persons/Doctor.h"

class LabReport {
private:
    int reportId_;
    Patient* patient_;
    Doctor* requestingDoctor_;
    string testDate_;
    string testType_;
    string results_;
    string normalRange_;
    bool isNormal_;

public:
    LabReport(Patient* patient, Doctor* requestingDoctor, const string& testDate,
             const string& testType, const string& normalRange = "", int reportId = 0);
    
    int getReportId() const { return reportId_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getRequestingDoctor() const { return requestingDoctor_; }
    string getTestDate() const { return testDate_; }
    string getTestType() const { return testType_; }
    string getResults() const { return results_; }
    string getNormalRange() const { return normalRange_; }
    bool getIsNormal() const { return isNormal_; }

    void setTestDate(const string& date) { testDate_ = date; }
    void setTestType(const string& type) { testType_ = type; }
    void setResults(const string& results);
    void setNormalRange(const string& range) { normalRange_ = range; }

    void analyzeResults();
    void print() const;
};

