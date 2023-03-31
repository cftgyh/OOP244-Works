/***********************************************************************
// OOP244 Workshop w9 p1:  Person cpp file
//
// File Person.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Person.h"

using namespace std;

namespace sdds {
	Person::Person()
	{
		m_firstName = nullptr;
		m_lastName = nullptr;
		m_midName = nullptr;
	}
	Person::~Person()
	{
		if (m_firstName) {
			delete[] m_firstName;
		}
		if (m_midName) {
			delete[] m_midName;
		}
		if (m_midName) {
			delete[] m_midName;
		}
		m_firstName = nullptr;
		m_lastName = nullptr;
		m_midName = nullptr;
	}
	bool Person::isValid() const
	{
		return (m_firstName && m_lastName);
	}
	Person::Person(const Person& P)
	{
		m_firstName = nullptr;
		m_lastName = nullptr;
		m_midName = nullptr;
		operator=(P);
	}
	Person& Person::operator=(const Person& P)
	{
		if (this != &P) {
			if(m_firstName) delete[] m_firstName;
			if(m_lastName) delete[] m_lastName;
			if(m_midName) delete[] m_midName;
			if (P.m_firstName != nullptr) m_firstName = U.aloCopy(strlen(P.m_firstName), P.m_firstName);
			else m_firstName = nullptr;
			if (P.m_midName != nullptr) m_midName = U.aloCopy(strlen(P.m_midName), P.m_midName);
			else m_midName = nullptr;
			if (P.m_lastName != nullptr) m_lastName = U.aloCopy(strlen(P.m_lastName), P.m_lastName);
			else m_lastName = nullptr;
		}

		return *this;
	}
	std::istream& Person::read(std::istream& istr)
	{
		char c{};
		char temp[100]{};
		char firstName[100]{};
		char lastName[100]{};

		m_firstName = nullptr;
		m_lastName = nullptr;
		m_midName = nullptr;

		istr.getline(firstName, 100, ','); // Homer
		m_firstName = U.aloCopy(strlen(firstName), firstName);

		c = istr.get();		// ','				// 'J'
		temp[0] = c;		// temp[0] = ','	// 'J'
		temp[1] = '\0';		// temp: string ","	// "J"

		if (c != ',') {
			char midName[100]{};
			istr.getline(midName, 100, ',');	// 'ay'
			strcat(temp, midName);		// temp: Jay
			m_midName = U.aloCopy(strlen(temp), temp); // m_midName: Jay
		}
		istr.getline(lastName, 100);
		m_lastName = U.aloCopy(strlen(lastName), lastName);

		return istr;
	}
	std::ifstream& Person::load(std::ifstream& ifst)
	{
		char c{};
		char temp[100]{};
		char firstName[100]{};
		char lastName[100]{};

		m_firstName = nullptr;
		m_lastName = nullptr;
		m_midName = nullptr;

		ifst.getline(firstName, 100, ','); // Homer
		m_firstName = U.aloCopy(strlen(firstName), firstName);

		c = ifst.get();		// ','				// 'J'
		temp[0] = c;		// temp[0] = ','	// 'J'
		temp[1] = '\0';		// temp: string ","	// "J"

		if (c != ',') {
			char midName[100]{};
			ifst.getline(midName, 100, ',');	// 'ay'
			strcat(temp, midName);		// temp: Jay
			m_midName = U.aloCopy(strlen(temp), temp); // m_midName: Jay
		}
		ifst.getline(lastName, 100);
		m_lastName = U.aloCopy(strlen(lastName), lastName);

		return ifst;
	}
	std::ostream& Person::display(std::ostream& ostr) const
	{
		if (isValid()) {
			ostr << m_firstName;
			ostr << " ";
			if (m_midName) {
				ostr << m_midName;
				ostr << " ";
			}
			ostr << m_lastName;
		}
		return ostr;
	}
	// helper function
	std::istream& operator>>(std::istream& istr, Person& P)
	{
		return P.read(istr);
	}
	std::ifstream& operator>>(std::ifstream& ifst, Person& P)
	{
		return P.load(ifst);
	}
	std::ostream& operator<<(std::ostream& ostr, const Person& P)
	{
		return P.display(ostr);
	}
}
