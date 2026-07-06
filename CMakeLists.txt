cmake_minimum_required(VERSION 3.26)
project(HospitalManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(HospitalManagementSystem main.cpp
        Patient.cpp
        Patient.h
        Doctor.cpp
        Doctor.h
        Appointment.cpp
        Appointment.h
        Nurse.cpp
        Nurse.h
        HospitalManagementSystem.cpp
        HospitalManagementSystem.h)
