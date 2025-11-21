#pragma once
#include "../pch.h"

class Polyclinic;
class Doctor;
class Cleaner;
class Patient;

class Department {
private:
    std::string name_;                      
    std::string type_;                      
    Polyclinic* polyclinic_;                
    std::vector<Doctor*> doctors_;          
    std::vector<Cleaner*> cleaners_;        
    std::vector<Patient*> patients_;        

public:
    Department();
    Department(const std::string& name, const std::string& type, Polyclinic* polyclinic = nullptr);
    ~Department();

    std::string getName() const;
    std::string getType() const;
    Polyclinic* getPolyclinic() const;

    const std::vector<Doctor*>& getDoctors() const;
    const std::vector<Cleaner*>& getCleaners() const;
    const std::vector<Patient*>& getPatients() const;

    void setName(const std::string& name);
    void setType(const std::string& type);
    void setPolyclinic(Polyclinic* polyclinic);

    void addDoctor(Doctor* doctor);
    void addCleaner(Cleaner* cleaner);
    void addPatient(Patient* patient);

    void removeDoctor(Doctor* doctor);
    void removeCleaner(Cleaner* cleaner);
    void removePatient(Patient* patient);

    void clearAll();

    void print() const;
};
