/***********************************************************************
// OOP244 Workshop w5 p1:  EggCarton cpp file
//
// File EggCarton.cpp
// Version 1.0
// Date  02/15/2023
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
#include <iostream>
#include "EggCarton.h"
using namespace std; // **********************************

namespace sdds {
	
	void EggCarton::setBroken() {
		m_size = -1;
		m_numOfEggs = -1;
	}
	EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) {
		if (size >= 6 && size <= 36 && size % 6 == 0 &&
			noOfEggs >= 0 && noOfEggs <= size) {
			m_size = size;
			m_numOfEggs = noOfEggs;
			m_isJumbo = jumboSize;
		}
		else {
			setBroken();
		}
	}
	EggCarton::~EggCarton() {
		setBroken();
	}
	istream& EggCarton::read(istream& istr) {
		m_isJumbo = false;
		char jumbo;
		int size, numOfegg;

		//jumbo = istr.get(); this statement also works
		istr >> jumbo;
		if (jumbo == 'j') {
			m_isJumbo = true;
		}
		istr.ignore();

		istr >> size;
		istr.ignore();

		istr >> numOfegg;
		istr.ignore();

		if (size >= 6 && size <= 36 && size % 6 == 0 &&
			numOfegg >= 0 && numOfegg <= size) {
			m_size = size;
			m_numOfEggs = numOfegg;
		}
		else {
			setBroken();
		}

		return istr;
	}
	//***********************************************
	ostream& EggCarton::display(ostream& ostr) const
	{
		if (bool(*this))
		{
			displayCarton(m_size, m_numOfEggs, m_isJumbo, ostr);
		}
		else
		{
			ostr << "Broken Egg Carton!" << endl;
		}
		return ostr;
	}

	ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr) const
	{
		int cartonWidth = size == 6 ? 3 : 6;
		for (int i = 0; i < size; i++)
		{
			ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
			((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
		}
		return ostr;
	}

	// Type Conversion Operator overloads
	EggCarton::operator bool() const
	{
		return m_size > 0;
	}
	EggCarton::operator int() const {
		int value;
		if (bool(*this)) {
			value = m_numOfEggs;
		}
		else { value = -1; }

		return value;
	}
	EggCarton::operator double() const {
		double value;
		int weight = m_isJumbo ? JumboEggWieght : RegularEggWieght;

		if (bool(*this)) {
			value = m_numOfEggs * weight * 0.001;
		}
		else { value = -1.0; }

		return value;
	}

	// Unary Operator overloads:
	EggCarton& EggCarton::operator--() {
		if (bool(*this) && m_numOfEggs > 0) {
			m_numOfEggs -= 1;
		}
		return *this;
	}
	EggCarton& EggCarton::operator++() {
		if (bool(*this)) {
			m_numOfEggs += 1;
			if (m_numOfEggs > m_size) {
				setBroken();
			}
		}
		return *this;
	}

	EggCarton EggCarton::operator--(int) {
		EggCarton old(m_size, m_numOfEggs, m_isJumbo);

		if (bool(this) && m_numOfEggs > 0) {
			m_numOfEggs -= 1;
		}

		return old;
	}
	
	EggCarton EggCarton::operator++(int) {
		EggCarton old(m_size, m_numOfEggs, m_isJumbo);

		if (bool(this) && m_numOfEggs > 0) {
			m_numOfEggs += 1;
		}

		return old;
	}

	// Binary Member Operators
	EggCarton& EggCarton::operator=(int value) {
		m_numOfEggs = value;
		if (m_numOfEggs > m_size) {
			setBroken();
		}
		return *this;
	}
	EggCarton& EggCarton::operator+=(int value) {
		if (bool(*this)) {
			m_numOfEggs += value;
			if (m_numOfEggs > m_size) {
				setBroken();
			}
		}
		return *this;
	}
	EggCarton& EggCarton::operator+=(EggCarton& right) {
		if (bool(*this)) {
			int differ = m_size - m_numOfEggs;
			if (differ >= right.m_numOfEggs) {
				m_numOfEggs += right.m_numOfEggs;
				right.m_numOfEggs = 0;
			}
			else {
				m_numOfEggs = m_size;
				right.m_numOfEggs -= differ;
			}
		}
		return *this;
	}
	bool EggCarton::operator==(const EggCarton& right) const {
		return ((double(*this) - double(right)) >= -0.001 &&
			((double(*this) - double(right)) <= 0.001));
	}


	// Helper Binary Operator Overload
	int operator+(int left, const EggCarton& right)
	{
		int value = left;
		if (bool(right)) {
			value = left + int(right);
		}
		return value;
	}
	ostream& operator<<(ostream& ostr, const EggCarton& right)
	{
		// TODO: insert return statement here
		return right.display(ostr);
	}

	istream& operator>>(istream& istr, EggCarton& right)
	{
		// TODO: insert return statement here
		return right.read(istr);
	}
}

