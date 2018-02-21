cmake_minimum_required(VERSION 3.8)
project(TP-C++)

set(CMAKE_CXX_STANDARD 11)

add_executable(Ex1 Ex1.cpp)
add_executable(Ex2 Ex2.cpp)
add_executable(Ex3 Ex3.cpp)
add_executable(Ex4 ex4/Main.cpp ex4/Patient.cpp ex4/Patient.h ex4/PatientFoncteur.cpp ex4/PatientFoncteur.h ex4/SortPat.cpp ex4/SortPat.h ex4/ScoreSort.cpp ex4/ScoreSort.h)
add_executable(Ex5
        ex5/Main.cpp
        ex5/Ressource.h ex5/Ressource.cpp
        ex5/Task.cpp ex5/Task.h
        ex5/Slot.cpp ex5/Slot.h
        ex5/Center.cpp ex5/Center.h
        ex5/FoncteurScheduleRessource.cpp ex5/FoncteurScheduleRessource.h
        ex5/FoncteurFindSlot.cpp ex5/FoncteurFindSlot.h
        ex5/FoncteurAssignSlot.cpp ex5/FoncteurAssignSlot.h
        )