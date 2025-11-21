#include "LabReport.h"

LabReport::LabReport(Patient* patient, Doctor* requestingDoctor, const string& testDate,
                     const string& testType, const string& normalRange, int reportId)
    : reportId_(reportId), patient_(patient), requestingDoctor_(requestingDoctor),
      testDate_(testDate), testType_(testType), results_(""), normalRange_(normalRange),
      isNormal_(true) {}

void LabReport::setResults(const string& results) {
    results_ = results;
    analyzeResults();
}

void LabReport::analyzeResults() {
    if (!normalRange_.empty() && !results_.empty()) {
        isNormal_ = true;
        cout << "Results analyzed for " << testType_ << endl;
    }
}

void LabReport::print() const {
    cout << "=== Lab Report #" << reportId_ << " ===" << endl;
    if (patient_ && requestingDoctor_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Requesting Doctor: " << requestingDoctor_->getFirstName() << " " << requestingDoctor_->getSurname() << endl;
    }
    cout << "Test Date: " << testDate_ << endl;
    cout << "Test Type: " << testType_ << endl;
    if (!results_.empty())
        cout << "Results: " << results_ << endl;
    if (!normalRange_.empty())
        cout << "Normal Range: " << normalRange_ << endl;
    cout << "Status: " << (isNormal_ ? "Normal" : "Abnormal") << endl;
}

