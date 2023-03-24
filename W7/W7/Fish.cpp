/***********************************************************************
// OOP244 Workshop w6 p1:   Fish cpp file
//
// File Fish.cpp
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
#include "Fish.h"
using namespace std;

namespace sdds {
	Fish::Fish(const char* name, int initAge): Pet(name, initAge, cFishFee){
		
	}
	void Fish::feed() {
		Pet::feed();
		if (Pet::live()) {
			addFee(fFishFee);
		}
	}
	void Fish::reSpawn() {
		Pet::reSpawn();
		addFee(rFishFee);
	}
	Fish& Fish::operator++(int) {
		if (Pet::live()) {
			double healthDelta = 0;
			healthDelta += 0.20 * (Pet::getFeed() - 1);

			addHealthLevel(healthDelta);
		}
		Pet::operator++(0);
		return *this;
	}
	Fish& Fish::operator=(const Fish& p) {
		double fee = (cBaseFee + cFishFee) * 2;
		Pet::operator=(p);
		addFee(fee);

		return *this;
	}
	std::ostream& operator<<(std::ostream& ostr, const Fish& f) {
		ostr << "** Generic Fish **" << endl;
		f.display(ostr);

		return ostr;
	}
}
