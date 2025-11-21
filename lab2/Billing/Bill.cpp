#include "Bill.h"

Bill::Bill(Patient* patient, const string& date, double totalAmount, int billId)
    : billId_(billId), patient_(patient), date_(date), totalAmount_(totalAmount),
      paidAmount_(0.0), status_("Unpaid") {}

void Bill::addService(const string& service) {
    services_.push_back(service);
}

void Bill::makePayment(double amount) {
    if (amount > 0) {
        paidAmount_ += amount;
        if (paidAmount_ > totalAmount_) {
            paidAmount_ = totalAmount_;
        }
        updateStatus();
        cout << "Payment of $" << amount << " received. Balance: $" << getBalance() << endl;
    }
}

void Bill::updateStatus() {
    if (paidAmount_ >= totalAmount_) {
        status_ = "Paid";
    } else if (paidAmount_ > 0) {
        status_ = "Partial";
    } else {
        status_ = "Unpaid";
    }
}

void Bill::print() const {
    cout << "=== Bill #" << billId_ << " ===" << endl;
    if (patient_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
    }
    cout << "Date: " << date_ << endl;
    cout << "Total Amount: $" << totalAmount_ << endl;
    cout << "Paid Amount: $" << paidAmount_ << endl;
    cout << "Balance: $" << getBalance() << endl;
    cout << "Status: " << status_ << endl;
    cout << "Services: " << services_.size() << endl;
    for (size_t i = 0; i < services_.size(); ++i) {
        cout << "  " << (i + 1) << ". " << services_[i] << endl;
    }
}

