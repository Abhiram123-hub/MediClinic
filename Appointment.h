
#ifndef HOSPITALMANAGEMENTSYSTEM_APPOINTMENT_H
#define HOSPITALMANAGEMENTSYSTEM_APPOINTMENT_H

// Appointment.h
#pragma once

// Include necessary header files
#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include <string>

// Declaration of the Appointment class
class Appointment
{
public:
    // Constructors
    Appointment() = default; // Default constructor (if needed)
    Appointment(const Patient &patient, const Doctor &doctor, const Nurse &nurse, const std::string &dateTime);
    // Constructor with parameters to initialize Appointment details.

    // Getters for retrieving information about the appointment
    const Patient &getPatient() const;      // Getter for retrieving the associated Patient object
    const Doctor &getDoctor() const;        // Getter for retrieving the associated Doctor object
    const Nurse &getNurse() const;          // Getter for retrieving the associated Nurse object
    const std::string &getDateTime() const; // Getter for retrieving the date and time of the appointment

private:
    // Appointment details stored as private members
    Patient patient;      // Associated Patient object
    Doctor doctor;        // Associated Doctor object
    Nurse nurse;          // Associated Nurse object
    std::string dateTime; // Date and time of the appointment
};

#endif //HOSPITALMANAGEMENTSYSTEM_APPOINTMENT_H
