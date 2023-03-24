/***********************************************************************
// OOP244 Workshop w6 p1:   Dog cpp file
//
// File Dog.cpp
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
#include <iostream>
#include "Dog.h"
using namespace std;

namespace sdds {
	Dog::Dog(const char* name, int initAge): Pet(name, initAge, cDogFee){
		m_noOfWalk = 0;
	}
	int Dog::getWalk() const{
		return m_noOfWalk;
	}
	void Dog::feed() {
		Pet::feed();
		if (Pet::live()) {
			addFee(fDogFee);
		}
	}
	void Dog::reSpawn() {
		Pet::reSpawn();
		addFee(rDogFee);
		m_noOfWalk = 0;
	}
	void Dog::walk() {
		if (live()) {
			m_noOfWalk += 1;
		}
	}
	Dog& Dog::operator++(int) {
		if (Pet::live()) {
			double healthDelta = 0;
			healthDelta += 0.15 * (Pet::getHug() - 1);
			healthDelta += 0.10 * (Pet::getFeed() - 2);
			healthDelta += 0.10 * (Pet::getClean() - 1);
			healthDelta += 0.20 * (m_noOfWalk - 2);

			addHealthLevel(healthDelta);
		}
		m_noOfWalk = 0;
		Pet::operator++(0);

		return *this;
	}
	Dog& Dog::operator=(const Dog& p) {
		double fee = (cDogFee + cBaseFee) * 2;
		Pet::operator=(p);
		addFee(fee);
		m_noOfWalk = p.m_noOfWalk;

		return *this;
	}
	std::ostream& operator<<(std::ostream& ostr, const Dog& d) {
		ostr << "** Generic Dog **" << endl;
		ostr << "   Walks: " << d.getWalk() << endl;
		d.display(ostr);

		return ostr;
	}
}
