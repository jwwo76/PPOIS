#pragma once
#include "../pch.h"

class Restaurant;

class Promotion{
    private:
        int promotionId_;
        Restaurant* restaurant_;
        double discountPercentage_;
        bool isActive_;
    public:
        Promotion(int promotionId, Restaurant* restaurant, double discountPercentage);
        ~Promotion();

        int getPromotionId() const { return promotionId_; }
        Restaurant* getRestaurant() const { return restaurant_; }
        double getDiscountPercentage() const { return discountPercentage_; }
        bool getIsActive() const { return isActive_; }

        void setDiscountPercentage(double percentage);
        void setIsActive(bool active) { isActive_ = active; }

        void print() const;
};


