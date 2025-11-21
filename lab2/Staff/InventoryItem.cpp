#include "InventoryItem.h"

InventoryItem::InventoryItem(const string& name, int quantity, int minStockLevel)
    : name_(name), quantity_(quantity), minStockLevel_(minStockLevel) {
    
    if (quantity_ < 0) quantity_ = 0;
    if (minStockLevel_ < 0) minStockLevel_ = 0;
}

InventoryItem::InventoryItem() 
    : name_("Unnamed"), quantity_(0), minStockLevel_(5) {}


void InventoryItem::updateQuantity(int change) {
    int newQuantity = quantity_ + change;
    if (newQuantity >= 0) {
        quantity_ = newQuantity;
    }
}

bool InventoryItem::needsReorder() const {
    return quantity_ <= minStockLevel_;
}

void InventoryItem::restock(int amount) {
    if (amount > 0) {
        updateQuantity(amount);
    }
}

void InventoryItem::useItem(int amount) {
    if (amount > 0 && amount <= quantity_) {
        updateQuantity(-amount);
    }
}

void InventoryItem::print() const {
    cout << "Name: " << name_ << endl;
    cout << "Quantity: " << quantity_ << endl;
    cout << "Min Stock Level: " << minStockLevel_ << endl;
    cout << "Needs Reorder: " << (needsReorder() ? "YES" : "NO") << endl;
}