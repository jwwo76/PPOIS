#pragma once
#include "../pch.h"

class LabTest;

class TestResult {
private:
    int resultId_;
    LabTest* test_;
    string resultDate_;
    string values_;
    string normalRange_;
    string interpretation_;

public:
    TestResult(LabTest* test, const string& resultDate, const string& values,
              const string& normalRange = "", int resultId = 0);
    
    int getResultId() const { return resultId_; }
    LabTest* getTest() const { return test_; }
    string getResultDate() const { return resultDate_; }
    string getValues() const { return values_; }
    string getNormalRange() const { return normalRange_; }
    string getInterpretation() const { return interpretation_; }

    void setResultDate(const string& date) { resultDate_ = date; }
    void setValues(const string& values) { values_ = values; }
    void setNormalRange(const string& range) { normalRange_ = range; }
    void setInterpretation(const string& interpretation) { interpretation_ = interpretation; }

    void interpretResults();
    void print() const;
};

