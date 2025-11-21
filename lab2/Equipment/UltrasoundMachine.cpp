#include "UltrasoundMachine.h"

UltrasoundMachine::UltrasoundMachine(const string& model, const string& serialNumber, Department* department,
                                    const string& probeType, int frequency, bool dopplerEnabled)
    : MedicalEquipment("Ultrasound Machine", model, serialNumber, department, true, ""),
      probeType_(probeType), frequency_(frequency), dopplerEnabled_(dopplerEnabled) {}

void UltrasoundMachine::performUltrasound() {
    if (!getIsFunctional()) {
        cout << "Ultrasound machine is not functional" << endl;
        return;
    }
    cout << "Ultrasound scan performed with " << probeType_ << " probe at " << frequency_ << " MHz" << endl;
}

void UltrasoundMachine::enableDoppler() {
    dopplerEnabled_ = true;
    cout << "Doppler mode enabled" << endl;
}

void UltrasoundMachine::disableDoppler() {
    dopplerEnabled_ = false;
    cout << "Doppler mode disabled" << endl;
}

void UltrasoundMachine::print() const {
    MedicalEquipment::print();
    cout << "Probe Type: " << probeType_ << endl;
    cout << "Frequency: " << frequency_ << " MHz" << endl;
    cout << "Doppler: " << (dopplerEnabled_ ? "Enabled" : "Disabled") << endl;
}



