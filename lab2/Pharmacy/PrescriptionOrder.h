#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"
#include "../Persons/Doctor.h"
#include "../Staff/Prescription.h"

class PrescriptionOrder {
private:
    int orderId_;
    Prescription* prescription_;
    Patient* patient_;
    Doctor* doctor_;
    string orderDate_;
    string status_;
    double totalCost_;

public:
    PrescriptionOrder(Prescription* prescription, Patient* patient, Doctor* doctor,
                     const string& orderDate, double totalCost, int orderId = 0);
    
    int getOrderId() const { return orderId_; }
    Prescription* getPrescription() const { return prescription_; }
    Patient* getPatient() const { return patient_; }
    Doctor* getDoctor() const { return doctor_; }
    string getOrderDate() const { return orderDate_; }
    string getStatus() const { return status_; }
    double getTotalCost() const { return totalCost_; }

    void setOrderDate(const string& date) { orderDate_ = date; }
    void setStatus(const string& status) { status_ = status; }
    void setTotalCost(double cost) { if(cost >= 0) totalCost_ = cost; }

    void processOrder();
    void fulfillOrder();
    void print() const;
};

