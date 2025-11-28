#pragma once
#include "../pch.h"

class Payment;

class Transaction{
    private:
        int transactionId_;
        Payment* payment_;
        string transactionType_;
        double amount_;
        string transactionDate_;
        string status_;
        string description_;
    public:
        Transaction(int transactionId, Payment* payment, const string& transactionType, double amount, const string& transactionDate);
        ~Transaction();

        int getTransactionId() const { return transactionId_; }
        Payment* getPayment() const { return payment_; }
        double getAmount() const { return amount_; }
        string getStatus() const { return status_; }

        void setStatus(const string& status) { status_ = status; }
        void process();

        void print() const;
};


