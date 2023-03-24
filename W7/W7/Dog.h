/***********************************************************************
// OOP244 Workshop w6 p1:   Dog header file
//
// File Dog.h
// Version 1.0
// Date  03/14/2023
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
#ifndef SDDS_DOG_H
#define SDDS_DOG_H
#include <ostream>
#include "Pet.h"

namespace sdds {
	class Dog: public Pet
	{
		const double cBaseFee = 1.00;
		const double cDogFee = 4.00;
		const double fDogFee = 0.25;
		const double rDogFee = 1.00;
		int m_noOfWalk{};
		
	public:
		Dog(const char* name, int initAge = 0);
		void feed();
		void reSpawn();
		void walk();
		Dog& operator++(int);
		Dog& operator=(const Dog& p);
		int getWalk() const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Dog& d);
}
#endif // !SDDS_DOG_H

