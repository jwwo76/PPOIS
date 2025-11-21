#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"

class Bill {
private:
    int billId_;
    Patient* patient_;
    string date_;
    double totalAmount_;
    double paidAmount_;
    string status_;
    vector<string> services_;

public:
    Bill(Patient* patient, const string& date, double totalAmount, int billId = 0);
    
    int getBillId() const { return billId_; }
    Patient* getPatient() const { return patient_; }
    double getTotalAmount() const { return totalAmount_; }
    double getBalance() const { return totalAmount_ - paidAmount_; }
    string getStatus() const { return status_; }

    void addService(const string& service);
    void makePayment(double amount);
    void updateStatus();
    void print() const;
};

