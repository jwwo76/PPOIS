#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"

class Payment {
private:
    int paymentId_;
    Patient* patient_;
    string date_;
    double amount_;
    string paymentMethod_;
    string transactionId_;
    string status_;

public:
    Payment(Patient* patient, const string& date, double amount, const string& paymentMethod, int paymentId = 0);
    
    int getPaymentId() const { return paymentId_; }
    Patient* getPatient() const { return patient_; }
    double getAmount() const { return amount_; }
    string getStatus() const { return status_; }

    void setStatus(const string& status) { status_ = status; }

    void processPayment();
    void confirmPayment(const string& transactionId);
    void print() const;
};

