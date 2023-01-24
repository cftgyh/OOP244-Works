/***********************************************************************
// Workshop 1 p2: tester program
//
// File  main.cpp
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*
? <3.6 [ENTER]  list all the GPA records less than 3.6
? >3.9 [ENTER]  list all the GPA records more than 3.9
? ~3.0 [ENTER]  list all values close to 3.0 with 0.05 precision (between 2.95 and 3.05)
? !  End query
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
		bool result = loadStudentData("students.csv", studentInfo);
		// function: sort gpa structs
		sortStudentData(studentInfo);
		// input gpa and output
		displayStudentInfo(studentInfo);

		return result;// return true or false;
	}
}
