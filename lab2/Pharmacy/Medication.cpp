#include "Medication.h"

Medication::Medication(const string& name, const string& genericName, const string& manufacturer,
                      int quantity, double price, const string& expiryDate, const string& prescriptionRequired)
    : name_(name), genericName_(genericName), manufacturer_(manufacturer), quantity_(quantity),
      price_(price), expiryDate_(expiryDate), prescriptionRequired_(prescriptionRequired) {}

void Medication::dispense(int amount) {
    if (amount > 0 && amount <= quantity_) {
        quantity_ -= amount;
        cout << "Dispensed " << amount << " units of " << name_ << ". Remaining: " << quantity_ << endl;
    } else {
        cout << "Insufficient stock" << endl;
    }
}

void Medication::restock(int amount) {
    if (amount > 0) {
        quantity_ += amount;
        cout << "Restocked " << amount << " units of " << name_ << ". Total: " << quantity_ << endl;
    }
}

bool Medication::isExpired() const {
    return false;
}

void Medication::print() const {
    cout << "=== Medication ===" << endl;
    cout << "Name: " << name_ << endl;
    cout << "Generic Name: " << genericName_ << endl;
    cout << "Manufacturer: " << manufacturer_ << endl;
    cout << "Quantity: " << quantity_ << endl;
    cout << "Price: $" << price_ << endl;
    cout << "Expiry Date: " << expiryDate_ << endl;
    cout << "Prescription Required: " << prescriptionRequired_ << endl;
}



