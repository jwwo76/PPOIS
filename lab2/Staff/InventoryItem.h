#pragma once
#include "../pch.h"

class InventoryItem {
private:
    string name_;           
    int quantity_;
    int minStockLevel_;

public:
    
    InventoryItem(const string& name, int quantity, int minStockLevel);
    InventoryItem();

    string getName() const { return name_; }
    int getQuantity() const { return quantity_; }
    int getMinStockLevel() const { return minStockLevel_; }

    void setName(const string& name) { name_ = name; }
    void setQuantity(int quantity) { if(quantity >= 0) quantity_ = quantity; }
    void setMinStockLevel(int level) { if(level >= 0) minStockLevel_ = level; }

    void updateQuantity(int change);
    bool needsReorder() const;
    void restock(int amount);
    void useItem(int amount);
    void print() const;
};