// Appointment.cpp
#include "Appointment.h"

// Constructor for Appointment class
Appointment::Appointment(const Patient &patient, const Doctor &doctor, const Nurse &nurse, const std::string &dateTime)
        : patient(patient), doctor(doctor), nurse(nurse), dateTime(dateTime)
{
    // Initialize an Appointment object with the provided Patient, Doctor, Nurse, and DateTime information.
}

// Getter for retrieving the associated Patient object
const Patient &Appointment::getPatient() const
{
    return patient; // Return the Patient object associated with this Appointment.
}

// Getter for retrieving the associated Doctor object
const Doctor &Appointment::getDoctor() const
{
    return doctor; // Return the Doctor object associated with this Appointment.
}

// Getter for retrieving the associated Nurse object
const Nurse &Appointment::getNurse() const
{
    return nurse; // Return the Nurse object associated with this Appointment.
}

// Getter for retrieving the date and time of the appointment
const std::string &Appointment::getDateTime() const
{
    return dateTime; // Return the date and time of this Appointment.
}
