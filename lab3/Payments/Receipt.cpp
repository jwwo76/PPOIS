#include "Receipt.h"
#include "Payment.h"
#include "../Orders/Order.h"

Receipt::Receipt(int receiptId, Payment* payment, Order* order, double amount, const string& receiptDate)
    : receiptId_(receiptId), payment_(payment), order_(order), amount_(amount), receiptDate_(receiptDate) {}

Receipt::~Receipt() {
    payment_ = nullptr;
    order_ = nullptr;
}

void Receipt::print() const {
    cout << "Receipt ID: " << receiptId_ << endl;
    cout << "Receipt Date: " << receiptDate_ << endl;
    cout << "Amount: $" << fixed << setprecision(2) << amount_ << endl;
    if (!transactionId_.empty()) {
        cout << "Transaction ID: " << transactionId_ << endl;
    }
}


