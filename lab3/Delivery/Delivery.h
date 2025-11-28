#pragma once
#include "../pch.h"

class Order;
class DeliveryPerson;
class Address;
class Vehicle;

class Delivery{
    private:
        int deliveryId_;
        Order* order_;
        DeliveryPerson* deliveryPerson_;
        Address* deliveryAddress_;
        Vehicle* vehicle_;
        string status_;
        string estimatedTime_;
        string actualTime_;
        double deliveryFee_;
    public:
        Delivery(int deliveryId, Order* order, DeliveryPerson* deliveryPerson, Address* deliveryAddress, double deliveryFee);
        ~Delivery();

        int getDeliveryId() const { return deliveryId_; }
        Order* getOrder() const { return order_; }
        DeliveryPerson* getDeliveryPerson() const { return deliveryPerson_; }
        string getStatus() const { return status_; }
        double getDeliveryFee() const { return deliveryFee_; }

        void setStatus(const string& status) { status_ = status; }
        void completeDelivery();

        void print() const;
};


