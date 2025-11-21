#include "Cabinet.h"

Cabinet::Cabinet(const string& number, Doctor* doctor, Department* department)
    : number_(number), doctor_(doctor), department_(department) {}

Cabinet::Cabinet() 
    : number_("000"), doctor_(nullptr), department_(nullptr) {}

void Cabinet::addInventoryItem(InventoryItem* item) {
    if (item) {
        inventory_.push_back(item);
    }
}

void Cabinet::removeInventoryItem(InventoryItem* item) {
    auto it = remove(inventory_.begin(), inventory_.end(), item);
    inventory_.erase(it, inventory_.end());
}

void Cabinet::print() const {
    cout << "Cabinet " << number_ << endl;
    
    if (doctor_) {
        cout << "Doctor: " << doctor_->getFirstName() << " " << doctor_->getSurname() << endl;
    }
    
    if (department_) {
        cout << "Department: " << department_->getName() << endl;
    }
    
    cout << "Inventory items: " << inventory_.size() << endl;
}