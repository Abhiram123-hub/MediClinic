
// Nurse.cpp
#include "Nurse.h"

// Constructor for initializing Nurse details
Nurse::Nurse(const std::string &name) : name(name) {}

// Getter for retrieving the name of the Nurse
const std::string &Nurse::getName() const
{
    return name;
}
