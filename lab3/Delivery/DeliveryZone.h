#pragma once
#include "../pch.h"

class Address;
class Delivery;

class DeliveryZone{
    private:
        int zoneId_;
        string zoneName_;
        vector<Address*> coveredAreas_;
        double deliveryFee_;
        int estimatedDeliveryTime_;
        vector<Delivery*> activeDeliveries_;
    public:
        DeliveryZone(int zoneId, const string& zoneName, double deliveryFee, int estimatedDeliveryTime);
        ~DeliveryZone();

        int getZoneId() const { return zoneId_; }
        string getZoneName() const { return zoneName_; }
        double getDeliveryFee() const { return deliveryFee_; }

        void addCoveredArea(Address* address);
        void addDelivery(Delivery* delivery);
        void removeDelivery(Delivery* delivery);

        void print() const;
};


