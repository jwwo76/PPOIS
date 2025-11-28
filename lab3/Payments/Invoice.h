#pragma once
#include "../pch.h"

class Order;
class Customer;

class Invoice{
    private:
        int invoiceId_;
        Order* order_;
        Customer* customer_;
        double totalAmount_;
        double taxAmount_;
        double discountAmount_;
        string invoiceDate_;
        string dueDate_;
        string status_;
    public:
        Invoice(int invoiceId, Order* order, Customer* customer, double totalAmount, const string& invoiceDate);
        ~Invoice();

        int getInvoiceId() const { return invoiceId_; }
        Order* getOrder() const { return order_; }
        Customer* getCustomer() const { return customer_; }
        double getTotalAmount() const { return totalAmount_; }
        string getStatus() const { return status_; }

        void setTaxAmount(double amount) { taxAmount_ = amount; }
        void setDiscountAmount(double amount) { discountAmount_ = amount; }
        void setStatus(const string& status) { status_ = status; }
        void calculateTotal();

        void print() const;
};


