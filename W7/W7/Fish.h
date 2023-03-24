/***********************************************************************
// OOP244 Workshop w6 p1:   Fish header file
//
// File Fish.h
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
#ifndef SDDS_FISH_H
#define SDDS_FISH_H
#include "Pet.h"
#include <ostream>
using namespace std;

namespace sdds {
	class Fish: public Pet
	{
		const double cBaseFee = 1.00;
		const double cFishFee = 2.00;
		const double fFishFee = 0.10;
		const double rFishFee = 0.50;

	public:
		Fish(const char* name, int initAge = 0);
		void feed();
		void reSpawn();
		Fish& operator++(int);
		Fish& operator=(const Fish& p);
	};
	std::ostream& operator<<(std::ostream& ostr, const Fish& f);
}
#endif // !SDDS_FISH_H
