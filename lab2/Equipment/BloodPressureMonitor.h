#pragma once
#include "MedicalEquipment.h"

class BloodPressureMonitor : public MedicalEquipment {
private:
    string cuffSize_;
    bool isDigital_;
    int lastSystolic_;
    int lastDiastolic_;

public:
    BloodPressureMonitor(const string& model, const string& serialNumber, Department* department,
                        const string& cuffSize = "Standard", bool isDigital = true);
    
    int getLastSystolic() const { return lastSystolic_; }
    int getLastDiastolic() const { return lastDiastolic_; }

    void measureBloodPressure(int systolic, int diastolic);
    void print() const override;
};



