// Doctor.cpp
#include "Doctor.h"

// Constructor for initializing Doctor details
Doctor::Doctor(const std::string &name, const std::string &specialization, const std::vector<std::string> &acceptedInsurances)
        : name(name), specialization(specialization), acceptedInsurances(acceptedInsurances) {}

// Getter for retrieving the name of the Doctor
const std::string &Doctor::getName() const
{
    return name;
}

// Getter for retrieving the specialization of the Doctor
const std::string &Doctor::getSpecialization() const
{
    return specialization;
}

// Getter for retrieving the list of accepted insurances by the Doctor
const std::vector<std::string> &Doctor::getAcceptedInsurances() const
{
    return acceptedInsurances;
}
