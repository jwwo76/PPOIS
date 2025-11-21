#include "TestResult.h"
#include "LabTest.h"

TestResult::TestResult(LabTest* test, const string& resultDate, const string& values,
                      const string& normalRange, int resultId)
    : resultId_(resultId), test_(test), resultDate_(resultDate), values_(values),
      normalRange_(normalRange), interpretation_("") {}

void TestResult::interpretResults() {
    if (!normalRange_.empty() && !values_.empty()) {
        interpretation_ = "Results analyzed";
        cout << "Results interpreted for test #" << (test_ ? test_->getTestId() : 0) << endl;
    }
}

void TestResult::print() const {
    cout << "=== Test Result #" << resultId_ << " ===" << endl;
    if (test_) {
        cout << "Test ID: " << test_->getTestId() << endl;
    }
    cout << "Result Date: " << resultDate_ << endl;
    cout << "Values: " << values_ << endl;
    if (!normalRange_.empty())
        cout << "Normal Range: " << normalRange_ << endl;
    if (!interpretation_.empty())
        cout << "Interpretation: " << interpretation_ << endl;
}

