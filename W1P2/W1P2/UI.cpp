/***********************************************************************
// Workshop 1 p2: UI.cpp file
//
// File  UI.cpp
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
holding User interaction functions.
*/

#include <iostream>
#include "UI.h"
#include "GPA.h"

using namespace std;

namespace sdds
{
	void displayStudentInfo(struct GPA stdInfo[])
	{
		char symbol, selection = 'n';
		double gpa;
		int i, position;
		cout << "Enter GPA query..." << endl;
		do
		{
			cout << "? ";
			cin >> symbol;
			if (symbol != '!')
			{
				cin >> gpa;
				position = 1;
				if (symbol == '>')
				{
					for (i = 0; stdInfo[i].stno != 0; i++)
					{
						if (stdInfo[i].gpa > gpa)
						{
							displayOneInfo(i, position, stdInfo);
							position++;
						}
					}
				}
				else if (symbol == '<')
				{
					for (i = 0; stdInfo[i].stno != 0; i++)
					{
						if (stdInfo[i].gpa < gpa)
						{
							displayOneInfo(i, position, stdInfo);
							position++;
						}
					}
				}
				else if (symbol == '~')
				{
					for (i = 0; stdInfo[i].stno != 0; i++)
					{
						if (stdInfo[i].gpa > gpa - 0.05 && stdInfo[i].gpa < gpa + 0.05)
						{
							displayOneInfo(i, position, stdInfo);
							position++;
						}
					}
				}
				else
				{
					cout << "Syntax error: ? [Op][value]<ENTER>" << endl
						<< "Op: [>,<,~,!]" << endl
						<< "value: GPA value" << endl << endl;
				}
			}
			else
			{
				cout << "Exit the program? (Y)es/(N)o: ";
				cin >> selection;
			}	
		} while (symbol != '!' && selection != 'y');
	}

	void displayOneInfo(int i, int position, struct GPA g[])
	{
		//cout << "[" << position << "]" << g[i].stno << ": "
			//<< g[i].gpa << " (" << g[i].name << ")" << endl;
		printf("[%d] %d: %.1lf (%s)\n", position, g[i].stno, g[i].gpa, g[i].name);
	}
}
