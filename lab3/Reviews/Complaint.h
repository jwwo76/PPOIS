#pragma once
#include "../pch.h"

class Customer;
class Order;

class Complaint{
    private:
        int complaintId_;
        Customer* customer_;
        Order* order_;
        string complaintType_;
        string description_;
        string complaintDate_;
        string status_;
        string resolution_;
    public:
        Complaint(int complaintId, Customer* customer, Order* order, const string& complaintType, const string& description, const string& complaintDate);
        ~Complaint();

        int getComplaintId() const { return complaintId_; }
        Customer* getCustomer() const { return customer_; }
        Order* getOrder() const { return order_; }
        string getStatus() const { return status_; }
        string getResolution() const { return resolution_; }

        void setStatus(const string& status) { status_ = status; }
        void setResolution(const string& resolution) { resolution_ = resolution; }
        void resolve(const string& resolution);

        void print() const;
};


