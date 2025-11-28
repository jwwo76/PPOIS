#include "InventoryItem.h"
#include "Warehouse.h"

InventoryItem::InventoryItem(int itemId, const string& name, const string& category, int quantity, double unitPrice, const string& lastRestockedDate, Warehouse* warehouse)
    : itemId_(itemId), name_(name), category_(category), quantity_(quantity), unitPrice_(unitPrice), lastRestockedDate_(lastRestockedDate), warehouse_(warehouse) {}

InventoryItem::~InventoryItem() {
    warehouse_ = nullptr;
}

void InventoryItem::restock(int amount) {
    if (amount > 0) {
        quantity_ += amount;
    }
}

void InventoryItem::print() const {
    cout << "Item ID: " << itemId_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "Category: " << category_ << endl;
    cout << "Quantity: " << quantity_ << endl;
    cout << "Unit Price: $" << fixed << setprecision(2) << unitPrice_ << endl;
    cout << "Last Restocked: " << lastRestockedDate_ << endl;
}


