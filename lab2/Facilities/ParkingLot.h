#pragma once
#include "../pch.h"

class ParkingLot {
private:
    string lotId_;
    int totalSpots_;
    int occupiedSpots_;
    bool isCovered_;
    double hourlyRate_;

public:
    ParkingLot(const string& lotId, int totalSpots, bool isCovered = false, double hourlyRate = 0.0);
    
    string getLotId() const { return lotId_; }
    int getTotalSpots() const { return totalSpots_; }
    int getAvailableSpots() const { return totalSpots_ - occupiedSpots_; }
    double getHourlyRate() const { return hourlyRate_; }

    void setTotalSpots(int spots) { if(spots > 0) totalSpots_ = spots; }
    void setHourlyRate(double rate) { if(rate >= 0) hourlyRate_ = rate; }

    void parkVehicle();
    void releaseSpot();
    bool hasAvailableSpots() const;
    void print() const;
};



