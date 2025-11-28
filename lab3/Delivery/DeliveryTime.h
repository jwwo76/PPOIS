#pragma once
#include "../pch.h"

class Delivery;

class DeliveryTime{
    private:
        int timeId_;
        Delivery* delivery_;
        string estimatedTime_;
        string actualTime_;
        int estimatedMinutes_;
        int actualMinutes_;
    public:
        DeliveryTime(int timeId, Delivery* delivery, const string& estimatedTime, int estimatedMinutes);
        ~DeliveryTime();

        int getTimeId() const { return timeId_; }
        Delivery* getDelivery() const { return delivery_; }
        string getEstimatedTime() const { return estimatedTime_; }
        string getActualTime() const { return actualTime_; }

        void setActualTime(const string& time) { actualTime_ = time; }
        int calculateDelay() const;

        void print() const;
};


