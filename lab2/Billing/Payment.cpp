#include "Payment.h"
#include "../Exceptions/Exceptions.h"

Payment::Payment(Patient* patient, const string& date, double amount, const string& paymentMethod, int paymentId)
    : paymentId_(paymentId), patient_(patient), date_(date), amount_(amount),
      paymentMethod_(paymentMethod), transactionId_(""), status_("Pending") {}

void Payment::processPayment() {
    status_ = "Processing";
    cout << "Payment #" << paymentId_ << " of $" << amount_ << " processing..." << endl;
}

void Payment::confirmPayment(const string& transactionId) {
    transactionId_ = transactionId;
    status_ = "Completed";
    cout << "Payment #" << paymentId_ << " confirmed. Transaction ID: " << transactionId_ << endl;
    if(amount_ < 0)
        Exceptions::throwInvalidPayment("Amount cannot be negative");
}

void Payment::print() const {
    cout << "=== Payment #" << paymentId_ << " ===" << endl;
    if (patient_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
    }
    cout << "Date: " << date_ << endl;
    cout << "Amount: $" << amount_ << endl;
    cout << "Method: " << paymentMethod_ << endl;
    cout << "Status: " << status_ << endl;
    if (!transactionId_.empty())
        cout << "Transaction ID: " << transactionId_ << endl;
}

