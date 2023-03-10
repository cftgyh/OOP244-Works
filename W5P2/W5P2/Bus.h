/***********************************************************************
// OOP244 Workshop w5 p2: Bus header file
//
// File Bus.h
// Version 1.0
// Date  02/18/2023
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
#ifndef SDDS_BUS_H
#define SDDS_BUS_H
#include <iostream>
using namespace std;

namespace sdds {
	const double ticketPrice = 125.34;
	class Bus
	{
		int m_noOfSeats;
		int m_noOfPsgers;
		void drawBus(int seats, int noOfPassengers, ostream& ostr) const;

	public:
		Bus(int seats = 20, int passengers = 0);
		~Bus();
		void setOutOfService();
		// Read function
		istream& read(istream& istr = cin);

		// Display function
		ostream& display(ostream& ostr) const;

		// Type Conversion Operator overloads
		operator bool() const;
		operator int() const;
		operator double() const;

		// Unary Operator overloads:
		bool operator--();
		bool operator++();
		bool operator--(int);
		bool operator++(int);

		// Binary Member Operators
		Bus& operator=(int value);
		Bus& operator+=(int value);
		Bus& operator+=(Bus& right);
		bool operator==(const Bus& right) const;
	};
	// Helper Binary Operator Overload
	int operator+(int left, const Bus& right);
	ostream& operator<<(ostream& ostr, const Bus& right);
	istream& operator>>(istream& istr, Bus& right);
}
 
#endif // !SDDS_BUS_H


