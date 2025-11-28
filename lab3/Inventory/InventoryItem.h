#pragma once
#include "../pch.h"

class Warehouse;

class InventoryItem{
    private:
        int itemId_;
        string name_;
        string category_;
        int quantity_;
        double unitPrice_;
        string lastRestockedDate_;
        Warehouse* warehouse_;
    public:
        InventoryItem(int itemId, const string& name, const string& category, int quantity, double unitPrice, const string& lastRestockedDate, Warehouse* warehouse);
        ~InventoryItem();

        int getItemId() const { return itemId_; }
        string getName() const { return name_; }
        int getQuantity() const { return quantity_; }
        double getUnitPrice() const { return unitPrice_; }

        void setQuantity(int quantity) { quantity_ = quantity; }
        void restock(int amount);

        void print() const;
};


