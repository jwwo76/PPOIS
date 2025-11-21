#include <gtest/gtest.h>
#include "../Persons/Person.h"
#include "../Persons/Employee.h"
#include "../Persons/Doctor.h"
#include "../Persons/Patient.h"
#include "../Persons/Cleaner.h"
#include "../Persons/Nurse.h"
#include "../Persons/Receptionist.h"
#include "../Core/Polyclinic.h"
#include "../Core/Department.h"
#include "../Core/Cabinet.h"
#include "../Staff/Appointment.h"
#include "../Staff/Prescription.h"
#include "../Staff/MedicalCard.h"
#include "../Staff/InventoryItem.h"
#include "../Services/ConsultationService.h"
#include "../Services/DiagnosticService.h"
#include "../Services/SurgeryService.h"
#include "../Services/TherapyService.h"
#include "../Services/VaccinationService.h"
#include "../Records/PatientRecord.h"
#include "../Records/TreatmentRecord.h"
#include "../Records/DiagnosisRecord.h"
#include "../Records/SurgeryReport.h"
#include "../Records/LabReport.h"
#include "../Operations/Shift.h"
#include "../Operations/Schedule.h"
#include "../Operations/Task.h"
#include "../Operations/Maintenance.h"
#include "../Operations/QualityControl.h"
#include "../Equipment/MedicalEquipment.h"
#include "../Equipment/XRayMachine.h"
#include "../Equipment/UltrasoundMachine.h"
#include "../Equipment/BloodPressureMonitor.h"
#include "../Equipment/Stethoscope.h"
#include "../Facilities/WaitingRoom.h"
#include "../Facilities/OperatingRoom.h"
#include "../Facilities/LabRoom.h"
#include "../Facilities/StorageRoom.h"
#include "../Facilities/ParkingLot.h"
#include "../Billing/Bill.h"
#include "../Billing/Invoice.h"
#include "../Billing/Payment.h"
#include "../Billing/Insurance.h"
#include "../Laboratory/LabTest.h"
#include "../Laboratory/LabSample.h"
#include "../Laboratory/LabTechnician.h"
#include "../Laboratory/TestResult.h"
#include "../Pharmacy/Medication.h"
#include "../Pharmacy/PharmacyStock.h"
#include "../Pharmacy/PrescriptionOrder.h"
#include "../Pharmacy/Pharmacist.h"
#include "../Emergency/EmergencyCase.h"
#include "../Emergency/Ambulance.h"
#include "../Emergency/EmergencyProtocol.h"
#include "../Exceptions/Exceptions.h"

TEST(PersonTest, ConstructorAndGetters) {
    Person person("John", "Doe", 30);
    EXPECT_EQ(person.getFirstName(), "John");
    EXPECT_EQ(person.getSurname(), "Doe");
    EXPECT_EQ(person.getAge(), 30);
}

TEST(PersonTest, Setters) {
    Person person("John", "Doe", 30);
    person.setFirstName("Jane");
    person.setSurname("Smith");
    person.setAge(25);
    EXPECT_EQ(person.getFirstName(), "Jane");
    EXPECT_EQ(person.getSurname(), "Smith");
    EXPECT_EQ(person.getAge(), 25);
}

TEST(EmployeeTest, ConstructorAndGetters) {
    Department* dept = new Department("Cardiology", "Medical");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, dept, "Cardiology");
    EXPECT_EQ(doctor->getId(), 1);
    EXPECT_EQ(doctor->getPosition(), "Doctor");
    EXPECT_EQ(doctor->getSalary(), 5000.0);
    delete doctor;
    delete dept;
}

TEST(DoctorTest, WorkMethod) {
    Department* dept = new Department("Cardiology", "Medical");
    Doctor doctor("John", "Doe", 35, 1, 5000.0, 5, dept, "Cardiology");
    testing::internal::CaptureStdout();
    doctor.work();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    delete dept;
}

TEST(PatientTest, ConstructorAndGetters) {
    Patient patient("Jane", "Smith", 28, "Female");
    EXPECT_EQ(patient.getFirstName(), "Jane");
    EXPECT_EQ(patient.getSurname(), "Smith");
    EXPECT_EQ(patient.getAge(), 28);
    EXPECT_EQ(patient.getGender(), "Female");
    EXPECT_EQ(patient.getStatus(), "outpatient");
}

TEST(DepartmentTest, ConstructorAndBasicOperations) {
    Department dept("Cardiology", "Medical");
    EXPECT_EQ(dept.getName(), "Cardiology");
    EXPECT_EQ(dept.getType(), "Medical");
}

TEST(DepartmentTest, AddAndRemoveDoctor) {
    Department dept("Cardiology", "Medical");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, &dept, "Cardiology");
    dept.addDoctor(doctor);
    EXPECT_EQ(dept.getDoctors().size(), 1);
    dept.removeDoctor(doctor);
    EXPECT_EQ(dept.getDoctors().size(), 0);
    delete doctor;
}

TEST(AppointmentTest, ConstructorAndBasicOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    Appointment appointment(patient, doctor, "2024-01-15 10:00", "Checkup", 1);
    
    EXPECT_EQ(appointment.getAppointmentId(), 1);
    EXPECT_EQ(appointment.getDateTime(), "2024-01-15 10:00");
    EXPECT_EQ(appointment.getReason(), "Checkup");
    EXPECT_FALSE(appointment.getIsCompleted());
    
    delete patient;
    delete doctor;
}

TEST(AppointmentTest, RescheduleAndComplete) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    Appointment appointment(patient, doctor, "2024-01-15 10:00", "Checkup", 1);
    
    testing::internal::CaptureStdout();
    appointment.reschedule("2024-01-16 11:00");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(appointment.getDateTime(), "2024-01-16 11:00");
    
    appointment.completeAppointment("Healthy");
    EXPECT_TRUE(appointment.getIsCompleted());
    
    delete patient;
    delete doctor;
}

TEST(PrescriptionTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    vector<string> meds = {"Aspirin", "Vitamin D"};
    Prescription prescription(patient, doctor, "2024-01-15", meds, "1 tablet daily", "Take with food", 1);
    
    EXPECT_EQ(prescription.getPrescriptionId(), 1);
    EXPECT_EQ(prescription.getMedications().size(), 2);
    EXPECT_FALSE(prescription.getIsFilled());
    
    prescription.fillPrescription();
    EXPECT_TRUE(prescription.getIsFilled());
    
    delete patient;
    delete doctor;
}

TEST(MedicalCardTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    MedicalCard card(1, patient);
    
    EXPECT_EQ(card.getCardId(), 1);
    card.addMedicalRecord("Annual checkup 2024");
    card.addMedication("Aspirin");
    EXPECT_EQ(card.getMedicalHistory().size(), 1);
    EXPECT_EQ(card.getCurrentMedications().size(), 1);
    
    card.removeMedication("Aspirin");
    EXPECT_EQ(card.getCurrentMedications().size(), 0);
    
    delete patient;
}

