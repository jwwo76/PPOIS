#pragma once
#include "../pch.h"

class MenuItem;
class Category;

class Menu{
    private:
        int menuId_;
        string name_;
        vector<MenuItem*> items_;
    public:
        Menu(int menuId, const string& name);
        ~Menu();

        int getMenuId() const { return menuId_; }
        string getName() const { return name_; }
        vector<MenuItem*> getItems() const { return items_; }

        void addItem(MenuItem* item);

        void print() const;
};


