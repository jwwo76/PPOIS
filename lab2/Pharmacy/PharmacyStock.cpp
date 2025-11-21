#include "PharmacyStock.h"

PharmacyStock::PharmacyStock()
    : totalItems_(0), totalValue_(0.0) {}

void PharmacyStock::addMedication(Medication* medication) {
    if (medication) {
        medications_.push_back(medication);
        updateStock();
    }
}

void PharmacyStock::removeMedication(Medication* medication) {
    auto it = remove(medications_.begin(), medications_.end(), medication);
    medications_.erase(it, medications_.end());
    updateStock();
}

Medication* PharmacyStock::findMedication(const string& name) {
    for (auto* med : medications_) {
        if (med && med->getName() == name) {
            return med;
        }
    }
    return nullptr;
}

void PharmacyStock::updateStock() {
    totalItems_ = medications_.size();
    totalValue_ = 0.0;
    for (auto* med : medications_) {
        if (med) {
            totalValue_ += med->getPrice() * med->getQuantity();
        }
    }
}

void PharmacyStock::print() const {
    cout << "=== Pharmacy Stock ===" << endl;
    cout << "Total Items: " << totalItems_ << endl;
    cout << "Total Value: $" << totalValue_ << endl;
    cout << "Medications: " << medications_.size() << endl;
    for (size_t i = 0; i < medications_.size(); ++i) {
        if (medications_[i]) {
            cout << "  " << (i + 1) << ". " << medications_[i]->getName() << endl;
        }
    }
}



