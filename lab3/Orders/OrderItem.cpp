#include "OrderItem.h"
#include "../Restaurants/MenuItem.h"

OrderItem::OrderItem(int orderItemId, MenuItem* menuItem, int quantity, const string& specialInstructions)
    : orderItemId_(orderItemId), menuItem_(menuItem), quantity_(quantity), specialInstructions_(specialInstructions) {
    if (menuItem_) {
        price_ = menuItem_->getPrice();
        calculateSubtotal();
    } else {
        price_ = 0.0;
        subtotal_ = 0.0;
    }
}

OrderItem::~OrderItem() {
    menuItem_ = nullptr;
}

void OrderItem::setQuantity(int quantity) {
    if (quantity > 0) {
        quantity_ = quantity;
        calculateSubtotal();
    }
}

void OrderItem::calculateSubtotal() {
    subtotal_ = price_ * quantity_;
}

void OrderItem::print() const {
    cout << "Order Item ID: " << orderItemId_ << endl;
    cout << "Quantity: " << quantity_ << endl;
    cout << "Price: $" << fixed << setprecision(2) << price_ << endl;
    cout << "Subtotal: $" << fixed << setprecision(2) << subtotal_ << endl;
    if (!specialInstructions_.empty()) {
        cout << "Special Instructions: " << specialInstructions_ << endl;
    }
}


