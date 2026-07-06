
#ifndef HOSPITALMANAGEMENTSYSTEM_DOCTOR_H
#define HOSPITALMANAGEMENTSYSTEM_DOCTOR_H

#include <string>
#include <vector>
#include "Patient.h"

using namespace std;

/**
 * @brief The Doctor class represents a doctor in the hospital management system.
 */

class Doctor
{
public:
    // Constructor for initializing Doctor details
    Doctor(const std::string &name, const std::string &specialization, const std::vector<std::string> &acceptedInsurances);

    // Getter for retrieving the name of the Doctor
    const std::string &getName() const;

    // Getter for retrieving the specialization of the Doctor
    const std::string &getSpecialization() const;

    // Getter for retrieving the list of accepted insurances by the Doctor
    const std::vector<std::string> &getAcceptedInsurances() const;

private:
    // Doctor details
    std::string name;                            // Name of the doctor
    std::string specialization;                  // Specialization of the doctor
    std::vector<std::string> acceptedInsurances; // List of accepted insurances by the doctor
    std::vector<Patient> assignedPatients;       // List of patients assigned to the doctor
};

#endif //HOSPITALMANAGEMENTSYSTEM_DOCTOR_H
