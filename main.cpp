// main.cpp
#include "HospitalManagementSystem.h"
#include <iostream>
#include <string>
#include <limits>
#include <regex>

using namespace std;

// Function to get a valid date-time input from the user
string getDateTimeInput()
{
    string dateTime;

    // Regular expression for validating the date-time format (HH:MM[am/pm])
    regex dateTimePattern(R"((1[0-2]|0?[1-9]):[0-5][0-9]([ap]m)?)");

    while (true)
    {
        cout << "Enter Time (eg:3:15pm): ";
        cin >> dateTime;

        if (regex_match(dateTime, dateTimePattern))
        {
            // Valid input
            break;
        }
        else
        {
            cout << "Invalid date-time format. Please enter a valid time (HH:MM[am/pm]).\n";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    return dateTime;
}

// Function to print the main menu options
void printMainMenu()
{
    cout << "Hospital Management System Menu:\n";
    cout << "1. Register New Patient\n";
    cout << "2. Add Medication to Patient\n";
    cout << "3. Add Illness to Patient\n";
    cout << "4. Display All Patients\n";
    cout << "5. Display Patient Details\n";
    cout << "6. Add New Doctor\n";
    cout << "7. Display All Doctors\n";
    cout << "8. Display Doctor Details\n";
    cout << "9. Save State\n";
    cout << "10. Load State\n";
    cout << "11. Add New Nurse\n";
    cout << "12. Display All Nurses\n";
    cout << "13. Schedule Appointment\n";
    cout << "14. Display All Appointments\n";

    cout << "0. Exit\n";
}

int getIntegerInput()
{
    int input;
    while (true)
    {
        if (cin >> input)
        {
            // Valid input
            break;
        }
        else
        {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid number.\n";
        }
    }
    return input;
}

string getStringInput()
{
    string input;
    cin >> input;
    return input;
}

int main()
{
    // Create an instance of the HospitalManagementSystem
    HospitalManagementSystem hospitalSystem;

    // Main loop for the interactive menu
    while (true)
    {
        // Display the main menu
        printMainMenu();
        cout << "Choose an option: ";

        int choice = getIntegerInput();

        switch (choice)
        {
            case 1:
            {
                string name, dateOfBirth, gender, admissionTime;
                int insuranceOption;

                cout << "Enter patient's name: ";
                name = getStringInput();
                cout << "Enter patient's date of birth (YYYY-MM-DD): ";
                dateOfBirth = getStringInput();
                cout << "Enter patient's gender(M/F): ";
                gender = getStringInput();
                cout << "Enter admission time (Enter Time (e.g., 3:15pm)): ";
                admissionTime = getStringInput();

                // Input validation for insuranceOption
                while (true)
                {
                    cout << "Enter insurance option (1 for InsuranceA / 2 for InsuranceB): ";
                    insuranceOption = getIntegerInput();

                    if (insuranceOption == 1 || insuranceOption == 2)
                    {
                        break; // Valid input, exit the loop
                    }
                    else
                    {
                        cout << "Invalid input. Please enter 1 for InsuranceA or 2 for InsuranceB.\n";
                    }
                }

                hospitalSystem.registerNewPatient(name, dateOfBirth, gender, admissionTime, insuranceOption);
                break;
            }
            case 2:
            {
                // Add medication to a patient
                string patientID, medication;

                // Input validation for patientID
                cout << "Enter Patient ID : ";
                while (!(std::cin >> patientID))
                {
                    cin.clear(); // Clear the error flag
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input for Patient ID. Please enter a valid string.\n";
                    cout << "Enter Patient ID : ";
                }

                // Input validation for medication
                cout << "Enter Medication: ";
                while (!(std::cin >> medication))
                {
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input for Medication. Please enter a valid string.\n";
                    cout << "Enter Medication: ";
                }

                hospitalSystem.addPatientMedication(patientID, medication);
                break;
            }
            case 3:
            {
                // Add illness to a patient
                string patientID, illness;
                cout << "Enter Patient ID : ";
                patientID = getStringInput();

                // Input validation for illness
                while (true)
                {
                    cout << "Enter Illness: ";
                    cin >> illness;

                    if (!illness.empty()) // Check if the input is not empty
                        break;
                    else
                        cout << "Invalid input. Please enter a non-empty illness.\n";
                }

                hospitalSystem.addPatientIllness(patientID, illness);
                break;
            }

            case 4:
            {
                // Display details of all patients
                hospitalSystem.displayAllPatients();
                break;

            }

            case 5:
            {
                // Display details of a specific patient
                string patientID;
                cout << "Enter Patient ID : ";

                // Input validation for patientID
                while (true)
                {
                    cin >> patientID;

                    if (cin.fail())
                    {
                        cin.clear(); // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                        cout << "Invalid input. Please enter a valid Patient ID.\n";
                    }
                    else
                    {
                        break; // Valid input, exit the loop
                    }
                }

                hospitalSystem.displayPatientDetails(patientID);
                break;
            }
            case 6:
            {
                // Add a new doctor
                string name, specialization;

                // Input validation for doctor's name
                cout << "Enter doctor's name: ";
                name = getStringInput();

                // Input validation for specialization
                cout << "Enter specialization: ";
                specialization = getStringInput();

                hospitalSystem.addDoctor(name, specialization, {"InsuranceA", "InsuranceB"});
                break;
            }
            case 7:
                // Display details of all doctors
                hospitalSystem.displayAllDoctors();
                break;
            case 8:
            {
                // Display details of a specific doctor
                string doctorID;
                cout << "Enter Doctor's Name: ";
                cin >> doctorID;
                hospitalSystem.displayDoctorDetails(doctorID);
                break;
            }
            case 9:
            {
                // Save the state of the hospital to a file
                hospitalSystem.saveState("hospital_state.txt");
                break;

            }
            case 10:
            {
                // Load the state of the hospital from a file
                hospitalSystem.loadState("hospital_state.txt");
                break;
            }
            case 11:
            {
                // Add a new nurse
                string nurseName;
                cout << "Enter nurse's name: ";
                cin >> nurseName;
                hospitalSystem.addNurse(nurseName);
                break;
            }
            case 12:
                // Display details of all nurses
                hospitalSystem.displayAllNurses();
                break;

            case 13:
            {
                // Schedule an appointment
                string patientID, doctorID, nurseID, dateTime;

                cout << "Enter Patient ID : ";
                patientID = getStringInput();

                cout << "Enter Doctor's Name: ";
                doctorID = getStringInput();

                cout << "Enter Nurse's Name: ";
                nurseID = getStringInput();

                cout << "Enter Time (eg:3:15pm): ";
                dateTime = getDateTimeInput();

                hospitalSystem.scheduleAppointment(patientID, doctorID, nurseID, dateTime);
                break;
            }

            case 14:
            {
                // Display details of all appointments
                hospitalSystem.displayAllAppointments();
                break;
            }

            case 0:
                // Exit the program
                cout << "Exiting the program. Goodbye!\n";
                return 0;

            default:
                // Handle invalid choice
                cout << "Invalid choice. Please try again.\n";
        }

        cout << "\n"; // Add a newline for better readability
    }

}


