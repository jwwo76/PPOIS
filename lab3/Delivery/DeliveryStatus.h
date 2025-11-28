#pragma once
#include "../pch.h"

class Delivery;

class DeliveryStatus{
    private:
        int statusId_;
        Delivery* delivery_;
        string statusName_;
        string description_;
        string timestamp_;
    public:
        DeliveryStatus(int statusId, Delivery* delivery, const string& statusName, const string& description);
        ~DeliveryStatus();

        int getStatusId() const { return statusId_; }
        Delivery* getDelivery() const { return delivery_; }
        string getStatusName() const { return statusName_; }
        string getDescription() const { return description_; }
        string getTimestamp() const { return timestamp_; }

        void setStatusId(int id) { statusId_ = id; }
        void setDelivery(Delivery* delivery);
        void setStatusName(const string& name) { statusName_ = name; }
        void setDescription(const string& desc) { description_ = desc; }
        void setTimestamp(const string& time) { timestamp_ = time; }

        void print() const;
};


