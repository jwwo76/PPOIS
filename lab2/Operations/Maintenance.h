#pragma once
#include "../pch.h"
#include "../Equipment/MedicalEquipment.h"

class Maintenance {
private:
    int maintenanceId_;
    MedicalEquipment* equipment_;
    string scheduledDate_;
    string completedDate_;
    string maintenanceType_;
    string notes_;
    bool isCompleted_;

public:
    Maintenance(MedicalEquipment* equipment, const string& scheduledDate,
               const string& maintenanceType, int maintenanceId = 0);
    
    int getMaintenanceId() const { return maintenanceId_; }
    MedicalEquipment* getEquipment() const { return equipment_; }
    string getScheduledDate() const { return scheduledDate_; }
    string getCompletedDate() const { return completedDate_; }
    string getMaintenanceType() const { return maintenanceType_; }
    string getNotes() const { return notes_; }
    bool getIsCompleted() const { return isCompleted_; }

    void setScheduledDate(const string& date) { scheduledDate_ = date; }
    void setCompletedDate(const string& date) { completedDate_ = date; }
    void setMaintenanceType(const string& type) { maintenanceType_ = type; }
    void setNotes(const string& notes) { notes_ = notes; }

    void completeMaintenance(const string& completedDate, const string& notes);
    void print() const;
};

