#pragma once
#include "MedicalEquipment.h"

class XRayMachine : public MedicalEquipment {
private:
    int radiationLevel_;
    int maxDosePerDay_;
    int currentDoseToday_;
    bool requiresCalibration_;

public:
    XRayMachine(const string& model, const string& serialNumber, Department* department,
                int radiationLevel = 100, int maxDosePerDay = 50);
    
    int getMaxDosePerDay() const { return maxDosePerDay_; }
    int getCurrentDoseToday() const { return currentDoseToday_; }
    bool getRequiresCalibration() const { return requiresCalibration_; }

    void performXRay();
    void calibrate();
    void resetDailyDose();
    void print() const override;
};



