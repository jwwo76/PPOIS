#include "QualityControl.h"

QualityControl::QualityControl(const string& date, const string& department, const string& inspector, int controlId)
    : controlId_(controlId), date_(date), department_(department), inspector_(inspector), score_(0) {}

void QualityControl::addIssue(const string& issue) {
    issues_.push_back(issue);
}

void QualityControl::addRecommendation(const string& recommendation) {
    recommendations_.push_back(recommendation);
}

void QualityControl::calculateScore() {
    int baseScore = 100;
    score_ = baseScore - (issues_.size() * 10);
    if (score_ < 0) score_ = 0;
    cout << "Quality score calculated: " << score_ << "/100" << endl;
}

void QualityControl::print() const {
    cout << "=== Quality Control #" << controlId_ << " ===" << endl;
    cout << "Date: " << date_ << endl;
    cout << "Department: " << department_ << endl;
    cout << "Inspector: " << inspector_ << endl;
    cout << "Score: " << score_ << "/100" << endl;
    cout << "Issues: " << issues_.size() << endl;
    for (size_t i = 0; i < issues_.size(); ++i) {
        cout << "  " << (i + 1) << ". " << issues_[i] << endl;
    }
    cout << "Recommendations: " << recommendations_.size() << endl;
    for (size_t i = 0; i < recommendations_.size(); ++i) {
        cout << "  " << (i + 1) << ". " << recommendations_[i] << endl;
    }
}

