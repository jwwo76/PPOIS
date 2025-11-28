#pragma once
#include "../pch.h"

class Order;

class OrderStatus{
    private:
        int statusId_;
        string statusName_;
        string description_;
        string timestamp_;
        Order* order_;
    public:
        OrderStatus(int statusId, const string& statusName, const string& description, Order* order);
        ~OrderStatus();

        int getStatusId() const { return statusId_; }
        string getStatusName() const { return statusName_; }
        string getDescription() const { return description_; }
        string getTimestamp() const { return timestamp_; }
        Order* getOrder() const { return order_; }

        void setStatusId(int id) { statusId_ = id; }
        void setStatusName(const string& name) { statusName_ = name; }
        void setDescription(const string& desc) { description_ = desc; }
        void setTimestamp(const string& time) { timestamp_ = time; }
        void setOrder(Order* order);

        void print() const;
};


