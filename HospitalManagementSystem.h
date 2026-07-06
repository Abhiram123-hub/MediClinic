
#ifndef HOSPITALMANAGEMENTSYSTEM_HOSPITALMANAGEMENTSYSTEM_H
#define HOSPITALMANAGEMENTSYSTEM_HOSPITALMANAGEMENTSYSTEM_H

// HospitalManagementSystem.h

#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Appointment.h"
#include <fstream>
#include <iostream>
#include <vector>

class HospitalManagementSystem
{
public:
    // Constructor
    HospitalManagementSystem();

    // State-related functions
    void loadState(const std::string &filePath); // Load the state of the hospital from a file
    void saveState(const std::string &filePath); // Save the state of the hospital to a file

    // Patient Operations
    void registerNewPatient(const std::string &name, const std::string &dateOfBirth, const std::string &gender, const std::string &admissionTime, int insuranceOption); // Register a new patient
    void displayPatientDetails(const std::string &patientID);                                                                                                           // Display details of a specific patient
    void addPatientIllness(const std::string &patientID, const std::string &illness);                                                                                   // Add illness to a patient
    void addPatientMedication(const std::string &patientID, const std::string &medication);                                                                             // Add medication to a patient

    // Doctor Operations
    void addDoctor(const std::string &name, const std::string &specialization, const std::vector<std::string> &acceptedInsurances); // Add a new doctor
    void displayDoctorDetails(const std::string &doctorID);                                                                         // Display details of a specific doctor

    // Display Operations
    void displayAllPatients(); // Display details of all patients
    void displayAllDoctors();  // Display details of all doctors

    // Appointment Operations
    void scheduleAppointment(const std::string &patientID, const std::string &doctorID); // Schedule an appointment
    void setFollowUpDate(const std::string &patientID, const std::string &followUpDate); // Set a follow-up date for a patient

    // Nurse Operations
    void addNurse(const std::string &name); // Add a new nurse
    void displayAllNurses();                // Display details of all nurses

    // Advanced Appointment Operations
    void scheduleAppointment(const std::string &patientID, const std::string &doctorID, const std::string &nurseID, const std::string &dateTime); // Schedule an appointment with a specific nurse
    void displayAllAppointments();                                                                                                                // Display details of all appointments

private:
    // Hospital data
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<Nurse> nurses;
    std::vector<Appointment> appointments;

    // Helper functions to find objects by ID
    Patient &findPatientByID(const std::string &patientID);
    Doctor &findDoctorByID(const std::string &doctorID);
    Nurse &findNurseByID(const std::string &nurseID);
};

#endif //HOSPITALMANAGEMENTSYSTEM_HOSPITALMANAGEMENTSYSTEM_H
