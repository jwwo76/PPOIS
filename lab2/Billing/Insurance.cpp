#include "Insurance.h"

Insurance::Insurance(const string& policyNumber, Patient* patient, const string& insuranceCompany,
                    const string& policyType, double coverageAmount, const string& expiryDate)
    : policyNumber_(policyNumber), patient_(patient), insuranceCompany_(insuranceCompany),
      policyType_(policyType), coverageAmount_(coverageAmount), remainingCoverage_(coverageAmount),
      expiryDate_(expiryDate) {}

void Insurance::useCoverage(double amount) {
    if (hasCoverage() && amount <= remainingCoverage_) {
        remainingCoverage_ -= amount;
        cout << "Coverage used: $" << amount << ". Remaining: $" << remainingCoverage_ << endl;
    } else {
        cout << "Insufficient coverage or insurance expired" << endl;
    }
}

bool Insurance::isExpired() const {
    return false;
}

bool Insurance::hasCoverage() const {
    return remainingCoverage_ > 0 && !isExpired();
}

void Insurance::print() const {
    cout << "=== Insurance ===" << endl;
    cout << "Policy Number: " << policyNumber_ << endl;
    if (patient_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
    }
    cout << "Company: " << insuranceCompany_ << endl;
    cout << "Type: " << policyType_ << endl;
    cout << "Coverage Amount: $" << coverageAmount_ << endl;
    cout << "Remaining Coverage: $" << remainingCoverage_ << endl;
    cout << "Expiry Date: " << expiryDate_ << endl;
}



