#include "Maintenance.h"

Maintenance::Maintenance(MedicalEquipment* equipment, const string& scheduledDate,
                        const string& maintenanceType, int maintenanceId)
    : maintenanceId_(maintenanceId), equipment_(equipment), scheduledDate_(scheduledDate),
      completedDate_(""), maintenanceType_(maintenanceType), notes_(""), isCompleted_(false) {}

void Maintenance::completeMaintenance(const string& completedDate, const string& notes) {
    completedDate_ = completedDate;
    notes_ = notes;
    isCompleted_ = true;
    if (equipment_) {
        equipment_->performMaintenance();
    }
    cout << "Maintenance #" << maintenanceId_ << " completed" << endl;
}

void Maintenance::print() const {
    cout << "=== Maintenance #" << maintenanceId_ << " ===" << endl;
    if (equipment_) {
        cout << "Equipment: " << equipment_->getName() << endl;
    }
    cout << "Type: " << maintenanceType_ << endl;
    cout << "Scheduled Date: " << scheduledDate_ << endl;
    cout << "Status: " << (isCompleted_ ? "Completed" : "Pending") << endl;
    if (!completedDate_.empty())
        cout << "Completed Date: " << completedDate_ << endl;
    if (!notes_.empty())
        cout << "Notes: " << notes_ << endl;
}

