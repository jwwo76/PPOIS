#pragma once
#include "../pch.h"

class Order;
class Customer;
class PaymentMethod;

class Payment{
    private:
        int paymentId_;
        Order* order_;
        double amount_;
        string status_;
    public:
        Payment(int paymentId, Order* order, double amount);
        ~Payment();

        int getPaymentId() const { return paymentId_; }
        Order* getOrder() const { return order_; }
        double getAmount() const { return amount_; }
        string getStatus() const { return status_; }

        void setStatus(const string& status) { status_ = status; }
        void processPayment();

        void print() const;
};


