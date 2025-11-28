#include "Shift.h"
#include "../Persons/Employee.h"

Shift::Shift(int shiftId, Employee* employee, const string& shiftDate)
    : shiftId_(shiftId), employee_(employee), shiftDate_(shiftDate), isCompleted_(false) {}

Shift::~Shift() {
    employee_ = nullptr;
}

void Shift::print() const {
    cout << "Shift ID: " << shiftId_ << endl;
    cout << "Date: " << shiftDate_ << endl;
    cout << "Completed: " << (isCompleted_ ? "Yes" : "No") << endl;
}


