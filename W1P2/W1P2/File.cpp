/***********************************************************************
// Workshop 1 p2: File.cpp file
//
// File  File.cpp
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
holding file related functions.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"
#include "GPA.h"

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
		struct GPA sInfo = { {0} };			// GPA sInfo use to as an exchange medium

		// count how many valid members are there in the stdInfo array.
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
					// exchange stdInfo[i] and stdInfo[j]
					sInfo = stdInfo[i];
					stdInfo[i] = stdInfo[j];
					stdInfo[j] = sInfo;
				}
			}
				
		}
	}
}
	

	