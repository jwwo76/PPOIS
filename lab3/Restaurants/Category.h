#pragma once
#include "../pch.h"

class MenuItem;

class Category{
    private:
        int categoryId_;
        string name_;
        string description_;
        vector<MenuItem*> items_;
    public:
        Category(int categoryId, const string& name, const string& description);
        ~Category();

        int getCategoryId() const { return categoryId_; }
        string getName() const { return name_; }
        string getDescription() const { return description_; }
        vector<MenuItem*> getItems() const { return items_; }

        void setCategoryId(int id) { categoryId_ = id; }
        void setName(const string& name) { name_ = name; }
        void setDescription(const string& desc) { description_ = desc; }
        void addItem(MenuItem* item);
        void removeItem(MenuItem* item);

        void print() const;
};


