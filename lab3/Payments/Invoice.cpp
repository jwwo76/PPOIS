#include "Invoice.h"
#include "../Orders/Order.h"
#include "../Persons/Customer.h"

Invoice::Invoice(int invoiceId, Order* order, Customer* customer, double totalAmount, const string& invoiceDate)
    : invoiceId_(invoiceId), order_(order), customer_(customer), totalAmount_(totalAmount), taxAmount_(0.0), discountAmount_(0.0), invoiceDate_(invoiceDate), status_("Unpaid") {}

Invoice::~Invoice() {
    order_ = nullptr;
    customer_ = nullptr;
}

void Invoice::calculateTotal() {
    totalAmount_ = totalAmount_ + taxAmount_ - discountAmount_;
}

void Invoice::print() const {
    cout << "Invoice ID: " << invoiceId_ << endl;
    cout << "Invoice Date: " << invoiceDate_ << endl;
    cout << "Due Date: " << dueDate_ << endl;
    cout << "Total Amount: $" << fixed << setprecision(2) << totalAmount_ << endl;
    cout << "Tax: $" << fixed << setprecision(2) << taxAmount_ << endl;
    cout << "Discount: $" << fixed << setprecision(2) << discountAmount_ << endl;
    cout << "Status: " << status_ << endl;
}


