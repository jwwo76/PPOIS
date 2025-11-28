#pragma once
#include "../pch.h"

class Order;

class Discount{
    private:
        int discountId_;
        string discountCode_;
        double discountAmount_;
        double discountPercentage_;
        string discountType_;
        Order* order_;
        bool isUsed_;
    public:
        Discount(int discountId, const string& discountCode, double discountAmount, double discountPercentage, const string& discountType, Order* order);
        ~Discount();

        int getDiscountId() const { return discountId_; }
        string getDiscountCode() const { return discountCode_; }
        double getDiscountAmount() const { return discountAmount_; }
        bool getIsUsed() const { return isUsed_; }

        void apply() { isUsed_ = true; }
        double calculateDiscount(double amount) const;

        void print() const;
};


