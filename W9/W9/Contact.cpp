/***********************************************************************
// OOP244 Workshop w9 p1:  Contact cpp file
//
// File Contact.cpp
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
#include "Tools.h"
#include "Contact.h"
using namespace std;

namespace sdds {
	Contact::~Contact() // destructor doesn't need to deallo parents' memory
	{
		~*this;
	}
	Contact::operator bool() const
	{
		return m_address && m_address[0] && m_city && m_city[0];
	}
	void Contact::operator~()
	{
		Person::operator~();	// parent destructor will be called auto when the program end, and it will call parent~ to deallocate parent memory
								// but when the program run, only child~ will be called
								// so when object push and pull data in running, we need to handly call parent~ to deallocate parent memory
		delete[] m_address;
		delete[] m_city;
		m_address = m_city = nullptr;
	}
	Contact::Contact() :Person() {}
	// rule of three
	Contact::Contact(const Contact& copyFrom): Person(copyFrom) // can I write ": Person(copyFrom)" or not? Can!
	{
		operator=(copyFrom);
	}
	Contact& Contact::operator=(const Contact& RightOperand)
	{
		Person::operator=(RightOperand);
		if (this != &RightOperand) {
			strCpy(m_province, RightOperand.m_province);
			strCpy(m_postCode, RightOperand.m_postCode);
			delAlloCopy(m_address, RightOperand.m_address);
			delAlloCopy(m_city, RightOperand.m_city);
		}
		return *this;
	}
	std::istream& Contact::read(std::istream& istr)
	{
		~*this;
		Person::read(istr);

		char postCode[7]{};
		m_address = dynRead(istr, ',');
		m_city = dynRead(istr, ',');
		istr.getline(m_province, 3, ','); // bad province "70 the pond road,North York,ONT,M3J3M6
		istr.getline(postCode, 7, '\n');  // bad postcode "70 the pond road,North York,ON,M3J 3M6"
										  // getLine eat '\n', otherwise will print a new line

		if (istr.fail() || strLen(postCode) != 6) {
			~*this;
		}
		else strCpy(m_postCode, postCode);

		return istr;
	}
	std::ostream& Contact::write(std::ostream& ostr) const
	{
		if (*this) {
			Person::write(ostr);
			ostr << endl;
			ostr << m_address << endl;
			ostr << m_city << " " << m_province << endl;
			for (int i = 0; i < 3; i++) {
				ostr << m_postCode[i];
			}
			ostr << " ";
			for (int i = 3; i < 6; i++) {
				ostr << m_postCode[i];
			}
			ostr << endl;
		}
		return ostr;
	}
}