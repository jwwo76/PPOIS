#include "Pharmacist.h"

Pharmacist::Pharmacist(const string& fName, const string& sName, int age, int id,
                      double salary, int experience, const string& licenseNumber)
    : Employee(fName, sName, age, id, "Pharmacist", salary, experience),
      licenseNumber_(licenseNumber), prescriptionsDispensed_(0) {}

void Pharmacist::work() {
    cout << "Pharmacist " << getFirstName() << " " << getSurname()
         << " is dispensing medications. License: " << licenseNumber_ << endl;
}

void Pharmacist::dispensePrescription() {
    prescriptionsDispensed_++;
    cout << "Prescription dispensed. Total: " << prescriptionsDispensed_ << endl;
}

void Pharmacist::print() const {
    Employee::print();
    cout << "License Number: " << licenseNumber_ << endl;
    cout << "Prescriptions Dispensed: " << prescriptionsDispensed_ << endl;
}



