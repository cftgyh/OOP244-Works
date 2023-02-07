/***********************************************************************
// OOP244 Workshop 3 # p1: tester program
//
// File	main.cpp
// Version 1.0
// Date		October 7, 2022
// Author	Mohammad Shamas
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Department.h"
using namespace std;
using namespace sdds;

int main() {

	Project testProject = { "Base",551.55 };

	Project myprojects[5] = { {"Synergy", 5041.55},
							  {"Mecha", 2925.99},
							  {"Chroma", 3995.45},
							  {"Force", 6988.45},
							  {"Oculus", 7441.22}
	};

	Department SDDS{};

	//Test1
	cout << "**********Create Department TEST START**********" << endl;
	SDDS.createDepartment("School of Software development", testProject, 1);
	display(SDDS);
	cout << "**********Create Department TEST END**********" << endl;

	//Test2
	cout << endl << "**********Update Name TEST Start**********" << endl;
	SDDS.updateName("School of Software development and design");
	display(SDDS);
	cout << "**********Update Name TEST END**********" << endl;

	//Test3
	cout << endl << "**********Update Budget TEST Start**********" << endl;
	SDDS.updateBudget(5555.99);
	display(SDDS);
	cout << "**********Update Budget TEST END**********" << endl;

	//Test4
	cout << endl << "**********Expenses and Remaining Budget TEST Start**********" << endl;
	cout << "Our current total Expenses are: " << SDDS.totalexpenses() << endl;
	cout << "Our remaining budget is: " << SDDS.remainingBudget() << endl;
	cout << "**********Expenses and Remaining Budget TEST END**********" << endl;

	//Test5
	cout << endl << "**********Add Project TEST START**********" << endl;
	for (int i = 0; i < 5 && SDDS.addProject(myprojects[i]); i++);
	display(SDDS);
	cout << "**********Add Project TEST END**********" << endl;

	SDDS.clearDepartment();
	return 0;
}