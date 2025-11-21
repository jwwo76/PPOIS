Поликлиника

Классы: 55

Поля: 294

Методы: 385

Ассоциации: 75

Исключения: 12

Исключения (12)

Все в классе Exceptions (статические методы для throw):

throwInvalidArgument("Invalid argument")
throwInvalidPayment("Invalid payment method")
throwCapacityExceeded("Capacity exceeded")
throwAppointmentNotFound("Appointment not found")
throwPatientNotFound("Patient not found")
throwDoctorNotFound("Doctor not found")
throwDepartmentNotFound("Department not found")
throwEquipmentUnavailable("Equipment unavailable")
throwInsufficientFunds("Insufficient funds")
throwInvalidPrescription("Invalid prescription")
throwRoomUnavailable("Room unavailable")
throwInvalidOperation("Invalid operation")

Классы

Формат: Класс Поля Методы → Ассоциации (классы как поля/параметры)

Core/

Polyclinic 3 8 → Department

Поля: address_, name_, departments_

Методы: getName, getAddress, getDepartments, setName, setAddress, addDepartment, removeDepartment, printInfo

Department 6 15 → Polyclinic, Doctor, Cleaner, Patient

Поля: name_, type_, polyclinic_, doctors_, cleaners_, patients_

Методы: getName, getType, getPolyclinic, getDoctors, getCleaners, getPatients, setName, setType, setPolyclinic, addDoctor, addCleaner, addPatient, removeDoctor, removeCleaner, removePatient, clearAll, print

Cabinet 4 10 → Doctor, Department, InventoryItem

Поля: number_, doctor_, department_, inventory_

Методы: getNumber, getDoctor, getDepartment, getInventory, setNumber, setDoctor, setDepartment, addInventoryItem, removeInventoryItem, print

Persons/

Person 3 7

Поля: firstName_, surname_, age_

Методы: setFirstName, setSurname, setAge, getFirstName, getSurname, getAge, print

Employee 4 9 → Person

Поля: id_, position_, salary_, experience_

Методы: getId, getPosition, getSalary, setId, setPosition, setSalary, work, print

Doctor 2 2 → Employee, Department

Поля: department_, specialization_

Методы: work, print

Cleaner 3 7 → Employee, Department

Поля: workShift_, assignedDepartments_, equipment_

Методы: work, assignDepartment, clearDepartments, getAssignedDepartments, getWorkShift, getEquipment, setWorkShift, setEquipment, print

Patient 3 6 → Person, MedicalCard

Поля: gender_, medicalCard_, status_

Методы: getGender, getMedicalCard, getStatus, setGender, setMedicalCard, setStatus, print

Nurse 3 9 → Employee, Department

Поля: department_, specialization_, patientCapacity_

Методы: work, print, getSpecialization, getPatientCapacity, getDepartment, setSpecialization, setPatientCapacity, setDepartment

Receptionist 3 8 → Employee, Polyclinic

Поля: polyclinic_, workShift_, appointmentsPerDay_

Методы: work, print, getPolyclinic, getWorkShift, getAppointmentsPerDay, setPolyclinic, setWorkShift, setAppointmentsPerDay

Staff/

Appointment 7 11 → Patient, Doctor

Поля: appointmentId_, patient_, doctor_, dateTime_, reason_, isCompleted_, cost_

Методы: getAppointmentId, getPatient, getDoctor, getDateTime, getReason, getIsCompleted, getCost, setDateTime, setReason, setCost, reschedule, completeAppointment, cancelAppointment, print

Prescription 7 10 → Patient, Doctor

Поля: prescriptionId_, patient_, doctor_, date_, medications_, dosage_, instructions_, isFilled_

Методы: getPrescriptionId, getPatient, getDoctor, getDate, getMedications, getDosage, getInstructions, getIsFilled, setDate, setDosage, setInstructions, addMedication, removeMedication, fillPrescription, print

MedicalCard 6 8 → Patient

Поля: cardId_, patient_, medicalHistory_, currentMedications_, bloodType_, allergies_

Методы: getCardId, getPatient, getMedicalHistory, getCurrentMedications, getBloodType, getAllergies, setBloodType, setAllergies, addMedicalRecord, addMedication, removeMedication, clearHistory, print

InventoryItem 3 8

Поля: name_, quantity_, minStockLevel_

