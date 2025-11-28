#pragma once
#include "../pch.h"

class Address;
class Stock;

class Warehouse{
    private:
        int warehouseId_;
        string name_;
        Address* address_;
        double capacity_;
        double currentCapacity_;
        vector<Stock*> stocks_;
    public:
        Warehouse(int warehouseId, const string& name, Address* address, double capacity);
        ~Warehouse();

        int getWarehouseId() const { return warehouseId_; }
        string getName() const { return name_; }
        double getCapacity() const { return capacity_; }
        double getCurrentCapacity() const { return currentCapacity_; }

        void addStock(Stock* stock);
        void removeStock(Stock* stock);
        void calculateCurrentCapacity();
        bool isFull() const;
        void print() const;
};


