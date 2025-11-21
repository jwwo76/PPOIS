#include "LabTest.h"

LabTest::LabTest(Patient* patient, Doctor* requestingDoctor, const string& testType, const string& date, int testId)
    : testId_(testId), patient_(patient), requestingDoctor_(requestingDoctor),
      testType_(testType), date_(date), result_(""), isCompleted_(false) {}

void LabTest::setResult(const string& result) {
    result_ = result;
    completeTest(result);
}

void LabTest::performTest() {
    if (patient_ && requestingDoctor_) {
        cout << "Lab test " << testType_ << " performed for patient "
             << patient_->getFirstName() << " " << patient_->getSurname() << endl;
    }
}

void LabTest::completeTest(const string& result) {
    result_ = result;
    isCompleted_ = true;
    cout << "Lab test #" << testId_ << " completed. Result: " << result_ << endl;
}

void LabTest::print() const {
    cout << "=== Lab Test #" << testId_ << " ===" << endl;
    if (patient_ && requestingDoctor_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Requesting Doctor: " << requestingDoctor_->getFirstName() << " " << requestingDoctor_->getSurname() << endl;
    }
    cout << "Test Type: " << testType_ << endl;
    cout << "Date: " << date_ << endl;
    cout << "Status: " << (isCompleted_ ? "Completed" : "Pending") << endl;
    if (!result_.empty())
        cout << "Result: " << result_ << endl;
}

