#include "XRayMachine.h"

XRayMachine::XRayMachine(const string& model, const string& serialNumber, Department* department,
                        int radiationLevel, int maxDosePerDay)
    : MedicalEquipment("X-Ray Machine", model, serialNumber, department, true, ""),
      radiationLevel_(radiationLevel), maxDosePerDay_(maxDosePerDay), 
      currentDoseToday_(0), requiresCalibration_(false) {}

void XRayMachine::performXRay() {
    if (!getIsFunctional()) {
        cout << "X-Ray machine is not functional" << endl;
        return;
    }
    if (currentDoseToday_ >= maxDosePerDay_) {
        cout << "Maximum daily dose reached" << endl;
        return;
    }
    currentDoseToday_++;
    cout << "X-Ray performed. Dose today: " << currentDoseToday_ << "/" << maxDosePerDay_ << endl;
}

void XRayMachine::calibrate() {
    requiresCalibration_ = false;
    performMaintenance();
    cout << "X-Ray machine calibrated" << endl;
}

void XRayMachine::resetDailyDose() {
    currentDoseToday_ = 0;
    cout << "Daily dose reset" << endl;
}

void XRayMachine::print() const {
    MedicalEquipment::print();
    cout << "Radiation Level: " << radiationLevel_ << endl;
    cout << "Dose Today: " << currentDoseToday_ << "/" << maxDosePerDay_ << endl;
    cout << "Calibration Required: " << (requiresCalibration_ ? "Yes" : "No") << endl;
}



