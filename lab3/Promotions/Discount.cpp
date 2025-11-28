#include "Discount.h"
#include "../Orders/Order.h"

Discount::Discount(int discountId, const string& discountCode, double discountAmount, double discountPercentage, const string& discountType, Order* order)
    : discountId_(discountId), discountCode_(discountCode), discountAmount_(discountAmount), discountPercentage_(discountPercentage), discountType_(discountType), order_(order), isUsed_(false) {}

Discount::~Discount() {
    order_ = nullptr;
}

double Discount::calculateDiscount(double amount) const {
    if (discountType_ == "Percentage") {
        return amount * (discountPercentage_ / 100.0);
    } else {
        return discountAmount_;
    }
}

void Discount::print() const {
    cout << "Discount ID: " << discountId_ << endl;
    cout << "Code: " << discountCode_ << endl;
    cout << "Type: " << discountType_ << endl;
    cout << "Amount: $" << fixed << setprecision(2) << discountAmount_ << endl;
    cout << "Percentage: " << discountPercentage_ << "%" << endl;
    cout << "Used: " << (isUsed_ ? "Yes" : "No") << endl;
}