TEST(InventoryItemTest, ConstructorAndOperations) {
    InventoryItem item("Syringe", 100, 20);
    EXPECT_EQ(item.getName(), "Syringe");
    EXPECT_EQ(item.getQuantity(), 100);
    EXPECT_FALSE(item.needsReorder());
    
    item.useItem(90);
    EXPECT_EQ(item.getQuantity(), 10);
    EXPECT_TRUE(item.needsReorder());
    
    item.restock(50);
    EXPECT_EQ(item.getQuantity(), 60);
    EXPECT_FALSE(item.needsReorder());
}

TEST(ConsultationServiceTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    ConsultationService service(patient, doctor, "2024-01-15", "10:00", "Headache", 50.0);
    
    EXPECT_EQ(service.getCost(), 50.0);
    testing::internal::CaptureStdout();
    service.conductConsultation();
    service.provideDiagnosis("Migraine");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(service.getDiagnosis(), "Migraine");
    
    delete patient;
    delete doctor;
}

TEST(DiagnosticServiceTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    DiagnosticService service(patient, doctor, "Blood Test", "2024-01-15", 1);
    
    EXPECT_FALSE(service.getIsCompleted());
    testing::internal::CaptureStdout();
    service.performTest();
    service.completeTest("Normal");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_TRUE(service.getIsCompleted());
    EXPECT_EQ(service.getResult(), "Normal");
    
    delete patient;
    delete doctor;
}

