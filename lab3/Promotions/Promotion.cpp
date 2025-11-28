#include "Promotion.h"
#include "../Restaurants/Restaurant.h"

Promotion::Promotion(int promotionId, Restaurant* restaurant, double discountPercentage)
    : promotionId_(promotionId), restaurant_(restaurant), discountPercentage_(discountPercentage), isActive_(true) {}

Promotion::~Promotion() {
    restaurant_ = nullptr;
}

void Promotion::setDiscountPercentage(double percentage) {
    if (percentage >= 0.0 && percentage <= 100.0) {
        discountPercentage_ = percentage;
    }
}

void Promotion::print() const {
    cout << "Promotion ID: " << promotionId_ << endl;
    cout << "Discount: " << discountPercentage_ << "%" << endl;
    cout << "Active: " << (isActive_ ? "Yes" : "No") << endl;
}


