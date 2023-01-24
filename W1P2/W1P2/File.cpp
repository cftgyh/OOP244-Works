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
File: hold file-related functions
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"
#include "GPA.h"
#include "GPAList.h"

namespace sdds
{
	bool loadStudentData(const char* studentFile, struct GPA stdInfo[])
	{
		bool open = false;
		char ch;
		int i = 0;

		// read the data file
		FILE* fp = fopen(studentFile, "r");
		if (fp != NULL)
		{
			// store the GPA information
			while (i < 100 && fscanf(fp, "%[^,],%d,%lf%c", stdInfo[i].name, &stdInfo[i].stno, &stdInfo[i].gpa, &ch) == 4)
			{
				i++;
			}
			fclose(fp);
			fp = NULL;
			open = true;
		}
		return open;						// return the bool of whether open
	}

	void sortStudentData(struct GPA stdInfo[])
	{
		int i, j, n;
		struct GPA sInfo = { {0} };			// Appointment app use to as an exchange medium

		// count how many valid members are there in the appointments array.
		for (i = n = 0; i < 100 && stdInfo[i].stno != 0; i++)
		{
			n++;
		}
		// compare every members to other members 
		for (i = 0; i < n - 1; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (stdInfo[i].stno > stdInfo[j].stno)
				{
					// exchange appointments[i] and appointments[j]
					sInfo = stdInfo[i];
					stdInfo[i] = stdInfo[j];
					stdInfo[j] = sInfo;
				}
			}
				
		}
	}
}
	

	