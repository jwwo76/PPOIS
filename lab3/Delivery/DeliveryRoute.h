#pragma once
#include "../pch.h"

class Address;
class Delivery;

class DeliveryRoute{
    private:
        int routeId_;
        Address* startPoint_;
        Address* endPoint_;
        vector<Address*> waypoints_;
        double distance_;
        int estimatedTime_;
        vector<Delivery*> deliveries_;
    public:
        DeliveryRoute(int routeId, Address* startPoint, Address* endPoint, double distance, int estimatedTime);
        ~DeliveryRoute();

        int getRouteId() const { return routeId_; }
        double getDistance() const { return distance_; }
        int getEstimatedTime() const { return estimatedTime_; }

        void addWaypoint(Address* waypoint);
        void addDelivery(Delivery* delivery);
        void removeDelivery(Delivery* delivery);
        void calculateDistance();

        void print() const;
};


