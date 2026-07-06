// HospitalManagementSystem.cpp
#include "HospitalManagementSystem.h"
#include <algorithm> // For std::find_if
#include <iostream>
#include <iterator> // Add this line
#include <sstream>

// Constructor
HospitalManagementSystem::HospitalManagementSystem()
{
    // Initialization if needed
}

// Save the state of the hospital to a file
void HospitalManagementSystem::saveState(const std::string &filePath)
{
    std::ofstream outputFile(filePath);
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Unable to open file '" << filePath << "' for writing.\n";
        return;
    }

    // Save patients
    for (const auto &patient : patients)
    {
        outputFile << "Patient: " << patient.getPatientID() << " " << patient.getName() << " " << patient.getDateOfBirth() << " " << patient.getGender() << " " << patient.getAdmissionTime() << " " << patient.getInsuranceOption() << "\n";
    }

    // Save doctors
    for (const auto &doctor : doctors)
    {
        outputFile << "Doctor: " << doctor.getName() << " " << doctor.getSpecialization();
        for (const auto &insurance : doctor.getAcceptedInsurances())
        {
            outputFile << " " << insurance;
        }
        outputFile << "\n";
    }

    // Save nurses
    for (const auto &nurse : nurses)
    {
        outputFile << "Nurse: " << nurse.getName() << "\n";
    }

    // Save appointments
    for (const auto &appointment : appointments)
    {
        const Patient &patient = appointment.getPatient();
        const Doctor &doctor = appointment.getDoctor();
        const Nurse &nurse = appointment.getNurse();
        const std::string &dateTime = appointment.getDateTime();

        outputFile << "Appointment: " << patient.getPatientID() << " " << doctor.getName() << " " << nurse.getName() << " " << dateTime << "\n";
    }

    std::cout << "State saved successfully!\n";
}

// Load the state of the hospital from a file
void HospitalManagementSystem::loadState(const std::string &filePath)
{
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Unable to open file '" << filePath << "' for reading.\n";
        return;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        // Load patients
        if (line.substr(0, 8) == "Patient:")
        {
            std::istringstream iss(line.substr(8));
            std::string name, dateOfBirth, gender, admissionTime;
            int insuranceOption, patientID;
            if (!(iss >> patientID >> name >> dateOfBirth >> gender >> admissionTime >> insuranceOption))
            {
                std::cerr << "Error: Invalid format in the input file.\n";
                return;
            }

            // Load patient with the additional information
            patients.emplace_back(name, dateOfBirth, gender, admissionTime, insuranceOption);
        }
            // Load doctors
        else if (line.substr(0, 7) == "Doctor:")
        {
            std::istringstream iss(line.substr(7));
            std::string name, specialization;
            if (!(iss >> name >> specialization))
            {
                std::cerr << "Error: Invalid format in the input file.\n";
                return;
            }
            std::vector<std::string> acceptedInsurances;
            std::copy(std::istream_iterator<std::string>(iss),
                      std::istream_iterator<std::string>(),
                      std::back_inserter(acceptedInsurances));
            doctors.emplace_back(name, specialization, acceptedInsurances);
        }
            // Load nurses
        else if (line.substr(0, 6) == "Nurse:")
        {
            std::istringstream iss(line.substr(6));
            std::string name;
            if (!(iss >> name))
            {
                std::cerr << "Error: Invalid format in the input file.\n";
                return;
            }
            nurses.emplace_back(name);
        }
            // Load appointments
        else if (line.substr(0, 12) == "Appointment:")
        {
            std::istringstream iss(line.substr(12));
            std::string patientID, doctorID, nurseID, dateTime;
            if (!(iss >> patientID >> doctorID >> nurseID >> dateTime))
            {
                std::cerr << "Error: Invalid format in the input file.\n";
                return;
            }

            try
            {
                Patient &patient = findPatientByID(patientID);
                Doctor &doctor = findDoctorByID(doctorID);
                Nurse &nurse = findNurseByID(nurseID);

                appointments.emplace_back(patient, doctor, nurse, dateTime);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << "\n";
            }
        }
    }

    std::cout << "State loaded successfully!\n";
}

