#pragma once
#include "../pch.h"
#include "../Persons/Patient.h"

class LabSample {
private:
    int sampleId_;
    Patient* patient_;
    string sampleType_;
    string collectionDate_;
    string storageLocation_;
    bool isProcessed_;

public:
    LabSample(Patient* patient, const string& sampleType, const string& collectionDate, int sampleId = 0);
    
    int getSampleId() const { return sampleId_; }
    Patient* getPatient() const { return patient_; }
    string getSampleType() const { return sampleType_; }
    bool getIsProcessed() const { return isProcessed_; }

    void setStorageLocation(const string& location) { storageLocation_ = location; }

    void processSample();
    void print() const;
};

