/***********************************************************************
// OOP244 Workshop w6 p1:  Numbers header file
//
// File Numbers.h
// Version 1.0
// Date  03/05/2023
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
#ifndef SDDS_NUMBERS_H
#define SDDS_NUMBERS_H
#include <iostream>

namespace sdds {
	class Numbers
	{
		double* m_collection; // array keep numbers
		char m_fileName[256];
		unsigned int m_collectionSize{}; // number of double numbers
		bool m_originalFlag{};	// keep track: original object or copy?
		bool m_addFlag{};			// keep track: added to collection or not?

		void sort(double* array, unsigned int size);
		unsigned int countLines() const;
		void setEmpty();
		bool load();
		void save();
		double max() const;
		double min() const;
		double average() const;

	public: 
		Numbers(const char* cString); // receive file name
		Numbers();
		~Numbers();
		Numbers(const Numbers& source);
		Numbers& operator=(const Numbers& source);
		operator bool() const;
		void sort();
		Numbers& operator+=(double value);
		std::ostream& display(std::ostream& ostr = std::cout) const;
	};
	// helper functions
	std::ostream& operator<<(std::ostream& ostr, const Numbers & right);
	std::istream& operator>>(std::istream& istr, Numbers& right);
}
#endif // !SDDS_NUMBERS_H



