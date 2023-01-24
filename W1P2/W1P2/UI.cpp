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
		int i, position = 1;
		cout << "Enter GPA query..." << endl;
		do
		{
			cout << "? ";
			cin >> symbol >> gpa;
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
			else if (symbol == '!')
			{
				cout << "Exit the program? (Y)es/(N)o: ";
				cin >> selection;
				cout << endl;
			}
			else
			{
				cout << "Syntax error: ? [Op][value]<ENTER>" << endl
					<< "Op: [>,<,~,!]" << endl
					<< "value: GPA value" << endl << endl;
			}
		} while (symbol != '!' && selection != 'y');
	}

	void displayOneInfo(int i, int position, struct GPA g[])
	{
		cout << "[" << position << "]" << g[i].stno << ": "
			<< g[i].gpa << " (" << g[i].name << ")" << endl;
	}
}
