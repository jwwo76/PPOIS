#include "BloodPressureMonitor.h"

BloodPressureMonitor::BloodPressureMonitor(const string& model, const string& serialNumber, Department* department,
                                          const string& cuffSize, bool isDigital)
    : MedicalEquipment("Blood Pressure Monitor", model, serialNumber, department, true, ""),
      cuffSize_(cuffSize), isDigital_(isDigital), lastSystolic_(0), lastDiastolic_(0) {}

void BloodPressureMonitor::measureBloodPressure(int systolic, int diastolic) {
    if (!getIsFunctional()) {
        cout << "Blood pressure monitor is not functional" << endl;
        return;
    }
    lastSystolic_ = systolic;
    lastDiastolic_ = diastolic;
    string type = isDigital_ ? "Digital" : "Manual";
    cout << type << " measurement: " << systolic << "/" << diastolic << " mmHg" << endl;
}

void BloodPressureMonitor::print() const {
    MedicalEquipment::print();
    cout << "Cuff Size: " << cuffSize_ << endl;
    cout << "Type: " << (isDigital_ ? "Digital" : "Manual") << endl;
    if (lastSystolic_ > 0 && lastDiastolic_ > 0)
        cout << "Last Reading: " << lastSystolic_ << "/" << lastDiastolic_ << " mmHg" << endl;
}



