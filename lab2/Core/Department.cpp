#include "Department.h"
#include "Polyclinic.h"
#include "../Persons/Doctor.h"
#include "../Persons/Cleaner.h"
#include "../Persons/Patient.h"
#include "../Exceptions/Exceptions.h"


Department::Department() 
    : name_(""), type_(""), polyclinic_(nullptr) {}

Department::Department(const string& name, const string& type, Polyclinic* polyclinic)
    : name_(name), type_(type), polyclinic_(polyclinic) {}

Department::~Department() = default;

string Department::getName() const { return name_; }
string Department::getType() const { return type_; }
Polyclinic* Department::getPolyclinic() const { return polyclinic_; }

const vector<Doctor*>& Department::getDoctors() const { return doctors_; }
const vector<Cleaner*>& Department::getCleaners() const { return cleaners_; }
const vector<Patient*>& Department::getPatients() const { return patients_; }

void Department::setName(const string& name) { name_ = name; }
void Department::setType(const string& type) { type_ = type; }
void Department::setPolyclinic(Polyclinic* polyclinic) { polyclinic_ = polyclinic; }

void Department::addDoctor(Doctor* doctor) {
    if (doctor) doctors_.push_back(doctor);
}

void Department::addCleaner(Cleaner* cleaner) {
    if (cleaner) cleaners_.push_back(cleaner);
}

void Department::addPatient(Patient* patient) {
    if (patient) patients_.push_back(patient);
}

void Department::removeDoctor(Doctor* doctor) {
    auto it = find(doctors_.begin(), doctors_.end(), doctor);
    if (it == doctors_.end()) {
        Exceptions::throwDoctorNotFound("Doctor not found in department");
    }
    doctors_.erase(it);
}

void Department::removeCleaner(Cleaner* cleaner) {
    cleaners_.erase(remove(cleaners_.begin(), cleaners_.end(), cleaner), cleaners_.end());
}

void Department::removePatient(Patient* patient) {
    patients_.erase(remove(patients_.begin(), patients_.end(), patient), patients_.end());
}

void Department::clearAll() {
    doctors_.clear();
    cleaners_.clear();
    patients_.clear();
}

void Department::print() const {
    cout << "Department: " << name_ << " (" << type_ << ")" << endl;

    cout << "Polyclinic: ";
    if (polyclinic_)
        cout << "[Polyclinic@" << polyclinic_ << "]";
    else
        cout << "none";
    cout << endl;

    cout << "Doctors: " << doctors_.size() << endl;
    cout << "Cleaners: " << cleaners_.size() << endl;
    cout << "Patients: " << patients_.size() << endl;
}
