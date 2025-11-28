#pragma once
#include "../pch.h"

class Payment;
class Order;

class Receipt{
    private:
        int receiptId_;
        Payment* payment_;
        Order* order_;
        double amount_;
        string receiptDate_;
        string transactionId_;
    public:
        Receipt(int receiptId, Payment* payment, Order* order, double amount, const string& receiptDate);
        ~Receipt();

        int getReceiptId() const { return receiptId_; }
        Payment* getPayment() const { return payment_; }
        Order* getOrder() const { return order_; }
        double getAmount() const { return amount_; }
        string getReceiptDate() const { return receiptDate_; }

        void print() const;
};


