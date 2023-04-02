/***********************************************************************
// OOP244 Workshop w9 p1:  Contact header file
//
// File Contact.h
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
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include "Person.h"

namespace sdds {
	class Contact: public Person
	{
		char* m_address{};
		char* m_city{};
		char m_province[3]{};	// 2 chars
		char m_postCode[7]{};	// 6 chars
	public:
		Contact();
		// rule of three
		Contact(const Contact& copyFrom);
		Contact& operator=(const Contact& RightOperand);
		~Contact();
		operator bool()const;
		void operator~();

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
	};
}
#endif // !SDDS_CONTACT_H

