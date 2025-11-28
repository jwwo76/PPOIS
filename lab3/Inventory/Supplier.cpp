#include "Supplier.h"
#include "../Locations/Address.h"
#include "Ingredient.h"

Supplier::Supplier(int supplierId, const string& name, const string& contactPerson, const string& phoneNumber, const string& email, Address* address)
    : supplierId_(supplierId), name_(name), contactPerson_(contactPerson), phoneNumber_(phoneNumber), email_(email), address_(address) {}

Supplier::~Supplier() {
    address_ = nullptr;
}

void Supplier::addIngredient(Ingredient* ingredient) {
    if (ingredient) {
        ingredients_.push_back(ingredient);
    }
}

void Supplier::removeIngredient(Ingredient* ingredient) {
    ingredients_.erase(remove(ingredients_.begin(), ingredients_.end(), ingredient), ingredients_.end());
}

void Supplier::print() const {
    cout << "Supplier ID: " << supplierId_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "Contact Person: " << contactPerson_ << endl;
    cout << "Phone: " << phoneNumber_ << endl;
    cout << "Email: " << email_ << endl;
    cout << "Ingredients: " << ingredients_.size() << endl;
}


