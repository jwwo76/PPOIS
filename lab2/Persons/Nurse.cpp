#include "Nurse.h"
#include "../Core/Department.h"

void Nurse::work(){
    cout << "Nurse " << getFirstName() << " " << getSurname()
             << " (" << specialization_ << ") works at";
        if (department_)
            cout << " " << department_->getName();
        else
            cout << " (not assigned)";
        cout << endl;
}

void Nurse::print() const{
    Employee::print();
    cout << "Department: ";
    if (department_) cout << department_->getName(); else cout << "not assigned";
    cout << "\nSpecialization: " << specialization_ << endl;
    cout << "Patient Capacity: " << patientCapacity_ << endl;
}



