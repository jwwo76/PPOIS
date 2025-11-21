#include "LabSample.h"

LabSample::LabSample(Patient* patient, const string& sampleType, const string& collectionDate, int sampleId)
    : sampleId_(sampleId), patient_(patient), sampleType_(sampleType),
      collectionDate_(collectionDate), storageLocation_(""), isProcessed_(false) {}

void LabSample::processSample() {
    isProcessed_ = true;
    cout << "Sample #" << sampleId_ << " processed" << endl;
}

void LabSample::print() const {
    cout << "=== Lab Sample #" << sampleId_ << " ===" << endl;
    if (patient_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
    }
    cout << "Type: " << sampleType_ << endl;
    cout << "Collection Date: " << collectionDate_ << endl;
    cout << "Status: " << (isProcessed_ ? "Processed" : "Pending") << endl;
    if (!storageLocation_.empty())
        cout << "Storage Location: " << storageLocation_ << endl;
}

