#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"

class Insurance {
private:
    string policyNumber_;
    Patient* patient_;
    string insuranceCompany_;
    string policyType_;
    double coverageAmount_;
    double remainingCoverage_;
    string expiryDate_;

public:
    Insurance(const string& policyNumber, Patient* patient, const string& insuranceCompany,
             const string& policyType, double coverageAmount, const string& expiryDate);
    
    string getPolicyNumber() const { return policyNumber_; }
    Patient* getPatient() const { return patient_; }
    string getInsuranceCompany() const { return insuranceCompany_; }
    string getPolicyType() const { return policyType_; }
    double getCoverageAmount() const { return coverageAmount_; }
    double getRemainingCoverage() const { return remainingCoverage_; }
    string getExpiryDate() const { return expiryDate_; }

    void setPolicyNumber(const string& number) { policyNumber_ = number; }
    void setInsuranceCompany(const string& company) { insuranceCompany_ = company; }
    void setPolicyType(const string& type) { policyType_ = type; }
    void setExpiryDate(const string& date) { expiryDate_ = date; }

    void useCoverage(double amount);
    bool isExpired() const;
    bool hasCoverage() const;
    void print() const;
};



