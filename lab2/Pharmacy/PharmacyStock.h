#pragma once
#include "../pch.h"
#include "Medication.h"

class PharmacyStock {
private:
    vector<Medication*> medications_;
    int totalItems_;
    double totalValue_;

public:
    PharmacyStock();
    
    const vector<Medication*>& getMedications() const { return medications_; }
    int getTotalItems() const { return totalItems_; }
    double getTotalValue() const { return totalValue_; }

    void addMedication(Medication* medication);
    void removeMedication(Medication* medication);
    Medication* findMedication(const string& name);
    void updateStock();
    void print() const;
};



