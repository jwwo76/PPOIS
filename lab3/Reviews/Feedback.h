#pragma once
#include "../pch.h"

class Customer;
class Order;

class Feedback{
    private:
        int feedbackId_;
        Customer* customer_;
        Order* order_;
        string feedbackType_;
        string message_;
        string feedbackDate_;
        bool isResolved_;
    public:
        Feedback(int feedbackId, Customer* customer, Order* order, const string& feedbackType, const string& message, const string& feedbackDate);
        ~Feedback();

        int getFeedbackId() const { return feedbackId_; }
        Customer* getCustomer() const { return customer_; }
        string getMessage() const { return message_; }
        bool getIsResolved() const { return isResolved_; }

        void resolve() { isResolved_ = true; }

        void print() const;
};


