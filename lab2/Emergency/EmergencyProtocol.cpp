#include "EmergencyProtocol.h"

EmergencyProtocol::EmergencyProtocol(const string& protocolName, const string& description, const string& category, int protocolId)
    : protocolId_(protocolId), protocolName_(protocolName), description_(description), category_(category) {}

void EmergencyProtocol::addStep(const string& step) {
    steps_.push_back(step);
}

void EmergencyProtocol::executeProtocol() {
    cout << "Executing protocol: " << protocolName_ << endl;
    for (size_t i = 0; i < steps_.size(); ++i) {
        cout << "Step " << (i + 1) << ": " << steps_[i] << endl;
    }
}

void EmergencyProtocol::print() const {
    cout << "=== Emergency Protocol #" << protocolId_ << " ===" << endl;
    cout << "Name: " << protocolName_ << endl;
    cout << "Category: " << category_ << endl;
    cout << "Description: " << description_ << endl;
    cout << "Steps: " << steps_.size() << endl;
    for (size_t i = 0; i < steps_.size(); ++i) {
        cout << "  " << (i + 1) << ". " << steps_[i] << endl;
    }
}

