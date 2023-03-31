/***********************************************************************
// OOP244 Workshop w9 p1:  Person header file
//
// File Person.h
// Version 1.0
// Date  03/28/2023
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
#ifndef SDDS_PERSON_H
#define SDDS_PERSON_H
#include <iostream>
#include <fstream>
#include "Tools.h"

namespace sdds {
	class Person
	{
		char* m_firstName{};
		char* m_lastName{};
		char* m_midName{};
	public:
		Person();
		virtual ~Person();
		bool isValid()const;
		// rule of three;
		Person(const Person& P);
		virtual Person& operator=(const Person& P);
		virtual std::istream& read(std::istream& istr);
		virtual std::ifstream& load(std::ifstream& ifst);
		virtual std::ostream& display(std::ostream& ostr)const;
	};
	std::istream& operator>>(std::istream& istr, Person& P);
	std::ifstream& operator>>(std::ifstream& ifst, Person& P);

	std::ostream& operator<<(std::ostream& ostr, const Person& P);
}
#endif // !SDDS_PERSON_H



