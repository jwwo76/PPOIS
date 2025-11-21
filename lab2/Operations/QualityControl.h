#pragma once
#include "../pch.h"

class QualityControl {
private:
    int controlId_;
    string date_;
    string department_;
    string inspector_;
    vector<string> issues_;
    vector<string> recommendations_;
    int score_;

public:
    QualityControl(const string& date, const string& department, const string& inspector, int controlId = 0);
    
    int getControlId() const { return controlId_; }
    string getDepartment() const { return department_; }
    const vector<string>& getIssues() const { return issues_; }
    const vector<string>& getRecommendations() const { return recommendations_; }
    int getScore() const { return score_; }

    void addIssue(const string& issue);
    void addRecommendation(const string& recommendation);
    void calculateScore();
    void print() const;
};

