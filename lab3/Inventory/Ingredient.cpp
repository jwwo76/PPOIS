#include "Ingredient.h"
#include "Supplier.h"

Ingredient::Ingredient(int ingredientId, const string& name, double quantity, Supplier* supplier)
    : ingredientId_(ingredientId), name_(name), quantity_(quantity), supplier_(supplier) {}

Ingredient::~Ingredient() {
    supplier_ = nullptr;
}

void Ingredient::print() const {
    cout << "Ingredient ID: " << ingredientId_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "Quantity: " << quantity_ << endl;
}


