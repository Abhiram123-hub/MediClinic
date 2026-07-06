// Patient.cpp
#include "Patient.h"

int Patient::nextPatientID = 56272; // Initialize the static variable with the starting ID

// Constructor
Patient::Patient(const std::string &name, const std::string &dateOfBirth, const std::string &gender, const std::string &admissionTime, int insuranceOption)
        : patientID(nextPatientID++), name(name), dateOfBirth(dateOfBirth), gender(gender), admissionTime(admissionTime), insuranceOption(insuranceOption) {}

// Getters
int Patient::getPatientID() const
{
    return patientID; // Return the patient ID
}

const std::string &Patient::getName() const
{
    return name; // Return the name of the patient
}

const std::string &Patient::getDateOfBirth() const
{
    return dateOfBirth; // Return the date of birth of the patient
}

const std::string &Patient::getGender() const
{
    return gender; // Return the gender of the patient
}

const std::string &Patient::getAdmissionTime() const
{
    return admissionTime; // Return the admission time of the patient
}

int Patient::getInsuranceOption() const
{
    return insuranceOption; // Return the insurance option of the patient
}

const std::vector<std::string> &Patient::getMedications() const
{
    return medications; // Return the medications of the patient
}

const std::vector<std::string> &Patient::getIllnesses() const
{
    return illnesses; // Return the illnesses of the patient
}

// Setters
void Patient::addMedication(const std::string &medication)
{
    medications.push_back(medication); // Add a new medication to the patient's list
}

void Patient::addIllness(const std::string &illness)
{
    illnesses.push_back(illness); // Add a new illness to the patient's list
}
