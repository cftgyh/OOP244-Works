/***********************************************************************
// OOP244 Workshop w6 p1:   Pet header file
//
// File Pet.h
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
#ifndef SDDS_PET_H
#define SDDS_PET_H
#include <iostream>

namespace sdds {
	class Pet
	{
		const double cBaseFee = 1.00;
		const double fBaseFee = 0.00;
		const double rBaseFee = 0.25;
		// variables
		char m_petName[21]{};
		int m_originAge{};
		int m_currentAge{};
		int m_noOfFeed{};
		int m_noOfHug{};
		int m_noOfClean{};
		double m_totalAmount{};
		double m_healthLevel{};
	protected:
		int getFeed();
		int getHug();
		int getClean();
		void addFee(double amount);
		void addHealthLevel(double value);
		//...
	public:
		Pet();
		//  A pet is considered to be Alive after this constructor is invoked.
		// createFee: optional incremental fee to create this pet
		Pet(const char* petName, int originAge = 0, double createFee = 0.0);
		void feed();
		void groom();
		void hug();
		bool live() const;
		std::ostream& payBalance(std::ostream& ostr);
		void reSpawn();
		Pet& operator++(int);
		Pet& operator=(const Pet& p);
		std::ostream& display(std::ostream& ostr) const;
	};
	// helper function
	std::ostream& operator<<(std::ostream& ostr, const Pet& p);
}
#endif // !SDDS_PET_H