TEST(SurgeryServiceTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    SurgeryService service(patient, doctor, "Appendectomy", "2024-01-15", "14:00", 5000.0, 120, 1);
    
    EXPECT_EQ(service.getStatus(), "Scheduled");
    testing::internal::CaptureStdout();
    service.performSurgery();
    EXPECT_EQ(service.getStatus(), "In Progress");
    service.completeSurgery();
    EXPECT_EQ(service.getStatus(), "Completed");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

TEST(TherapyServiceTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    TherapyService service(patient, doctor, "Physical Therapy", "2024-01-15", 10, 1);
    
    EXPECT_EQ(service.getSessionNumber(), 0);
    testing::internal::CaptureStdout();
    service.conductSession();
    EXPECT_EQ(service.getSessionNumber(), 1);
    EXPECT_FALSE(service.isCompleted());
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

TEST(VaccinationServiceTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    VaccinationService service(patient, doctor, "COVID-19", "2024-01-15", "BATCH123", 1, 1);
    
    EXPECT_EQ(service.getVaccineName(), "COVID-19");
    testing::internal::CaptureStdout();
    service.administerVaccine();
    service.scheduleNextDose("2024-02-15");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(service.getNextDoseDate(), "2024-02-15");
    
    delete patient;
    delete doctor;
}

TEST(PatientRecordTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    PatientRecord record(patient, "2024-01-15", "Fever", 1);
    
    EXPECT_EQ(record.getStatus(), "Active");
    record.addTreatment("Antibiotics");
    
    testing::internal::CaptureStdout();
    record.dischargePatient("2024-01-20");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(record.getStatus(), "Discharged");
    
    delete patient;
}

TEST(TreatmentRecordTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    TreatmentRecord record(patient, doctor, "2024-01-15", "Medication", "Antibiotics course", 1);
    
    testing::internal::CaptureStdout();
    record.recordOutcome("Successful");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(record.getOutcome(), "Successful");
    
    delete patient;
    delete doctor;
}

TEST(DiagnosisRecordTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    DiagnosisRecord record(patient, doctor, "2024-01-15", "Migraine", "Headache, nausea", 1);
    
    record.addRecommendations("Rest and medication");
    EXPECT_FALSE(record.getRecommendations().empty());
    
    delete patient;
    delete doctor;
}

TEST(SurgeryReportTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    SurgeryReport report(patient, doctor, "2024-01-15", "Appendectomy", "Laparoscopic removal", 1);
    
    EXPECT_FALSE(report.getWasSuccessful());
    testing::internal::CaptureStdout();
    report.markSuccessful();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_TRUE(report.getWasSuccessful());
    
    report.addComplications("None");
    report.addRecoveryNotes("Patient recovering well");
    EXPECT_FALSE(report.getComplications().empty());
    EXPECT_FALSE(report.getRecoveryNotes().empty());
    
    delete patient;
    delete doctor;
}

TEST(LabReportTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    LabReport report(patient, doctor, "2024-01-15", "Blood Test", "Normal range", 1);
    
    EXPECT_TRUE(report.getIsNormal());
    testing::internal::CaptureStdout();
    report.setResults("All values within normal range");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(report.getResults(), "All values within normal range");
    
    delete patient;
    delete doctor;
}

TEST(ShiftTest, ConstructorAndOperations) {
    Shift shift("2024-01-15", "08:00", "16:00", "Day");
    EXPECT_EQ(shift.getDate(), "2024-01-15");
    EXPECT_EQ(shift.getStartTime(), "08:00");
    EXPECT_EQ(shift.getEndTime(), "16:00");
    EXPECT_EQ(shift.getShiftType(), "Day");
}

TEST(ScheduleTest, ConstructorAndOperations) {
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    Schedule schedule(doctor, "2024-01-15");
    
    schedule.addAppointment("2024-01-15", "10:00");
    schedule.addAppointment("2024-01-15", "11:00");
    EXPECT_FALSE(schedule.isTimeSlotAvailable("2024-01-15", "10:00"));
    EXPECT_TRUE(schedule.isTimeSlotAvailable("2024-01-15", "12:00"));
    
    schedule.removeAppointment("2024-01-15", "10:00");
    EXPECT_TRUE(schedule.isTimeSlotAvailable("2024-01-15", "10:00"));
    
    delete doctor;
}

TEST(TaskTest, ConstructorAndOperations) {
    Employee* employee = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    Task task("Review reports", "Check patient reports", employee, "2024-01-20", 1, 1);
    
    EXPECT_EQ(task.getStatus(), "Pending");
    testing::internal::CaptureStdout();
    task.completeTask();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(task.getStatus(), "Completed");
    
    delete employee;
}

TEST(MaintenanceTest, ConstructorAndOperations) {
    Department* dept = new Department("Cardiology", "Medical");
    MedicalEquipment* equipment = new MedicalEquipment("X-Ray", "Model X", "SN123", dept);
    Maintenance maintenance(equipment, "2024-01-15", "Routine", 1);
    
    EXPECT_FALSE(maintenance.getIsCompleted());
    testing::internal::CaptureStdout();
    maintenance.completeMaintenance("2024-01-16", "All systems checked");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_TRUE(maintenance.getIsCompleted());
    
    delete equipment;
    delete dept;
}

TEST(QualityControlTest, ConstructorAndOperations) {
    QualityControl qc("2024-01-15", "Cardiology", "Inspector Name", 1);
    
    qc.addIssue("Equipment needs calibration");
    qc.addRecommendation("Schedule maintenance");
    EXPECT_EQ(qc.getIssues().size(), 1);
    EXPECT_EQ(qc.getRecommendations().size(), 1);
    
    testing::internal::CaptureStdout();
    qc.calculateScore();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_GE(qc.getScore(), 0);
}

TEST(MedicalEquipmentTest, ConstructorAndOperations) {
    Department* dept = new Department("Cardiology", "Medical");
    MedicalEquipment equipment("X-Ray Machine", "Model X", "SN123", dept);
    
    EXPECT_EQ(equipment.getName(), "X-Ray Machine");
    EXPECT_TRUE(equipment.getIsFunctional());
    
    testing::internal::CaptureStdout();
    equipment.reportMalfunction();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_FALSE(equipment.getIsFunctional());
    
    equipment.performMaintenance();
    EXPECT_TRUE(equipment.getIsFunctional());
    
    delete dept;
}

TEST(XRayMachineTest, ConstructorAndOperations) {
    Department* dept = new Department("Radiology", "Medical");
    XRayMachine machine("Model X", "SN123", dept, 100, 50);
    
    EXPECT_EQ(machine.getMaxDosePerDay(), 50);
    testing::internal::CaptureStdout();
    machine.performXRay();
    EXPECT_EQ(machine.getCurrentDoseToday(), 1);
    machine.resetDailyDose();
    EXPECT_EQ(machine.getCurrentDoseToday(), 0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(UltrasoundMachineTest, ConstructorAndOperations) {
    Department* dept = new Department("Radiology", "Medical");
    UltrasoundMachine machine("Model U", "SN456", dept);
    
    EXPECT_FALSE(machine.getDopplerEnabled());
    testing::internal::CaptureStdout();
    machine.enableDoppler();
    EXPECT_TRUE(machine.getDopplerEnabled());
    machine.disableDoppler();
    EXPECT_FALSE(machine.getDopplerEnabled());
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(BloodPressureMonitorTest, ConstructorAndOperations) {
    Department* dept = new Department("Cardiology", "Medical");
    BloodPressureMonitor monitor("Model BP", "SN789", dept);
    
    testing::internal::CaptureStdout();
    monitor.measureBloodPressure(120, 80);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(monitor.getLastSystolic(), 120);
    EXPECT_EQ(monitor.getLastDiastolic(), 80);
    
    delete dept;
}

TEST(WaitingRoomTest, ConstructorAndOperations) {
    Department* dept = new Department("Cardiology", "Medical");
    WaitingRoom room("WR-101", dept, 20);
    
    Patient* patient1 = new Patient("Jane", "Smith", 28, "Female");
    Patient* patient2 = new Patient("John", "Doe", 35, "Male");
    
    room.addPatient(patient1);
    room.addPatient(patient2);
    EXPECT_EQ(room.getPatients().size(), 2);
    EXPECT_FALSE(room.isFull());
    
    room.removePatient(patient1);
    EXPECT_EQ(room.getPatients().size(), 1);
    
    delete patient1;
    delete patient2;
    delete dept;
}

TEST(OperatingRoomTest, ConstructorAndOperations) {
    Department* dept = new Department("Surgery", "Medical");
    OperatingRoom room("OR-201", dept);
    
    EXPECT_TRUE(room.getIsAvailable());
    testing::internal::CaptureStdout();
    room.reserveRoom();
    EXPECT_FALSE(room.getIsAvailable());
    room.releaseRoom();
    EXPECT_TRUE(room.getIsAvailable());
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(LabRoomTest, ConstructorAndOperations) {
    LabRoom room("LAB-301", "Chemistry", 10);
    
    room.addEquipment("Microscope");
    room.addEquipment("Centrifuge");
    EXPECT_EQ(room.getEquipment().size(), 2);
    
    room.removeEquipment("Microscope");
    EXPECT_EQ(room.getEquipment().size(), 1);
}

TEST(StorageRoomTest, ConstructorAndOperations) {
    StorageRoom room("ST-401", "Medical Supplies", 100);
    
    InventoryItem* item1 = new InventoryItem("Syringe", 50, 10);
    InventoryItem* item2 = new InventoryItem("Bandage", 100, 20);
    
    room.addItem(item1);
    room.addItem(item2);
    EXPECT_EQ(room.getItems().size(), 2);
    EXPECT_FALSE(room.isFull());
    
    room.removeItem(item1);
    EXPECT_EQ(room.getItems().size(), 1);
    
    delete item1;
    delete item2;
}

TEST(ParkingLotTest, ConstructorAndOperations) {
    ParkingLot lot("PARK-1", 50, true, 2.5);
    
    EXPECT_EQ(lot.getTotalSpots(), 50);
    EXPECT_EQ(lot.getAvailableSpots(), 50);
    EXPECT_TRUE(lot.hasAvailableSpots());
    
    testing::internal::CaptureStdout();
    lot.parkVehicle();
    EXPECT_EQ(lot.getAvailableSpots(), 49);
    lot.releaseSpot();
    EXPECT_EQ(lot.getAvailableSpots(), 50);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(BillTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Bill bill(patient, "2024-01-15", 500.0, 1);
    
    EXPECT_EQ(bill.getTotalAmount(), 500.0);
    EXPECT_EQ(bill.getBalance(), 500.0);
    EXPECT_EQ(bill.getStatus(), "Unpaid");
    
    bill.addService("Consultation");
    bill.addService("Lab Test");
    
    testing::internal::CaptureStdout();
    bill.makePayment(300.0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(bill.getBalance(), 200.0);
    EXPECT_EQ(bill.getStatus(), "Partial");
    
    bill.makePayment(200.0);
    EXPECT_EQ(bill.getStatus(), "Paid");
    
    delete patient;
}

TEST(InvoiceTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Invoice invoice(patient, "2024-01-15", "2024-02-15", 1000.0, 1);
    
    EXPECT_EQ(invoice.getStatus(), "Pending");
    testing::internal::CaptureStdout();
    invoice.markAsPaid("Credit Card");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(invoice.getStatus(), "Paid");
    
    delete patient;
}

TEST(PaymentTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Payment payment(patient, "2024-01-15", 500.0, "Credit Card", 1);
    
    EXPECT_EQ(payment.getStatus(), "Pending");
    testing::internal::CaptureStdout();
    payment.processPayment();
    payment.confirmPayment("TXN123456");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(payment.getStatus(), "Completed");
    
    delete patient;
}

TEST(InsuranceTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Insurance insurance("POL123", patient, "Health Insurance Co", "Premium", 10000.0, "2025-12-31");
    
    EXPECT_EQ(insurance.getRemainingCoverage(), 10000.0);
    EXPECT_TRUE(insurance.hasCoverage());
    
    testing::internal::CaptureStdout();
    insurance.useCoverage(2000.0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(insurance.getRemainingCoverage(), 8000.0);
    
    delete patient;
}

TEST(LabTestTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    LabTest test(patient, doctor, "Blood Test", "2024-01-15", 1);
    
    EXPECT_FALSE(test.getIsCompleted());
    testing::internal::CaptureStdout();
    test.performTest();
    test.completeTest("Normal");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_TRUE(test.getIsCompleted());
    
    delete patient;
    delete doctor;
}

TEST(LabSampleTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    LabSample sample(patient, "Blood", "2024-01-15", 1);
    
    EXPECT_FALSE(sample.getIsProcessed());
    testing::internal::CaptureStdout();
    sample.processSample();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_TRUE(sample.getIsProcessed());
    
    delete patient;
}

TEST(LabTechnicianTest, ConstructorAndOperations) {
    LabTechnician tech("Alice", "Johnson", 30, 10, 3500.0, 3, "Hematology");
    
    EXPECT_EQ(tech.getSpecialization(), "Hematology");
    testing::internal::CaptureStdout();
    tech.work();
    tech.performTest();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(tech.getTestsPerformed(), 1);
}

TEST(MedicationTest, ConstructorAndOperations) {
    Medication med("Aspirin", "Acetylsalicylic acid", "Pharma Co", 100, 5.50, "2025-12-31");
    
    EXPECT_EQ(med.getQuantity(), 100);
    testing::internal::CaptureStdout();
    med.dispense(10);
    EXPECT_EQ(med.getQuantity(), 90);
    med.restock(20);
    EXPECT_EQ(med.getQuantity(), 110);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(PharmacyStockTest, ConstructorAndOperations) {
    PharmacyStock stock;
    Medication* med1 = new Medication("Aspirin", "ASA", "Pharma", 100, 5.50, "2025-12-31");
    Medication* med2 = new Medication("Ibuprofen", "IBU", "Pharma", 50, 8.00, "2025-12-31");
    
    stock.addMedication(med1);
    stock.addMedication(med2);
    EXPECT_EQ(stock.getTotalItems(), 2);
    
    Medication* found = stock.findMedication("Aspirin");
    EXPECT_NE(found, nullptr);
    
    stock.updateStock();
    EXPECT_GT(stock.getTotalValue(), 0);
    
    delete med1;
    delete med2;
}

TEST(PrescriptionOrderTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    vector<string> meds = {"Aspirin"};
    Prescription* prescription = new Prescription(patient, doctor, "2024-01-15", meds, "1 daily", "With food", 1);
    PrescriptionOrder order(prescription, patient, doctor, "2024-01-15", 25.50, 1);
    
    EXPECT_EQ(order.getStatus(), "Pending");
    testing::internal::CaptureStdout();
    order.processOrder();
    order.fulfillOrder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(order.getStatus(), "Fulfilled");
    
    delete prescription;
    delete patient;
    delete doctor;
}

TEST(PharmacistTest, ConstructorAndOperations) {
    Pharmacist pharmacist("Bob", "Williams", 32, 11, 4000.0, 4, "PHARM123");
    
    EXPECT_EQ(pharmacist.getLicenseNumber(), "PHARM123");
    testing::internal::CaptureStdout();
    pharmacist.work();
    pharmacist.dispensePrescription();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(pharmacist.getPrescriptionsDispensed(), 1);
}

TEST(EmergencyCaseTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Emergency");
    EmergencyCase emergency(patient, doctor, "2024-01-15 14:30", "Chest pain", 3, 1);
    
    EXPECT_EQ(emergency.getStatus(), "Arrived");
    testing::internal::CaptureStdout();
    emergency.triage();
    EXPECT_EQ(emergency.getStatus(), "Triaged");
    emergency.treat();
    EXPECT_EQ(emergency.getStatus(), "Under Treatment");
    emergency.discharge();
    EXPECT_EQ(emergency.getStatus(), "Discharged");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

TEST(AmbulanceTest, ConstructorAndOperations) {
    Ambulance ambulance("AMB-001", "Driver Name", 2);
    
    EXPECT_TRUE(ambulance.getIsAvailable());
    testing::internal::CaptureStdout();
    ambulance.dispatch("123 Main St");
    EXPECT_FALSE(ambulance.getIsAvailable());
    ambulance.returnToStation();
    EXPECT_TRUE(ambulance.getIsAvailable());
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(EmergencyProtocolTest, ConstructorAndOperations) {
    EmergencyProtocol protocol("CPR", "Cardiopulmonary resuscitation", "Life Support", 1);
    
    protocol.addStep("Check responsiveness");
    protocol.addStep("Call for help");
    protocol.addStep("Begin chest compressions");
    EXPECT_EQ(protocol.getSteps().size(), 3);
    
    testing::internal::CaptureStdout();
    protocol.executeProtocol();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(ExceptionsTest, ThrowInvalidArgument) {
    EXPECT_THROW(Exceptions::throwInvalidArgument("Test message"), invalid_argument);
}

TEST(ExceptionsTest, ThrowInvalidPayment) {
    EXPECT_THROW(Exceptions::throwInvalidPayment("Test message"), runtime_error);
}

TEST(ExceptionsTest, ThrowCapacityExceeded) {
    EXPECT_THROW(Exceptions::throwCapacityExceeded("Test message"), runtime_error);
}

TEST(ExceptionsTest, ThrowAppointmentNotFound) {
    EXPECT_THROW(Exceptions::throwAppointmentNotFound("Test message"), runtime_error);
}

TEST(ExceptionsTest, ThrowPatientNotFound) {
    EXPECT_THROW(Exceptions::throwPatientNotFound("Test message"), runtime_error);
}

TEST(ExceptionsTest, ThrowDoctorNotFound) {
    EXPECT_THROW(Exceptions::throwDoctorNotFound("Test message"), runtime_error);
}

TEST(ExceptionsTest, ThrowDepartmentNotFound) {
    EXPECT_THROW(Exceptions::throwDepartmentNotFound("Test message"), runtime_error);
}

TEST(ExceptionsTest, ThrowEquipmentUnavailable) {
    EXPECT_THROW(Exceptions::throwEquipmentUnavailable("Test message"), runtime_error);
}

TEST(ExceptionsTest, ThrowInsufficientFunds) {
    EXPECT_THROW(Exceptions::throwInsufficientFunds("Test message"), runtime_error);
}

TEST(ExceptionsTest, ThrowInvalidPrescription) {
    EXPECT_THROW(Exceptions::throwInvalidPrescription("Test message"), runtime_error);
}

TEST(ExceptionsTest, ThrowRoomUnavailable) {
    EXPECT_THROW(Exceptions::throwRoomUnavailable("Test message"), runtime_error);
}

TEST(ExceptionsTest, ThrowInvalidOperation) {
    EXPECT_THROW(Exceptions::throwInvalidOperation("Test message"), runtime_error);
}

TEST(PolyclinicTest, ConstructorAndOperations) {
    Polyclinic polyclinic("City Clinic", "123 Main St");
    
    EXPECT_EQ(polyclinic.getName(), "City Clinic");
    EXPECT_EQ(polyclinic.getAddress(), "123 Main St");
    
    Department* dept = new Department("Cardiology", "Medical");
    polyclinic.addDepartment(dept);
    EXPECT_EQ(polyclinic.getDepartments().size(), 1);
    
    polyclinic.removeDepartment(dept);
    EXPECT_EQ(polyclinic.getDepartments().size(), 0);
    
    delete dept;
}

TEST(CabinetTest, ConstructorAndOperations) {
    Department* dept = new Department("Cardiology", "Medical");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, dept, "Cardiology");
    Cabinet cabinet("CAB-101", doctor, dept);
    
    InventoryItem* item = new InventoryItem("Stethoscope", 5, 2);
    cabinet.addInventoryItem(item);
    EXPECT_EQ(cabinet.getInventory().size(), 1);
    
    cabinet.removeInventoryItem(item);
    EXPECT_EQ(cabinet.getInventory().size(), 0);
    
    delete item;
    delete doctor;
    delete dept;
}

TEST(CleanerTest, ConstructorAndOperations) {
    Department* dept = new Department("Cardiology", "Medical");
    vector<Department*> depts = {dept};
    Cleaner cleaner("Mike", "Johnson", 40, 5, 2500.0, 2, "Day", depts, "Vacuum");
    
    testing::internal::CaptureStdout();
    cleaner.work();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    Department* dept2 = new Department("Surgery", "Medical");
    cleaner.assignDepartment(dept2);
    EXPECT_EQ(cleaner.getAssignedDepartments().size(), 2);
    
    cleaner.clearDepartments();
    EXPECT_EQ(cleaner.getAssignedDepartments().size(), 0);
    
    delete dept;
    delete dept2;
}

TEST(NurseTest, ConstructorAndOperations) {
    Department* dept = new Department("Cardiology", "Medical");
    Nurse nurse("Sarah", "Brown", 28, 6, 3500.0, 2, dept, "Cardiac Care", 15);
    
    EXPECT_EQ(nurse.getPatientCapacity(), 15);
    testing::internal::CaptureStdout();
    nurse.work();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(ReceptionistTest, ConstructorAndOperations) {
    Polyclinic* polyclinic = new Polyclinic("City Clinic", "123 Main St");
    Receptionist receptionist("Emma", "Davis", 25, 7, 3000.0, 1, polyclinic, "Day", 25);
    
    EXPECT_EQ(receptionist.getAppointmentsPerDay(), 25);
    testing::internal::CaptureStdout();
    receptionist.work();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete polyclinic;
}

TEST(TestResultTest, ConstructorAndOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    LabTest* test = new LabTest(patient, doctor, "Blood Test", "2024-01-15", 1);
    TestResult result(test, "2024-01-16", "120/80", "Normal", 1);
    
    testing::internal::CaptureStdout();
    result.interpretResults();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete test;
    delete patient;
    delete doctor;
}

TEST(PersonTest, PrintMethod) {
    Person person("John", "Doe", 30);
    testing::internal::CaptureStdout();
    person.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("John"), std::string::npos);
    EXPECT_NE(output.find("Doe"), std::string::npos);
}

TEST(PersonTest, EdgeCases) {
    Person person1("", "", 0);
    EXPECT_EQ(person1.getFirstName(), "");
    EXPECT_EQ(person1.getSurname(), "");
    EXPECT_EQ(person1.getAge(), 0);
    
    Person person2("VeryLongFirstNameThatMightCauseIssues", "VeryLongSurname", 150);
    EXPECT_EQ(person2.getAge(), 150);
}

TEST(EmployeeTest, Setters) {
    Department* dept = new Department("Cardiology", "Medical");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, dept, "Cardiology");
    
    doctor->setId(10);
    doctor->setPosition("Senior Doctor");
    doctor->setSalary(6000.0);
    
    EXPECT_EQ(doctor->getId(), 10);
    EXPECT_EQ(doctor->getPosition(), "Senior Doctor");
    EXPECT_EQ(doctor->getSalary(), 6000.0);
    
    delete doctor;
    delete dept;
}

TEST(DoctorTest, PrintMethod) {
    Department* dept = new Department("Cardiology", "Medical");
    Doctor doctor("John", "Doe", 35, 1, 5000.0, 5, dept, "Cardiology");
    testing::internal::CaptureStdout();
    doctor.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    delete dept;
}

TEST(PatientTest, PrintMethod) {
    Patient patient("Jane", "Smith", 28, "Female");
    testing::internal::CaptureStdout();
    patient.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(PatientTest, MedicalCardOperations) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    MedicalCard* card = new MedicalCard(1, patient);
    patient->setMedicalCard(card);
    EXPECT_NE(patient->getMedicalCard(), nullptr);
    delete card;
    delete patient;
}

TEST(DepartmentTest, PrintMethod) {
    Department dept("Cardiology", "Medical");
    testing::internal::CaptureStdout();
    dept.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(DepartmentTest, ClearAll) {
    Department dept("Cardiology", "Medical");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, &dept, "Cardiology");
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    
    dept.addDoctor(doctor);
    dept.addPatient(patient);
    EXPECT_EQ(dept.getDoctors().size(), 1);
    EXPECT_EQ(dept.getPatients().size(), 1);
    
    dept.clearAll();
    EXPECT_EQ(dept.getDoctors().size(), 0);
    EXPECT_EQ(dept.getPatients().size(), 0);
    
    delete doctor;
    delete patient;
}

TEST(DepartmentTest, SetPolyclinic) {
    Department dept("Cardiology", "Medical");
    Polyclinic* poly = new Polyclinic("City Clinic", "123 Main St");
    dept.setPolyclinic(poly);
    EXPECT_EQ(dept.getPolyclinic(), poly);
    delete poly;
}

TEST(AppointmentTest, CancelAppointment) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    Appointment appointment(patient, doctor, "2024-01-15 10:00", "Checkup", 1);
    
    testing::internal::CaptureStdout();
    appointment.cancelAppointment();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

TEST(AppointmentTest, SetCost) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    Appointment appointment(patient, doctor, "2024-01-15 10:00", "Checkup", 1);
    
    appointment.setCost(100.0);
    EXPECT_EQ(appointment.getCost(), 100.0);
    
    appointment.setCost(-50.0);
    EXPECT_EQ(appointment.getCost(), 100.0);
    
    delete patient;
    delete doctor;
}

TEST(PrescriptionTest, AddRemoveMedications) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    vector<string> meds = {"Aspirin"};
    Prescription prescription(patient, doctor, "2024-01-15", meds, "1 daily", "With food", 1);
    
    prescription.addMedication("Vitamin D");
    EXPECT_EQ(prescription.getMedications().size(), 2);
    
    prescription.removeMedication("Aspirin");
    EXPECT_EQ(prescription.getMedications().size(), 1);
    
    delete patient;
    delete doctor;
}

TEST(PrescriptionTest, SetMethods) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    vector<string> meds = {"Aspirin"};
    Prescription prescription(patient, doctor, "2024-01-15", meds, "1 daily", "With food", 1);
    
    prescription.setDate("2024-01-16");
    prescription.setDosage("2 daily");
    prescription.setInstructions("Take with water");
    
    delete patient;
    delete doctor;
}

TEST(MedicalCardTest, ClearHistory) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    MedicalCard card(1, patient);
    
    card.addMedicalRecord("Record 1");
    card.addMedicalRecord("Record 2");
    EXPECT_EQ(card.getMedicalHistory().size(), 2);
    
    card.clearHistory();
    EXPECT_EQ(card.getMedicalHistory().size(), 0);
    
    delete patient;
}

TEST(MedicalCardTest, SetBloodTypeAndAllergies) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    MedicalCard card(1, patient);
    
    card.setBloodType("O+");
    card.setAllergies("Peanuts, Shellfish");
    
    EXPECT_EQ(card.getBloodType(), "O+");
    EXPECT_EQ(card.getAllergies(), "Peanuts, Shellfish");
    
    delete patient;
}

TEST(InventoryItemTest, SetMethods) {
    InventoryItem item("Syringe", 100, 20);
    item.setName("Needle");
    item.setQuantity(200);
    item.setMinStockLevel(30);
    
    EXPECT_EQ(item.getName(), "Needle");
    EXPECT_EQ(item.getQuantity(), 200);
    EXPECT_EQ(item.getMinStockLevel(), 30);
}

TEST(ConsultationServiceTest, SetCost) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    ConsultationService service(patient, doctor, "2024-01-15", "10:00", "Headache", 50.0);
    
    service.setCost(75.0);
    EXPECT_EQ(service.getCost(), 75.0);
    
    service.setCost(-10.0);
    EXPECT_EQ(service.getCost(), 75.0);
    
    delete patient;
    delete doctor;
}

TEST(SurgeryServiceTest, ScheduleAndCancel) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    SurgeryService service(patient, doctor, "Appendectomy", "2024-01-15", "14:00", 5000.0, 120, 1);
    
    testing::internal::CaptureStdout();
    service.scheduleSurgery();
    service.cancelSurgery();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

TEST(SurgeryServiceTest, SetMethods) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    SurgeryService service(patient, doctor, "Appendectomy", "2024-01-15", "14:00", 5000.0, 120, 1);
    
    service.setSurgeryType("Laparoscopy");
    service.setDate("2024-01-16");
    service.setTime("15:00");
    service.setCost(6000.0);
    service.setDuration(90);
    
    delete patient;
    delete doctor;
}

TEST(TherapyServiceTest, AddNotesAndComplete) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    TherapyService service(patient, doctor, "Physical Therapy", "2024-01-15", 10, 1);
    
    service.addNotes("Patient showing improvement");
    service.conductSession();
    service.conductSession();
    
    while (!service.isCompleted()) {
        service.conductSession();
    }
    
    EXPECT_TRUE(service.isCompleted());
    
    delete patient;
    delete doctor;
}

TEST(VaccinationServiceTest, SetMethods) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    VaccinationService service(patient, doctor, "COVID-19", "2024-01-15", "BATCH123", 1, 1);
    
    service.setVaccineName("Flu");
    service.setDate("2024-01-16");
    service.setBatchNumber("BATCH456");
    service.setDoseNumber(2);
    
    delete patient;
    delete doctor;
}

TEST(PatientRecordTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    PatientRecord record(patient, "2024-01-15", "Fever", 1);
    
    testing::internal::CaptureStdout();
    record.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
}

TEST(TreatmentRecordTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    TreatmentRecord record(patient, doctor, "2024-01-15", "Medication", "Antibiotics course", 1);
    
    testing::internal::CaptureStdout();
    record.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

TEST(DiagnosisRecordTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    DiagnosisRecord record(patient, doctor, "2024-01-15", "Migraine", "Headache, nausea", 1);
    
    testing::internal::CaptureStdout();
    record.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

TEST(SurgeryReportTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    SurgeryReport report(patient, doctor, "2024-01-15", "Appendectomy", "Laparoscopic removal", 1);
    
    testing::internal::CaptureStdout();
    report.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

TEST(LabReportTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    LabReport report(patient, doctor, "2024-01-15", "Blood Test", "Normal range", 1);
    
    testing::internal::CaptureStdout();
    report.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

TEST(ShiftTest, PrintMethod) {
    Shift shift("2024-01-15", "08:00", "16:00", "Day");
    testing::internal::CaptureStdout();
    shift.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(ScheduleTest, PrintMethod) {
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    Schedule schedule(doctor, "2024-01-15");
    
    testing::internal::CaptureStdout();
    schedule.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete doctor;
}

TEST(TaskTest, PrintMethod) {
    Employee* employee = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    Task task("Review reports", "Check patient reports", employee, "2024-01-20", 1, 1);
    
    testing::internal::CaptureStdout();
    task.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete employee;
}

TEST(MaintenanceTest, PrintMethod) {
    Department* dept = new Department("Cardiology", "Medical");
    MedicalEquipment* equipment = new MedicalEquipment("X-Ray", "Model X", "SN123", dept);
    Maintenance maintenance(equipment, "2024-01-15", "Routine", 1);
    
    testing::internal::CaptureStdout();
    maintenance.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete equipment;
    delete dept;
}

TEST(QualityControlTest, PrintMethod) {
    QualityControl qc("2024-01-15", "Cardiology", "Inspector Name", 1);
    
    testing::internal::CaptureStdout();
    qc.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(MedicalEquipmentTest, PrintMethod) {
    Department* dept = new Department("Cardiology", "Medical");
    MedicalEquipment equipment("X-Ray Machine", "Model X", "SN123", dept);
    
    testing::internal::CaptureStdout();
    equipment.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(XRayMachineTest, CalibrateAndPrint) {
    Department* dept = new Department("Radiology", "Medical");
    XRayMachine machine("Model X", "SN123", dept, 100, 50);
    
    testing::internal::CaptureStdout();
    machine.calibrate();
    machine.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(UltrasoundMachineTest, PerformUltrasoundAndPrint) {
    Department* dept = new Department("Radiology", "Medical");
    UltrasoundMachine machine("Model U", "SN456", dept);
    
    testing::internal::CaptureStdout();
    machine.performUltrasound();
    machine.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(BloodPressureMonitorTest, PrintMethod) {
    Department* dept = new Department("Cardiology", "Medical");
    BloodPressureMonitor monitor("Model BP", "SN789", dept);
    
    testing::internal::CaptureStdout();
    monitor.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(StethoscopeTest, PerformAuscultationAndPrint) {
    Department* dept = new Department("Cardiology", "Medical");
    Stethoscope stethoscope("3M", "Littmann", false, dept);
    
    testing::internal::CaptureStdout();
    stethoscope.performAuscultation();
    stethoscope.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(StethoscopeTest, SetMethods) {
    Department* dept = new Department("Cardiology", "Medical");
    Stethoscope stethoscope("3M", "Littmann", false, dept);
    
    stethoscope.setBrand("Welch Allyn");
    stethoscope.setType("Electronic");
    stethoscope.setIsElectronic(true);
    
    EXPECT_EQ(stethoscope.getBrand(), "Welch Allyn");
    EXPECT_EQ(stethoscope.getType(), "Electronic");
    EXPECT_TRUE(stethoscope.getIsElectronic());
    
    delete dept;
}

TEST(WaitingRoomTest, FullCapacity) {
    Department* dept = new Department("Cardiology", "Medical");
    WaitingRoom room("WR-101", dept, 2);
    
    Patient* patient1 = new Patient("Jane", "Smith", 28, "Female");
    Patient* patient2 = new Patient("John", "Doe", 35, "Male");
    
    room.addPatient(patient1);
    room.addPatient(patient2);
    EXPECT_TRUE(room.isFull());
    
    delete patient1;
    delete patient2;
    delete dept;
}

TEST(WaitingRoomTest, PrintMethod) {
    Department* dept = new Department("Cardiology", "Medical");
    WaitingRoom room("WR-101", dept, 20);
    
    testing::internal::CaptureStdout();
    room.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(OperatingRoomTest, PrintMethod) {
    Department* dept = new Department("Surgery", "Medical");
    OperatingRoom room("OR-201", dept);
    
    testing::internal::CaptureStdout();
    room.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(LabRoomTest, PrintMethod) {
    LabRoom room("LAB-301", "Chemistry", 10);
    
    testing::internal::CaptureStdout();
    room.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(StorageRoomTest, FullCapacity) {
    StorageRoom room("ST-401", "Medical Supplies", 2);
    
    InventoryItem* item1 = new InventoryItem("Syringe", 50, 10);
    InventoryItem* item2 = new InventoryItem("Bandage", 100, 20);
    
    room.addItem(item1);
    room.addItem(item2);
    EXPECT_TRUE(room.isFull());
    
    delete item1;
    delete item2;
}

TEST(StorageRoomTest, PrintMethod) {
    StorageRoom room("ST-401", "Medical Supplies", 100);
    
    testing::internal::CaptureStdout();
    room.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(ParkingLotTest, FullCapacity) {
    ParkingLot lot("PARK-1", 2, true, 2.5);
    
    lot.parkVehicle();
    lot.parkVehicle();
    EXPECT_FALSE(lot.hasAvailableSpots());
    EXPECT_EQ(lot.getAvailableSpots(), 0);
}

TEST(ParkingLotTest, PrintMethod) {
    ParkingLot lot("PARK-1", 50, true, 2.5);
    
    testing::internal::CaptureStdout();
    lot.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}


TEST(BillTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Bill bill(patient, "2024-01-15", 500.0, 1);
    
    testing::internal::CaptureStdout();
    bill.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
}

TEST(InvoiceTest, IsOverdue) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Invoice invoice(patient, "2024-01-01", "2024-01-15", 1000.0, 1);
    
    testing::internal::CaptureStdout();
    invoice.markAsOverdue();
    bool overdue = invoice.isOverdue();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
}

TEST(InvoiceTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Invoice invoice(patient, "2024-01-15", "2024-02-15", 1000.0, 1);
    
    testing::internal::CaptureStdout();
    invoice.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
}

TEST(PaymentTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Payment payment(patient, "2024-01-15", 500.0, "Credit Card", 1);
    
    testing::internal::CaptureStdout();
    payment.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
}

TEST(InsuranceTest, SetMethods) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Insurance insurance("POL123", patient, "Health Insurance Co", "Premium", 10000.0, "2025-12-31");
    
    insurance.setPolicyNumber("POL456");
    insurance.setInsuranceCompany("New Insurance Co");
    insurance.setPolicyType("Basic");
    insurance.setExpiryDate("2026-12-31");
    
    delete patient;
}

TEST(InsuranceTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Insurance insurance("POL123", patient, "Health Insurance Co", "Premium", 10000.0, "2025-12-31");
    
    testing::internal::CaptureStdout();
    insurance.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
}

TEST(LabTestTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    LabTest test(patient, doctor, "Blood Test", "2024-01-15", 1);
    
    testing::internal::CaptureStdout();
    test.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

TEST(LabSampleTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    LabSample sample(patient, "Blood", "2024-01-15", 1);
    
    testing::internal::CaptureStdout();
    sample.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
}

TEST(LabTechnicianTest, SetSpecialization) {
    LabTechnician tech("Alice", "Johnson", 30, 10, 3500.0, 3, "Hematology");
    
    tech.setSpecialization("Microbiology");
    EXPECT_EQ(tech.getSpecialization(), "Microbiology");
}

TEST(LabTechnicianTest, PrintMethod) {
    LabTechnician tech("Alice", "Johnson", 30, 10, 3500.0, 3, "Hematology");
    
    testing::internal::CaptureStdout();
    tech.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(MedicationTest, PrintMethod) {
    Medication med("Aspirin", "Acetylsalicylic acid", "Pharma Co", 100, 5.50, "2025-12-31");
    
    testing::internal::CaptureStdout();
    med.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(PharmacyStockTest, PrintMethod) {
    PharmacyStock stock;
    Medication* med1 = new Medication("Aspirin", "ASA", "Pharma", 100, 5.50, "2025-12-31");
    stock.addMedication(med1);
    
    testing::internal::CaptureStdout();
    stock.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete med1;
}

TEST(PrescriptionOrderTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    vector<string> meds = {"Aspirin"};
    Prescription* prescription = new Prescription(patient, doctor, "2024-01-15", meds, "1 daily", "With food", 1);
    PrescriptionOrder order(prescription, patient, doctor, "2024-01-15", 25.50, 1);
    
    testing::internal::CaptureStdout();
    order.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete prescription;
    delete patient;
    delete doctor;
}

TEST(PharmacistTest, PrintMethod) {
    Pharmacist pharmacist("Bob", "Williams", 32, 11, 4000.0, 4, "PHARM123");
    
    testing::internal::CaptureStdout();
    pharmacist.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(EmergencyCaseTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Emergency");
    EmergencyCase emergency(patient, doctor, "2024-01-15 14:30", "Chest pain", 3, 1);
    
    testing::internal::CaptureStdout();
    emergency.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

TEST(AmbulanceTest, PrintMethod) {
    Ambulance ambulance("AMB-001", "Driver Name", 2);
    
    testing::internal::CaptureStdout();
    ambulance.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(EmergencyProtocolTest, PrintMethod) {
    EmergencyProtocol protocol("CPR", "Cardiopulmonary resuscitation", "Life Support", 1);
    
    testing::internal::CaptureStdout();
    protocol.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(PolyclinicTest, PrintInfo) {
    Polyclinic polyclinic("City Clinic", "123 Main St");
    
    testing::internal::CaptureStdout();
    polyclinic.printInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(PolyclinicTest, SetMethods) {
    Polyclinic polyclinic("City Clinic", "123 Main St");
    
    polyclinic.setName("New Clinic");
    polyclinic.setAddress("456 New St");
    
    EXPECT_EQ(polyclinic.getName(), "New Clinic");
    EXPECT_EQ(polyclinic.getAddress(), "456 New St");
}

TEST(CabinetTest, PrintMethod) {
    Department* dept = new Department("Cardiology", "Medical");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, dept, "Cardiology");
    Cabinet cabinet("CAB-101", doctor, dept);
    
    testing::internal::CaptureStdout();
    cabinet.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete doctor;
    delete dept;
}

TEST(CabinetTest, SetMethods) {
    Department* dept = new Department("Cardiology", "Medical");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, dept, "Cardiology");
    Cabinet cabinet("CAB-101", doctor, dept);
    
    cabinet.setNumber("CAB-102");
    cabinet.setDoctor(doctor);
    cabinet.setDepartment(dept);
    
    EXPECT_EQ(cabinet.getNumber(), "CAB-102");
    
    delete doctor;
    delete dept;
}

TEST(CleanerTest, PrintMethod) {
    Department* dept = new Department("Cardiology", "Medical");
    vector<Department*> depts = {dept};
    Cleaner cleaner("Mike", "Johnson", 40, 5, 2500.0, 2, "Day", depts, "Vacuum");
    
    testing::internal::CaptureStdout();
    cleaner.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(CleanerTest, SetMethods) {
    Department* dept = new Department("Cardiology", "Medical");
    vector<Department*> depts = {dept};
    Cleaner cleaner("Mike", "Johnson", 40, 5, 2500.0, 2, "Day", depts, "Vacuum");
    
    cleaner.setWorkShift("Night");
    cleaner.setEquipment("Mop");
    
    EXPECT_EQ(cleaner.getWorkShift(), "Night");
    EXPECT_EQ(cleaner.getEquipment(), "Mop");
    
    delete dept;
}

TEST(NurseTest, SetMethods) {
    Department* dept = new Department("Cardiology", "Medical");
    Nurse nurse("Sarah", "Brown", 28, 6, 3500.0, 2, dept, "Cardiac Care", 15);
    
    nurse.setSpecialization("Pediatrics");
    nurse.setPatientCapacity(20);
    nurse.setDepartment(dept);
    
    EXPECT_EQ(nurse.getSpecialization(), "Pediatrics");
    EXPECT_EQ(nurse.getPatientCapacity(), 20);
    
    delete dept;
}

TEST(NurseTest, PrintMethod) {
    Department* dept = new Department("Cardiology", "Medical");
    Nurse nurse("Sarah", "Brown", 28, 6, 3500.0, 2, dept, "Cardiac Care", 15);
    
    testing::internal::CaptureStdout();
    nurse.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dept;
}

TEST(ReceptionistTest, SetMethods) {
    Polyclinic* polyclinic = new Polyclinic("City Clinic", "123 Main St");
    Receptionist receptionist("Emma", "Davis", 25, 7, 3000.0, 1, polyclinic, "Day", 25);
    
    receptionist.setPolyclinic(polyclinic);
    receptionist.setWorkShift("Night");
    receptionist.setAppointmentsPerDay(30);
    
    EXPECT_EQ(receptionist.getWorkShift(), "Night");
    EXPECT_EQ(receptionist.getAppointmentsPerDay(), 30);
    
    delete polyclinic;
}

TEST(ReceptionistTest, PrintMethod) {
    Polyclinic* polyclinic = new Polyclinic("City Clinic", "123 Main St");
    Receptionist receptionist("Emma", "Davis", 25, 7, 3000.0, 1, polyclinic, "Day", 25);
    
    testing::internal::CaptureStdout();
    receptionist.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete polyclinic;
}

TEST(TestResultTest, SetMethods) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    LabTest* test = new LabTest(patient, doctor, "Blood Test", "2024-01-15", 1);
    TestResult result(test, "2024-01-16", "120/80", "Normal", 1);
    
    result.setResultDate("2024-01-17");
    result.setValues("130/85");
    result.setNormalRange("120-140/80-90");
    result.setInterpretation("Slightly elevated");
    
    delete test;
    delete patient;
    delete doctor;
}

TEST(TestResultTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    LabTest* test = new LabTest(patient, doctor, "Blood Test", "2024-01-15", 1);
    TestResult result(test, "2024-01-16", "120/80", "Normal", 1);
    
    testing::internal::CaptureStdout();
    result.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete test;
    delete patient;
    delete doctor;
}

TEST(PrescriptionTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    vector<string> meds = {"Aspirin", "Vitamin D"};
    Prescription prescription(patient, doctor, "2024-01-15", meds, "1 tablet daily", "Take with food", 1);
    
    testing::internal::CaptureStdout();
    prescription.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

TEST(AppointmentTest, PrintMethod) {
    Patient* patient = new Patient("Jane", "Smith", 28, "Female");
    Doctor* doctor = new Doctor("John", "Doe", 35, 1, 5000.0, 5, nullptr, "Cardiology");
    Appointment appointment(patient, doctor, "2024-01-15 10:00", "Checkup", 1);
    
    testing::internal::CaptureStdout();
    appointment.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete patient;
    delete doctor;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

