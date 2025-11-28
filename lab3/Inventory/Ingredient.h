#pragma once
#include "../pch.h"

class Supplier;

class Ingredient{
    private:
        int ingredientId_;
        string name_;
        double quantity_;
        Supplier* supplier_;
    public:
        Ingredient(int ingredientId, const string& name, double quantity, Supplier* supplier);
        ~Ingredient();

        int getIngredientId() const { return ingredientId_; }
        string getName() const { return name_; }
        double getQuantity() const { return quantity_; }
        Supplier* getSupplier() const { return supplier_; }

        void setQuantity(double quantity) { quantity_ = quantity; }

        void print() const;
};


