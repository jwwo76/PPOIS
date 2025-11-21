#include "Cleaner.h"
#include "../Core/Department.h"

void Cleaner::work(){
        cout << getFirstName() << " " << getSurname() << " is cleaning assigned departments using " << equipment_ << "." << endl;
}

void Cleaner::assignDepartment(Department* dept) {
        assignedDepartments_.push_back(dept);
    }

void Cleaner::clearDepartments() {
        assignedDepartments_.clear();
    }

const vector<Department*>& Cleaner::getAssignedDepartments() const {
        return assignedDepartments_;
    }



void Cleaner::print() const{
    Employee::print();
        cout << "Work shift: " << workShift_ << endl;
        cout << "Equipment: " << equipment_ << endl;

        cout << "Assigned departments: ";
        if (assignedDepartments_.empty()) {
            cout << "none";
        } else {
            for (const auto& dept : assignedDepartments_)
                cout << dept->getName();
        }
        cout << endl;


}
        

