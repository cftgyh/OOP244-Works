/***********************************************************************
// OOP244 Workshop w5 p1:  Bus cpp file
//
// File Bus.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Bus.h"

using namespace std;

namespace sdds {
	Bus::Bus(int seats, int passengers) {
		if (seats % 2 == 0 &&
			seats >= 10 && seats <= 40 &&
			passengers >= 0 && passengers <= seats) {
			m_noOfSeats = seats;
			m_noOfPsgers = passengers;
		}
		else {
			setOutOfService();
		}
	}
	Bus::~Bus() {
		setOutOfService();
	}
	void Bus::setOutOfService() {
		m_noOfSeats = -1;
	}
	// Read function
	istream& Bus::read(istream& istr) {
		int seats, passengers;
		istr >> seats;
		istr.ignore();

		istr >> passengers;
		istr.ignore();

		if (seats % 2 == 0 &&
			seats >= 10 && seats <= 40 &&
			passengers >= 0 && passengers <= seats) {
			m_noOfSeats = seats;
			m_noOfPsgers = passengers;
		}
		else {
			setOutOfService();
		}
		return istr;
	}

	// Display function
	void Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const {
			int i, p;
			ostr.fill('_');
			ostr.width((static_cast<std::streamsize>(seats / 2)) * 3 + 4);
			ostr << "_";
			ostr << endl << "| ";
			for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
			ostr << "|_\\_" << endl;
			ostr << "| ";
			ostr.fill(' ');
			ostr.width(((static_cast<std::streamsize>(seats / 2)) * 3 - 14) / 2);
			ostr << " " << "Seneca College";
			ostr.width(static_cast<std::streamsize>(((seats / 2) * 3 - 14) / 2) + (seats % 4 != 0));
			ostr << " " << "    )" << endl;
			ostr << "`---OO";
			ostr.fill('-');
			ostr.width((static_cast<std::streamsize>(seats / 2)) * 3 - 5);
			ostr << "-" << "O---'" << endl;
			ostr.setf(ios::fixed);
		    ostr.precision(2);
			ostr << "Total Fare Price: " << double(*this) << endl;
	}
	ostream& Bus::display(ostream& ostr) const {
		if (bool(*this)) {
			drawBus(m_noOfSeats, m_noOfPsgers, ostr);
		}
		else {
			ostr << "Out of service!" << endl;
		}
		return ostr;
	}

	// Type Conversion Operator overloads
	Bus::operator bool() const {
		return m_noOfSeats > 0; // returns true if the bus is in service
	}
	Bus::operator int() const {
		return bool(*this) ? m_noOfPsgers : -1;
								// return number of passengers
	}
	Bus::operator double() const {
		return bool(*this) ? (m_noOfPsgers * ticketPrice) : -1.0;
								// return total fare
	}
	// Unary Operator overloads:
	bool Bus::operator--() {
		bool minus = false;
		if (bool(*this) && m_noOfPsgers > 0) {
			m_noOfPsgers--;
			minus = true;
		}
		return minus;
	}
	bool Bus::operator++() {
		bool plus = false;
		if (bool(*this) && (m_noOfPsgers < m_noOfSeats)) {
			m_noOfPsgers++;
			plus = true;
		}
		return plus;
	}
	bool Bus::operator--(int) {
		bool minus = false;
		if (bool(*this) && m_noOfPsgers > 0) {
			m_noOfPsgers--;
			minus = true;
		}
		return minus;
	}
	bool Bus::operator++(int) {
		bool plus = false;
		if (bool(*this) && (m_noOfPsgers < m_noOfSeats)) {
			m_noOfPsgers++;
			plus = true;
		}
		return plus;
	}

	// Binary Member Operators
	Bus& Bus::operator=(int value) {
		if (value > m_noOfSeats) {
			setOutOfService();
		}
		else {
			m_noOfPsgers = value;
		}
		return *this;
	}
	Bus& Bus::operator+=(int value) {
		if (bool(*this)) {
			m_noOfPsgers += value;
			if (m_noOfPsgers > m_noOfSeats) {
				setOutOfService();
			}
		}
		return *this;
	}
	Bus& Bus::operator+=(Bus& right) {
		if (bool(*this) && bool(right)) {
			int space = m_noOfSeats - m_noOfPsgers;
			if (right.m_noOfPsgers <= space) {
				m_noOfPsgers += right.m_noOfPsgers;
				right.m_noOfPsgers = 0;
			}
			else {
				m_noOfPsgers = m_noOfSeats;
				right.m_noOfPsgers -= space;
			}
		}
		return *this;
	}
	bool Bus::operator==(const Bus& right) const {
		bool equal = false;
		if (bool(*this) && bool(right) && 
			m_noOfPsgers == right.m_noOfPsgers) {
			equal = true;
		}
		return equal;
	}

	// Helper Binary Operator Overload
	int operator+(int left, const Bus& right) {
		int value = left;
		if (bool(right)) {
			value = left + int(right);
		}
		return value;
	}
	ostream& operator<<(ostream& ostr, const Bus& right) {
		return right.display(ostr);
	}
	istream& operator>>(istream& istr, Bus& right) {
		return right.read(istr);
	}
}