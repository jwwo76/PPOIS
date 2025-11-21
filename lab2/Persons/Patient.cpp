#include "Patient.h"
    
void Patient::print() const{
    Person::print();
    cout << "Gender: " << gender_ << endl;
    cout << "Status: " << status_ << endl;
    if (medicalCard_)
        cout << "Medical card assigned." << endl;
    else
        cout << "No medical card." << endl;
    };