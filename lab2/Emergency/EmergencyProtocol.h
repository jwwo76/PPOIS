#pragma once
#include "../pch.h"

class EmergencyProtocol {
private:
    int protocolId_;
    string protocolName_;
    string description_;
    vector<string> steps_;
    string category_;

public:
    EmergencyProtocol(const string& protocolName, const string& description, const string& category, int protocolId = 0);
    
    int getProtocolId() const { return protocolId_; }
    string getProtocolName() const { return protocolName_; }
    string getDescription() const { return description_; }
    const vector<string>& getSteps() const { return steps_; }
    string getCategory() const { return category_; }

    void setProtocolName(const string& name) { protocolName_ = name; }
    void setDescription(const string& desc) { description_ = desc; }
    void setCategory(const string& category) { category_ = category; }

    void addStep(const string& step);
    void executeProtocol();
    void print() const;
};

