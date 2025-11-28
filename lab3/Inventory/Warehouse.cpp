#include "Warehouse.h"
#include "../Locations/Address.h"
#include "Stock.h"

Warehouse::Warehouse(int warehouseId, const string& name, Address* address, double capacity)
    : warehouseId_(warehouseId), name_(name), address_(address), capacity_(capacity), currentCapacity_(0.0) {}

Warehouse::~Warehouse() {
    address_ = nullptr;
}

void Warehouse::addStock(Stock* stock) {
    if (stock) {
        stocks_.push_back(stock);
        calculateCurrentCapacity();
    }
}

void Warehouse::removeStock(Stock* stock) {
    stocks_.erase(remove(stocks_.begin(), stocks_.end(), stock), stocks_.end());
    calculateCurrentCapacity();
}

void Warehouse::calculateCurrentCapacity() {
    currentCapacity_ = 0.0;
    for (auto stock : stocks_) {
        if (stock) {
            currentCapacity_ += stock->getQuantity();
        }
    }
}

bool Warehouse::isFull() const {
    return currentCapacity_ >= capacity_;
}

void Warehouse::print() const {
    cout << "Warehouse ID: " << warehouseId_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "Capacity: " << capacity_ << endl;
    cout << "Current Capacity: " << currentCapacity_ << endl;
    cout << "Full: " << (isFull() ? "Yes" : "No") << endl;
    cout << "Stocks: " << stocks_.size() << endl;
}


