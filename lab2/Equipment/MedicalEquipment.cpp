#include "MedicalEquipment.h"
#include "../Core/Department.h"
#include "../Exceptions/Exceptions.h"

MedicalEquipment::MedicalEquipment(const string& name, const string& model, const string& serialNumber,
                                  Department* department, bool isFunctional, const string& lastMaintenanceDate)
    : name_(name), model_(model), serialNumber_(serialNumber), department_(department),
      isFunctional_(isFunctional), lastMaintenanceDate_(lastMaintenanceDate) {}

MedicalEquipment::MedicalEquipment()
    : name_(""), model_(""), serialNumber_(""), department_(nullptr), isFunctional_(true), lastMaintenanceDate_("") {}

void MedicalEquipment::performMaintenance() {
    isFunctional_ = true;
    time_t now = time(0);
    lastMaintenanceDate_ = ctime(&now);
    cout << "Maintenance performed on " << name_ << endl;
}

void MedicalEquipment::reportMalfunction() {
    if (!isFunctional_) {
        Exceptions::throwEquipmentUnavailable("Equipment is already reported as malfunctioning");
    }
    isFunctional_ = false;
    cout << "Malfunction reported for " << name_ << " (Serial: " << serialNumber_ << ")" << endl;
}

void MedicalEquipment::print() const {
    cout << "Equipment: " << name_ << endl;
    cout << "Model: " << model_ << endl;
    cout << "Serial Number: " << serialNumber_ << endl;
    cout << "Status: " << (isFunctional_ ? "Functional" : "Malfunction") << endl;
    if (department_)
        cout << "Department: " << department_->getName() << endl;
    else
        cout << "Department: not assigned" << endl;
    if (!lastMaintenanceDate_.empty())
        cout << "Last Maintenance: " << lastMaintenanceDate_;
}