Методы: getName, getQuantity, getMinStockLevel, setName, setQuantity, setMinStockLevel, updateQuantity, needsReorder, restock, useItem, print

Services/

ConsultationService 7 6 → Patient, Doctor

Поля: patient_, doctor_, date_, time_, complaint_, diagnosis_, cost_

Методы: getPatient, getDoctor, getDate, getDiagnosis, getCost, setCost, conductConsultation, provideDiagnosis, print

DiagnosticService 7 7 → Patient, Doctor

Поля: serviceId_, patient_, doctor_, testType_, date_, result_, isCompleted_

Методы: getServiceId, getPatient, getDoctor, getTestType, getResult, getIsCompleted, setResult, performTest, completeTest, print

SurgeryService 9 11 → Patient, Doctor

Поля: surgeryId_, patient_, surgeon_, surgeryType_, date_, time_, status_, cost_, duration_

Методы: getSurgeryId, getPatient, getSurgeon, getSurgeryType, getDate, getTime, getStatus, getCost, getDuration, setSurgeryType, setDate, setTime, setStatus, setCost, setDuration, scheduleSurgery, performSurgery, completeSurgery, cancelSurgery, print

TherapyService 8 10 → Patient, Doctor

Поля: therapyId_, patient_, therapist_, therapyType_, date_, sessionNumber_, totalSessions_, notes_

Методы: getTherapyId, getPatient, getTherapist, getTherapyType, getDate, getSessionNumber, getTotalSessions, getNotes, setTherapyType, setDate, setTotalSessions, setNotes, conductSession, addNotes, completeSession, isCompleted, print

VaccinationService 7 10 → Patient, Doctor

Поля: vaccinationId_, patient_, doctor_, vaccineName_, date_, batchNumber_, nextDoseDate_, doseNumber_

Методы: getVaccinationId, getPatient, getDoctor, getVaccineName, getDate, getBatchNumber, getNextDoseDate, getDoseNumber, setVaccineName, setDate, setBatchNumber, setNextDoseDate, setDoseNumber, administerVaccine, scheduleNextDose, print

Records/

PatientRecord 7 5 → Patient

Поля: recordId_, patient_, admissionDate_, dischargeDate_, chiefComplaint_, treatments_, status_

Методы: getRecordId, getPatient, getAdmissionDate, getDischargeDate, getStatus, addTreatment, dischargePatient, print

TreatmentRecord 7 4 → Patient, Doctor

Поля: treatmentId_, patient_, doctor_, date_, treatmentType_, description_, outcome_

Методы: getTreatmentId, getPatient, getDoctor, getOutcome, recordOutcome, print

DiagnosisRecord 7 9 → Patient, Doctor

Поля: diagnosisId_, patient_, doctor_, date_, diagnosis_, symptoms_, recommendations_

Методы: getDiagnosisId, getPatient, getDoctor, getDate, getDiagnosis, getSymptoms, getRecommendations, setDate, setDiagnosis, setSymptoms, setRecommendations, addRecommendations, print

SurgeryReport 8 10 → Patient, Doctor

Поля: reportId_, patient_, surgeon_, surgeryDate_, surgeryType_, procedure_, complications_, recoveryNotes_, wasSuccessful_

Методы: getReportId, getPatient, getSurgeon, getSurgeryDate, getSurgeryType, getProcedure, getComplications, getRecoveryNotes, getWasSuccessful, setSurgeryDate, setSurgeryType, setProcedure, setComplications, setRecoveryNotes, setWasSuccessful, addComplications, addRecoveryNotes, markSuccessful, print

LabReport 7 8 → Patient, Doctor

Поля: reportId_, patient_, requestingDoctor_, testDate_, testType_, results_, normalRange_, isNormal_

Методы: getReportId, getPatient, getRequestingDoctor, getTestDate, getTestType, getResults, getNormalRange, getIsNormal, setTestDate, setTestType, setResults, setNormalRange, analyzeResults, print

Operations/

Shift 5 8 → Employee

Поля: date_, startTime_, endTime_, employees_, shiftType_

Методы: getDate, getStartTime, getEndTime, getEmployees, getShiftType, setDate, setStartTime, setEndTime, setShiftType, addEmployee, removeEmployee, print

Schedule 3 6 → Doctor

Поля: doctor_, weekStartDate_, appointments_

