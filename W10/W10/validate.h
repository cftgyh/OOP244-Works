/***********************************************************************
// OOP244 Workshop w10 p1:  validate header file
//
// File validate.h
// Version 1.0
// Date  04/04/2023
// Author Xinyu Zhang
// Section OOP244-ZAA
// Seneca ID   : 174538215
// Seneca email: xzhang399@myseneca.ca
//
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*
    minimum value: min
    array of test values: testValues
    number of element in array: no
    array of bool-> validaton result: results
*/
namespace sict {
    template<typename T>
    bool validate(const T& minValue, const T* testValues, const size_t no, bool* results) {
        bool isValid = true;

        for (size_t i = 0; i < no; i++) {
            results[i] = (testValues[i] >= minValue);
            isValid = isValid && results[i];
        }

        return isValid;
    }
}

