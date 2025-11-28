#pragma once
#include "../pch.h"

class Order;
class Delivery;

class OrderTracking{
    private:
        int trackingId_;
        Order* order_;
        Delivery* delivery_;
        string currentLocation_;
        string estimatedArrival_;
        string status_;
        vector<string> trackingHistory_;
    public:
        OrderTracking(int trackingId, Order* order, Delivery* delivery);
        ~OrderTracking();

        int getTrackingId() const { return trackingId_; }
        Order* getOrder() const { return order_; }
        string getCurrentLocation() const { return currentLocation_; }
        string getStatus() const { return status_; }

        void updateLocation(const string& location);
        void updateStatus(const string& status);
        void addTrackingEvent(const string& event);

        void print() const;
};