Методы: getDoctor, getWeekStartDate, getAppointments, setDoctor, setWeekStartDate, addAppointment, removeAppointment, isTimeSlotAvailable, print

Task 7 6 → Employee

Поля: taskId_, title_, description_, assignedTo_, dueDate_, status_, priority_

Методы: getTaskId, getTitle, getAssignedTo, getStatus, setAssignedTo, setStatus, completeTask, print

Maintenance 7 9 → MedicalEquipment

Поля: maintenanceId_, equipment_, scheduledDate_, completedDate_, maintenanceType_, notes_, isCompleted_

Методы: getMaintenanceId, getEquipment, getScheduledDate, getCompletedDate, getMaintenanceType, getNotes, getIsCompleted, setScheduledDate, setCompletedDate, setMaintenanceType, setNotes, completeMaintenance, print

QualityControl 7 6

Поля: controlId_, date_, department_, inspector_, issues_, recommendations_, score_

Методы: getControlId, getDepartment, getIssues, getRecommendations, getScore, addIssue, addRecommendation, calculateScore, print

Equipment/

MedicalEquipment 6 7 → Department

Поля: name_, model_, serialNumber_, department_, isFunctional_, lastMaintenanceDate_

Методы: getName, getDepartment, getIsFunctional, getLastMaintenanceDate, setDepartment, setIsFunctional, performMaintenance, reportMalfunction, print

XRayMachine 4 5 → MedicalEquipment, Department

Поля: radiationLevel_, maxDosePerDay_, currentDoseToday_, requiresCalibration_

Методы: getMaxDosePerDay, getCurrentDoseToday, getRequiresCalibration, performXRay, calibrate, resetDailyDose, print

UltrasoundMachine 3 4 → MedicalEquipment, Department

Поля: probeType_, frequency_, dopplerEnabled_

Методы: getDopplerEnabled, setDopplerEnabled, performUltrasound, enableDoppler, disableDoppler, print

BloodPressureMonitor 4 3 → MedicalEquipment, Department

Поля: cuffSize_, isDigital_, lastSystolic_, lastDiastolic_

Методы: getLastSystolic, getLastDiastolic, measureBloodPressure, print

Stethoscope 4 5 → Department

Поля: brand_, type_, isElectronic_, department_

Методы: getBrand, getType, getIsElectronic, getDepartment, setBrand, setType, setIsElectronic, setDepartment, performAuscultation, print

Facilities/

WaitingRoom 6 6 → Department, Patient

Поля: roomNumber_, department_, capacity_, patients_, hasAirConditioning_, hasTelevision_

Методы: getRoomNumber, getDepartment, getCapacity, getPatients, setDepartment, setCapacity, addPatient, removePatient, isFull, print

OperatingRoom 6 5 → Department

Поля: roomNumber_, department_, isAvailable_, equipmentList_, roomSize_, hasVentilation_

Методы: getRoomNumber, getDepartment, getIsAvailable, getRoomSize, setDepartment, setIsAvailable, reserveRoom, releaseRoom, print

LabRoom 5 5

Поля: roomNumber_, labType_, capacity_, hasSafetyEquipment_, equipment_

Методы: getRoomNumber, getLabType, getCapacity, getEquipment, setCapacity, addEquipment, removeEquipment, print

StorageRoom 6 6 → InventoryItem

Поля: roomNumber_, storageType_, capacity_, items_, isTemperatureControlled_, temperature_

Методы: getRoomNumber, getStorageType, getCapacity, getItems, getTemperature, setCapacity, setTemperature, addItem, removeItem, isFull, print

ParkingLot 5 5

Поля: lotId_, totalSpots_, occupiedSpots_, isCovered_, hourlyRate_

Методы: getLotId, getTotalSpots, getAvailableSpots, getHourlyRate, setTotalSpots, setHourlyRate, parkVehicle, releaseSpot, hasAvailableSpots, print

Billing/

Bill 7 6 → Patient

Поля: billId_, patient_, date_, totalAmount_, paidAmount_, status_, services_

Методы: getBillId, getPatient, getTotalAmount, getBalance, getStatus, addService, makePayment, updateStatus, print

Invoice 7 5 → Patient

Поля: invoiceId_, patient_, issueDate_, dueDate_, amount_, status_, paymentMethod_

