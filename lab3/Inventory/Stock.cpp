#include "Stock.h"
#include "Ingredient.h"
#include "Warehouse.h"
#include "../Exceptions/Exceptions.h"

Stock::Stock(int stockId, Ingredient* ingredient, Warehouse* warehouse, double quantity, double minStockLevel, double maxStockLevel)
    : stockId_(stockId), ingredient_(ingredient), warehouse_(warehouse), quantity_(quantity), minStockLevel_(minStockLevel), maxStockLevel_(maxStockLevel) {
    if (stockId <= 0) {
        Exceptions::throwInvalidArgument("Stock ID должен быть положительным");
    }
    if (!ingredient) {
        Exceptions::throwInvalidArgument("Ингредиент не может быть nullptr");
    }
    if (quantity < 0) {
        Exceptions::throwInvalidArgument("Количество не может быть отрицательным");
    }
    if (minStockLevel < 0 || maxStockLevel < minStockLevel) {
        Exceptions::throwInvalidArgument("Недопустимые уровни запасов");
    }
}

Stock::~Stock() {
    ingredient_ = nullptr;
    warehouse_ = nullptr;
}

void Stock::restock(double amount) {
    if (amount > 0) {
        quantity_ += amount;
        if (quantity_ > maxStockLevel_) {
            quantity_ = maxStockLevel_;
        }
    }
}

bool Stock::isLowStock() const {
    if (quantity_ < minStockLevel_) {
        return true;
    }
    return false;
}

void Stock::print() const {
    cout << "Stock ID: " << stockId_ << endl;
    cout << "Quantity: " << quantity_ << endl;
    cout << "Min Level: " << minStockLevel_ << endl;
    cout << "Max Level: " << maxStockLevel_ << endl;
    cout << "Low Stock: " << (isLowStock() ? "Yes" : "No") << endl;
}


