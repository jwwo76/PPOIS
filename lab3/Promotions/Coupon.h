#pragma once
#include "../pch.h"

class Customer;
class Restaurant;

class Coupon{
    private:
        int couponId_;
        string couponCode_;
        Customer* customer_;
        Restaurant* restaurant_;
        double discountValue_;
        string discountType_;
        string expiryDate_;
        bool isUsed_;
    public:
        Coupon(int couponId, const string& couponCode, Customer* customer, Restaurant* restaurant, double discountValue, const string& discountType, const string& expiryDate);
        ~Coupon();

        int getCouponId() const { return couponId_; }
        string getCouponCode() const { return couponCode_; }
        double getDiscountValue() const { return discountValue_; }
        bool getIsUsed() const { return isUsed_; }

        void use() { isUsed_ = true; }
        bool isExpired() const;
        void print() const;
};


