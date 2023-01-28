/***********************************************************************
// Workshop 1 p2: GPAlist.cpp file
//
// File  GPAlist.cpp
// Version 1.0
// Date  winter 2023
// Author:		Xinyu Zhang
// Student No#: 174538215
// Email:		xzhang399@myseneca.ca
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*
holding gpaQuery function.
*/
#include <iostream>
#include "GPAlist.h"
#include "GPA.h"
#include "File.h"
#include "UI.h"
using namespace std;

namespace sdds {

	GPA studentInfo[100] = { {0} };

	bool gpaQuery(const char* filename)
	{
		// function: get data from file.
		bool result = loadStudentData(filename, studentInfo);
		
		if (result == false)
		{
			return result;
		}
		// function: sort gpa structs
		sortStudentData(studentInfo);

		// user input and display output
		displayStudentInfo(studentInfo);

		return result;// return true;
	}
}
