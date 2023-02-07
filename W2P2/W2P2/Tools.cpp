/*
OOP244 Workshop 2 p2: Tools.cpp file

Name: Xinyu Zhang
Email: xzhang399@myseneca.ca
Student ID: 174538215
Date: 2023-01-28
I have done all the coding by myself and
only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Tools.h"

namespace sdds {
    void strCpy(char* str1, const char* str2) {
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
}