#include "Receptionist.h"
#include "../Core/Polyclinic.h"

void Receptionist::work(){
    cout << "Receptionist " << getFirstName() << " " << getSurname()
             << " is handling appointments during " << workShift_ << " shift";
        if (polyclinic_)
            cout << " at " << polyclinic_->getName();
        else
            cout << " (polyclinic not assigned)";
        cout << endl;
}

void Receptionist::print() const{
    Employee::print();
    cout << "Work Shift: " << workShift_ << endl;
    cout << "Appointments Per Day: " << appointmentsPerDay_ << endl;
    cout << "Polyclinic: ";
    if (polyclinic_) cout << polyclinic_->getName(); else cout << "not assigned";
    cout << endl;
}



