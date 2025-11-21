#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"
#include "../Persons/Doctor.h"

class LabTest {
private:
    int testId_;
    Patient* patient_;
    Doctor* requestingDoctor_;
    string testType_;
    string date_;
    string result_;
    bool isCompleted_;

public:
    LabTest(Patient* patient, Doctor* requestingDoctor, const string& testType, const string& date, int testId = 0);
    
    int getTestId() const { return testId_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getRequestingDoctor() const { return requestingDoctor_; }
    string getTestType() const { return testType_; }
    string getResult() const { return result_; }
    bool getIsCompleted() const { return isCompleted_; }

    void setResult(const string& result);

    void performTest();
    void completeTest(const string& result);
    void print() const;
};

