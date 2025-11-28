#include "Transaction.h"
#include "Payment.h"

Transaction::Transaction(int transactionId, Payment* payment, const string& transactionType, double amount, const string& transactionDate)
    : transactionId_(transactionId), payment_(payment), transactionType_(transactionType), amount_(amount), transactionDate_(transactionDate), status_("Pending") {}

Transaction::~Transaction() {
    payment_ = nullptr;
}

void Transaction::process() {
    status_ = "Completed";
}

void Transaction::print() const {
    cout << "Transaction ID: " << transactionId_ << endl;
    cout << "Type: " << transactionType_ << endl;
    cout << "Amount: $" << fixed << setprecision(2) << amount_ << endl;
    cout << "Date: " << transactionDate_ << endl;
    cout << "Status: " << status_ << endl;
    if (!description_.empty()) {
        cout << "Description: " << description_ << endl;
    }
}


