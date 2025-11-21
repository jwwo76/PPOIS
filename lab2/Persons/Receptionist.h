#pragma once
#include "Employee.h"

class Polyclinic;

class Receptionist : public Employee {
private:
    Polyclinic* polyclinic_;
    string workShift_;
    int appointmentsPerDay_;

public:
    Receptionist(const string& fName, const string& sName, int age,
            int id, double salary, int experience,
            Polyclinic* polyclinic, const string& workShift = "Day",
            int appointmentsPerDay = 20)
        : Employee(fName, sName, age, id, "Receptionist", salary, experience),
          polyclinic_(polyclinic), workShift_(workShift), appointmentsPerDay_(appointmentsPerDay) {}

    void work() override;
    void print() const override;

    Polyclinic* getPolyclinic() const { return polyclinic_; }
    string getWorkShift() const { return workShift_; }
    int getAppointmentsPerDay() const { return appointmentsPerDay_; }

    void setPolyclinic(Polyclinic* polyclinic) { polyclinic_ = polyclinic; }
    void setWorkShift(const string& shift) { workShift_ = shift; }
    void setAppointmentsPerDay(int appointments) { if(appointments > 0) appointmentsPerDay_ = appointments; }
};



