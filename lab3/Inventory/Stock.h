#pragma once
#include "../pch.h"

class Ingredient;
class Warehouse;

class Stock{
    private:
        int stockId_;
        Ingredient* ingredient_;
        Warehouse* warehouse_;
        double quantity_;
        double minStockLevel_;
        double maxStockLevel_;
    public:
        Stock(int stockId, Ingredient* ingredient, Warehouse* warehouse, double quantity, double minStockLevel, double maxStockLevel);
        ~Stock();

        int getStockId() const { return stockId_; }
        Ingredient* getIngredient() const { return ingredient_; }
        double getQuantity() const { return quantity_; }

        void setQuantity(double quantity) { quantity_ = quantity; }
        void restock(double amount);
        bool isLowStock() const;
        void print() const;
};


