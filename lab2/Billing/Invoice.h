#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"

class Invoice {
private:
    int invoiceId_;
    Patient* patient_;
    string issueDate_;
    string dueDate_;
    double amount_;
    string status_;
    string paymentMethod_;

public:
    Invoice(Patient* patient, const string& issueDate, const string& dueDate, double amount, int invoiceId = 0);
    
    int getInvoiceId() const { return invoiceId_; }
    Patient* getPatient() const { return patient_; }
    double getAmount() const { return amount_; }
    string getStatus() const { return status_; }

    void markAsPaid(const string& paymentMethod);
    void markAsOverdue();
    bool isOverdue() const;
    void print() const;
};

