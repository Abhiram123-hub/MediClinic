

#ifndef HOSPITALMANAGEMENTSYSTEM_PATIENT_H
#define HOSPITALMANAGEMENTSYSTEM_PATIENT_H

#include <string>
#include <vector>

class Patient
{
public:
    // Constructor
    Patient(const std::string &name, const std::string &dateOfBirth, const std::string &gender, const std::string &admissionTime, int insuranceOption);

    // Getters
    const std::string &getName() const;
    const std::string &getDateOfBirth() const;
    const std::string &getGender() const;
    const std::string &getAdmissionTime() const;
    int getInsuranceOption() const;
    int getPatientID() const;
    const std::vector<std::string> &getMedications() const;
    const std::vector<std::string> &getIllnesses() const;

    // Setters
    void addMedication(const std::string &medication);
    void addIllness(const std::string &illness);

private:
    // Patient details
    static int nextPatientID; // Static variable to generate unique patient IDs
    int patientID;            // Unique ID for each patient
    std::string name;
    std::string dateOfBirth;
    std::string gender;        // Gender of the patient
    std::string admissionTime; // Admission time of the patient
    int insuranceOption;
    std::vector<std::string> medications; // List of medications for the patient
    std::vector<std::string> illnesses;   // List of illnesses for the patient
};

#endif //HOSPITALMANAGEMENTSYSTEM_PATIENT_H
