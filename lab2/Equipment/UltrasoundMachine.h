#pragma once
#include "MedicalEquipment.h"

class UltrasoundMachine : public MedicalEquipment {
private:
    string probeType_;
    int frequency_;
    bool dopplerEnabled_;

public:
    UltrasoundMachine(const string& model, const string& serialNumber, Department* department,
                     const string& probeType = "Linear", int frequency = 5, bool dopplerEnabled = false);
    
    bool getDopplerEnabled() const { return dopplerEnabled_; }

    void setDopplerEnabled(bool enabled) { dopplerEnabled_ = enabled; }

    void performUltrasound();
    void enableDoppler();
    void disableDoppler();
    void print() const override;
};



