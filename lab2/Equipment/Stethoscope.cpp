#include "Stethoscope.h"
#include "../Core/Department.h"

Stethoscope::Stethoscope(const string& brand, const string& type, bool isElectronic, Department* department)
    : brand_(brand), type_(type), isElectronic_(isElectronic), department_(department) {}

Stethoscope::Stethoscope()
    : brand_(""), type_("Standard"), isElectronic_(false), department_(nullptr) {}

void Stethoscope::performAuscultation() {
    string type = isElectronic_ ? "Electronic" : "Acoustic";
    cout << type << " stethoscope (" << brand_ << ") used for auscultation" << endl;
}

void Stethoscope::print() const {
    cout << "Stethoscope: " << brand_ << " - " << type_ << endl;
    cout << "Type: " << (isElectronic_ ? "Electronic" : "Acoustic") << endl;
    if (department_)
        cout << "Department: " << department_->getName() << endl;
    else
        cout << "Department: not assigned" << endl;
}



