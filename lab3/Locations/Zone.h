#pragma once
#include "../pch.h"

class Address;

class Zone{
    private:
        int zoneId_;
        string zoneName_;
        vector<Address*> addresses_;
        double deliveryFee_;
        int estimatedDeliveryTime_;
    public:
        Zone(int zoneId, const string& zoneName, double deliveryFee, int estimatedDeliveryTime);
        ~Zone();

        int getZoneId() const { return zoneId_; }
        string getZoneName() const { return zoneName_; }
        vector<Address*> getAddresses() const { return addresses_; }
        double getDeliveryFee() const { return deliveryFee_; }
        int getEstimatedDeliveryTime() const { return estimatedDeliveryTime_; }

        void setZoneId(int id) { zoneId_ = id; }
        void setZoneName(const string& name) { zoneName_ = name; }
        void setDeliveryFee(double fee) { deliveryFee_ = fee; }
        void setEstimatedDeliveryTime(int time) { estimatedDeliveryTime_ = time; }
        void addAddress(Address* address);
        void removeAddress(Address* address);

        void print() const;
};


