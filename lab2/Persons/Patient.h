#pragma once
#include "Person.h"

class MedicalCard;

class Patient : public Person {
private:
    string gender_;
    MedicalCard* medicalCard_;
    string status_;            

public:
    Patient(const string& firstName, const string& lastName, int age,
            const string& gender, MedicalCard* medicalCard = nullptr,
            const string& status = "outpatient")
        : Person(firstName, lastName, age),
          gender_(gender),
          medicalCard_(medicalCard),
          status_(status) {}

    Patient() : Person("", "", 0), gender_(""), medicalCard_(nullptr), status_("outpatient") {}

    virtual ~Patient() = default;

    string getGender() const { return gender_; }
    MedicalCard* getMedicalCard() const { return medicalCard_; }
    string getStatus() const { return status_; }

    void setGender(const string& gender) { gender_ = gender; }
    void setMedicalCard(MedicalCard* card) { medicalCard_ = card; }
    void setStatus(const string& status) { status_ = status; }

    virtual void print() const override;
};