// Register a new patient
void HospitalManagementSystem::registerNewPatient(const std::string &name, const std::string &dateOfBirth, const std::string &gender, const std::string &admissionTime, int insuranceOption)
{
    if (name.empty() || dateOfBirth.empty() || gender.empty() || admissionTime.empty())
    {
        std::cerr << "Error: Name, date of birth, gender, and admission time cannot be empty.\n";
        return;
    }

    patients.emplace_back(name, dateOfBirth, gender, admissionTime, insuranceOption);
    std::cout << "Patient registered successfully! Patient ID: " << patients.back().getPatientID() << "\n";
}

// Add a new doctor
void HospitalManagementSystem::addDoctor(const std::string &name, const std::string &specialization, const std::vector<std::string> &acceptedInsurances)
{
    if (name.empty() || specialization.empty())
    {
        std::cerr << "Error: Name and specialization cannot be empty.\n";
        return;
    }

    doctors.emplace_back(name, specialization, acceptedInsurances);
    std::cout << "Doctor added successfully!\n";
}

// Display details of a specific doctor
void HospitalManagementSystem::displayDoctorDetails(const std::string &doctorID)
{
    auto doctorIterator = std::find_if(doctors.begin(), doctors.end(), [&doctorID](const Doctor &doctor)
    {
        // Assuming doctorID is the name for simplicity
        return doctor.getName() == doctorID; });

    if (doctorIterator != doctors.end())
    {
        const Doctor &doctor = *doctorIterator;
        std::cout << "Doctor Details:\n";
        std::cout << "Name: " << doctor.getName() << "\n";
        std::cout << "Specialization: " << doctor.getSpecialization() << "\n";
        std::cout << "Accepted Insurances: ";
        for (const auto &insurance : doctor.getAcceptedInsurances())
        {
            std::cout << insurance << " ";
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "Error: Doctor not found.\n";
    }
}

// Set a follow-up date for a patient
void HospitalManagementSystem::setFollowUpDate(const std::string &patientID, const std::string &followUpDate)
{
    // Implementation for setting a follow-up date
    // ...
}

// Helper function to find a patient by ID
Patient &HospitalManagementSystem::findPatientByID(const std::string &patientID)
{
    auto patientIterator = std::find_if(patients.begin(), patients.end(), [&patientID](const Patient &patient)
    {
        // Convert patient.getPatientID() to string for comparison
        return std::to_string(patient.getPatientID()) == patientID; });

    if (patientIterator != patients.end())
    {
        return *patientIterator;
    }
    else
    {
        // Handle the case where the patient is not found
        throw std::runtime_error("Patient not found.");
    }
}

// Helper function to find a doctor by ID
Doctor &HospitalManagementSystem::findDoctorByID(const std::string &doctorID)
{
    auto doctorIterator = std::find_if(doctors.begin(), doctors.end(), [&doctorID](const Doctor &doctor)
    {
        // Assuming doctorID is the name for simplicity
        return doctor.getName() == doctorID; });

    if (doctorIterator != doctors.end())
    {
        return *doctorIterator;
    }
    else
    {
        // Handle the case where the doctor is not found
        throw std::runtime_error("Doctor not found.");
    }
}

// Display details of all patients
void HospitalManagementSystem::displayAllPatients()
{
    std::cout << "All Patients:\n";
    for (const auto &patient : patients)
    {
        std::cout << "Patient ID: " << patient.getPatientID() << "\n";
        std::cout << "Patient Name: " << patient.getName() << "\n";
        std::cout << "Gender: " << patient.getGender() << "\n";
        std::cout << "Admission Time: " << patient.getAdmissionTime() << "\n";
        std::cout << "Insurance Option: " << patient.getInsuranceOption() << "\n";
        std::cout << "\n";
    }
}

// Display details of all doctors
void HospitalManagementSystem::displayAllDoctors()
{
    std::cout << "All Doctors:\n";
    for (const auto &doctor : doctors)
    {
        std::cout << "Doctor ID: " << doctor.getName() << "\n";
        std::cout << "Name: " << doctor.getName() << "\n";
        std::cout << "Specialization: " << doctor.getSpecialization() << "\n";
        std::cout << "Accepted Insurances: ";
        for (const auto &insurance : doctor.getAcceptedInsurances())
        {
            std::cout << insurance << " ";
        }
        std::cout << "\n\n";
    }
}

// Add a new nurse
void HospitalManagementSystem::addNurse(const std::string &name)
{
    if (name.empty())
    {
        std::cerr << "Error: Name cannot be empty for adding a nurse.\n";
        return;
    }

    nurses.emplace_back(name);
    std::cout << "Nurse added successfully!\n";
}

// Display details of all nurses
void HospitalManagementSystem::displayAllNurses()
{
    std::cout << "List of All Nurses:\n";
    for (const auto &nurse : nurses)
    {
        std::cout << "Name: " << nurse.getName() << "\n";
    }
}

// Helper function to find a nurse by ID
Nurse &HospitalManagementSystem::findNurseByID(const std::string &nurseID)
{
    auto it = std::find_if(nurses.begin(), nurses.end(),
                           [nurseID](const Nurse &nurse)
                           { return nurse.getName() == nurseID; });

    if (it != nurses.end())
    {
        return *it;
    }
    else
    {
        throw std::runtime_error("Nurse not found.");
    }
}

// Schedule an appointment with a specific nurse
void HospitalManagementSystem::scheduleAppointment(const std::string &patientID, const std::string &doctorID, const std::string &nurseID, const std::string &dateTime)
{
    try
    {
        Patient &patient = findPatientByID(patientID);
        Doctor &doctor = findDoctorByID(doctorID);
        Nurse &nurse = findNurseByID(nurseID);

        appointments.emplace_back(patient, doctor, nurse, dateTime);
        std::cout << "Appointment scheduled successfully!\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

// Display details of all appointments
void HospitalManagementSystem::displayAllAppointments()
{
    std::cout << "List of All Appointments:\n";
    for (const auto &appointment : appointments)
    {
        const Patient &patient = appointment.getPatient();
        const Doctor &doctor = appointment.getDoctor();
        const Nurse &nurse = appointment.getNurse();
        const std::string &dateTime = appointment.getDateTime();

        std::cout << "Patient: " << patient.getAdmissionTime() << ", Doctor: " << doctor.getName() << ", Nurse: " << nurse.getName() << ", Date/Time: " << dateTime << "\n";
    }
}

// Add medication to a patient
void HospitalManagementSystem::addPatientMedication(const std::string &patientID, const std::string &medication)
{
    try
    {
        Patient &patient = findPatientByID(patientID);
        patient.addMedication(medication);
        std::cout << "Medication added successfully!\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

// Add illness to a patient
void HospitalManagementSystem::addPatientIllness(const std::string &patientID, const std::string &illness)
{
    try
    {
        Patient &patient = findPatientByID(patientID);
        patient.addIllness(illness);
        std::cout << "Illness added successfully!\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

// Display details of a specific patient
void HospitalManagementSystem::displayPatientDetails(const std::string &patientID)
{
    try
    {
        Patient &patient = findPatientByID(patientID);

        std::cout << "Patient Details:\n";
        std::cout << "Patient ID: " << patient.getPatientID() << "\n";
        std::cout << "Name: " << patient.getName() << "\n";
        std::cout << "Gender: " << patient.getGender() << "\n";
        std::cout << "Admission Time: " << patient.getAdmissionTime() << "\n";
        std::cout << "Insurance Option: " << patient.getInsuranceOption() << "\n";
        std::cout << "Medications:\n";
        for (const auto &medication : patient.getMedications())
        {
            std::cout << "- " << medication << "\n";
        }
        std::cout << "Illnesses:\n";
        for (const auto &illness : patient.getIllnesses())
        {
            std::cout << "- " << illness << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
