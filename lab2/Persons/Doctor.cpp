#include "Doctor.h"
#include "../Core/Department.h"

void Doctor::work(){
    cout << "Doctor " << getFirstName() << " " << getSurname()
             << " (" << specialization_ << ") works at";
        if (department_)
            cout << department_->getName();
        else
            cout << "(not found)";
}

void Doctor::print() const{
    Employee::print();
    cout << "Department: ";
    if (department_) cout << department_->getName(); else cout << "not assigned";
    cout << "\nSpecialization: " << specialization_;
}