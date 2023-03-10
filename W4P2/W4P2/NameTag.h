/***********************************************************************
// OOP244 Workshop w4 p2:  NameTag header file
//
// File NameTag.h
// Version 1.0
// Date  02/11/2023
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
//create / read information for a name tagand print it.

#ifndef SDDS_NAMETAG_H
#define SDDS_NAMETAG_H

namespace sdds {
	class NameTag
	{
		char *m_name;		// dynamically hold name, print >= 20 spaces, <= 40 chars
		int m_extensionNum; // 5 digit, if not provided, it's N/A
	
	public:
		NameTag(const char* name);
		NameTag(const char* name, unsigned int c);
		NameTag();
		~NameTag();
		void deallocate();
		void setEmpty();
		void set(const char* name, unsigned int eNumber);
		void print();
		NameTag& read();
	};
}

#endif // !SDDS_NAMETAG_H


