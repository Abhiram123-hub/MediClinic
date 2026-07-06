//
// Created by jaich on 12/13/2023.
//

#ifndef HOSPITALMANAGEMENTSYSTEM_NURSE_H
#define HOSPITALMANAGEMENTSYSTEM_NURSE_H

#include <string>

class Nurse
{
public:
    // Constructors
    Nurse() = default;              // Default constructor
    Nurse(const std::string &name); // Parameterized constructor

    // Getters
    const std::string &getName() const; // Getter for retrieving the name of the Nurse

private:
    // Nurse details
    std::string name; // Stores the name of the Nurse
};



#endif //HOSPITALMANAGEMENTSYSTEM_NURSE_H
