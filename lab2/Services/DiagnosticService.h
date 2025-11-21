#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"
#include "../Persons/Doctor.h"

class DiagnosticService {
private:
    int serviceId_;
    Patient* patient_;
    Doctor* doctor_;
    string testType_;
    string date_;
    string result_;
    bool isCompleted_;

public:
    DiagnosticService(Patient* patient, Doctor* doctor, const string& testType, const string& date, int serviceId = 0);
    
    int getServiceId() const { return serviceId_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getDoctor() const { return doctor_; }
    string getTestType() const { return testType_; }
    string getResult() const { return result_; }
    bool getIsCompleted() const { return isCompleted_; }

    void setResult(const string& result) { result_ = result; }

    void performTest();
    void completeTest(const string& result);
    void print() const;
};

