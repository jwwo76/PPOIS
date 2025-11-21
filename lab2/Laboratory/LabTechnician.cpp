#include "LabTechnician.h"

LabTechnician::LabTechnician(const string& fName, const string& sName, int age, int id,
                            double salary, int experience, const string& specialization)
    : Employee(fName, sName, age, id, "Lab Technician", salary, experience),
      specialization_(specialization), testsPerformed_(0) {}

void LabTechnician::work() {
    cout << "Lab Technician " << getFirstName() << " " << getSurname()
         << " is performing laboratory tests in " << specialization_ << endl;
}

void LabTechnician::performTest() {
    testsPerformed_++;
    cout << "Test performed. Total tests: " << testsPerformed_ << endl;
}

void LabTechnician::print() const {
    Employee::print();
    cout << "Specialization: " << specialization_ << endl;
    cout << "Tests Performed: " << testsPerformed_ << endl;
}



