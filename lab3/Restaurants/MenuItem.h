#pragma once
#include "../pch.h"

class Category;

class MenuItem{
    private:
        int itemId_;
        string name_;
        double price_;
        Category* category_;
    public:
        MenuItem(int itemId, const string& name, double price, Category* category);
        ~MenuItem();

        int getItemId() const { return itemId_; }
        string getName() const { return name_; }
        double getPrice() const { return price_; }
        Category* getCategory() const { return category_; }

        void setPrice(double price);

        void print() const;
};