Методы: getInvoiceId, getPatient, getAmount, getStatus, markAsPaid, markAsOverdue, isOverdue, print

Payment 7 5 → Patient

Поля: paymentId_, patient_, date_, amount_, paymentMethod_, transactionId_, status_

Методы: getPaymentId, getPatient, getAmount, getStatus, setStatus, processPayment, confirmPayment, print

Insurance 7 8 → Patient

Поля: policyNumber_, patient_, insuranceCompany_, policyType_, coverageAmount_, remainingCoverage_, expiryDate_

Методы: getPolicyNumber, getPatient, getInsuranceCompany, getPolicyType, getCoverageAmount, getRemainingCoverage, getExpiryDate, setPolicyNumber, setInsuranceCompany, setPolicyType, setExpiryDate, useCoverage, isExpired, hasCoverage, print

Laboratory/

LabTest 7 6 → Patient, Doctor

Поля: testId_, patient_, requestingDoctor_, testType_, date_, result_, isCompleted_

Методы: getTestId, getPatient, getRequestingDoctor, getTestType, getResult, getIsCompleted, setResult, performTest, completeTest, print

LabSample 6 4 → Patient

Поля: sampleId_, patient_, sampleType_, collectionDate_, storageLocation_, isProcessed_

Методы: getSampleId, getPatient, getSampleType, getIsProcessed, setStorageLocation, processSample, print

LabTechnician 2 4 → Employee

Поля: specialization_, testsPerformed_

Методы: getSpecialization, getTestsPerformed, setSpecialization, work, performTest, print

TestResult 6 7 → LabTest

Поля: resultId_, test_, resultDate_, values_, normalRange_, interpretation_

Методы: getResultId, getTest, getResultDate, getValues, getNormalRange, getInterpretation, setResultDate, setValues, setNormalRange, setInterpretation, interpretResults, print

Pharmacy/

Medication 7 5

Поля: name_, genericName_, manufacturer_, quantity_, price_, expiryDate_, prescriptionRequired_

Методы: getName, getQuantity, getPrice, getExpiryDate, setQuantity, setPrice, dispense, restock, isExpired, print

PharmacyStock 3 6 → Medication

Поля: medications_, totalItems_, totalValue_

Методы: getMedications, getTotalItems, getTotalValue, addMedication, removeMedication, findMedication, updateStock, print

PrescriptionOrder 7 8 → Prescription, Patient, Doctor

Поля: orderId_, prescription_, patient_, doctor_, orderDate_, status_, totalCost_

Методы: getOrderId, getPrescription, getPatient, getDoctor, getOrderDate, getStatus, getTotalCost, setOrderDate, setStatus, setTotalCost, processOrder, fulfillOrder, print

Pharmacist 2 4 → Employee

Поля: licenseNumber_, prescriptionsDispensed_

Методы: getLicenseNumber, getPrescriptionsDispensed, setLicenseNumber, work, dispensePrescription, print

Emergency/

EmergencyCase 7 9 → Patient, Doctor

Поля: caseId_, patient_, attendingDoctor_, arrivalTime_, condition_, severityLevel_, status_

Методы: getCaseId, getPatient, getAttendingDoctor, getArrivalTime, getCondition, getSeverityLevel, getStatus, setArrivalTime, setCondition, setSeverityLevel, setStatus, triage, treat, discharge, print

Ambulance 5 6

Поля: vehicleId_, driverName_, isAvailable_, currentLocation_, capacity_

Методы: getVehicleId, getDriverName, getIsAvailable, getCurrentLocation, getCapacity, setVehicleId, setDriverName, setCurrentLocation, setCapacity, dispatch, returnToStation, print

EmergencyProtocol 5 6

Поля: protocolId_, protocolName_, description_, steps_, category_

Методы: getProtocolId, getProtocolName, getDescription, getSteps, getCategory, setProtocolName, setDescription, setCategory, addStep, executeProtocol, print

Exceptions/

Exceptions 0 12

Методы: throwInvalidArgument, throwInvalidPayment, throwCapacityExceeded, throwAppointmentNotFound, throwPatientNotFound, throwDoctorNotFound, throwDepartmentNotFound, throwEquipmentUnavailable, throwInsufficientFunds, throwInvalidPrescription, throwRoomUnavailable, throwInvalidOperation
