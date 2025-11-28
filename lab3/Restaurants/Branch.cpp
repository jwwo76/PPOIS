#include "Branch.h"
#include "Restaurant.h"
#include "../Locations/Address.h"

Branch::Branch(int branchId, Restaurant* restaurant, Address* address, const string& phoneNumber, int capacity)
    : branchId_(branchId), restaurant_(restaurant), address_(address), phoneNumber_(phoneNumber), isOpen_(false), capacity_(capacity) {}

Branch::~Branch() {
    restaurant_ = nullptr;
    address_ = nullptr;
}

void Branch::print() const {
    cout << "Branch ID: " << branchId_ << endl;
    cout << "Phone: " << phoneNumber_ << endl;
    cout << "Status: " << (isOpen_ ? "Open" : "Closed") << endl;
    cout << "Capacity: " << capacity_ << endl;
}


