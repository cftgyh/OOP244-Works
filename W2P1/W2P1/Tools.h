/*
OOP244 Workshop 2 p1: Tools header file

Name: Xinyu Zhang
Email: xzhang399@myseneca.ca
Student ID: 174538215
Date: 2023-01-25
I have done all the coding by myself and
only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds {
	int openFile_r(const char filename[]); // Provided
	void closefile(); // Provided
	int noOfTraces(); // Provided

	// ADD: Declare read prototypes (4 prototypes)

	int read(char& dayOfWeek);
    int read(int& value);
    int read(double& timeInHours);
    int read(char* pName);

	void strCpy(char* des, const char* src); // Provided
	int strLen(const char* s); // Provided
}
#endif 
