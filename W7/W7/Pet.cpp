/***********************************************************************
// OOP244 Workshop w6 p1:   Pet cpp file
//
// File Pet.cpp
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
#include <cstring>
#include "Pet.h"
using namespace std;

namespace sdds {
	// protected methods
	int Pet::getFeed() {
		return m_noOfFeed;
	}
	int Pet::getHug() {
		return m_noOfHug;
	}
	int Pet::getClean() {
		return m_noOfClean;
	}
	void Pet::addFee(double amount) {
		m_totalAmount += amount;
	}
	void Pet::addHealthLevel(double value) {
		m_healthLevel += value;
	}
	// public methods
	Pet::Pet() {
		m_currentAge = -1;
		m_originAge = -1;
		m_healthLevel = -1;
		m_petName[0] = '\0';
		m_noOfFeed = 0;
		m_noOfHug = 0;
		m_noOfClean = 0;
		m_totalAmount = 0.0;
	}
	Pet::Pet(const char* petName, int originAge, double createFee) {
		if (petName) {
			strcpy(m_petName, petName);
			m_originAge = originAge;
			m_currentAge = originAge;
			m_totalAmount = cBaseFee + createFee;
			m_healthLevel = 1.0;
		}
	}
	void Pet::feed() {
		if (live()) {
			m_noOfFeed += 1;
		}
	}
	void Pet::groom() {
		if (live()) {
			m_noOfClean += 1;
		}
	}
	void Pet::hug() {
		if (live()) {
			m_noOfHug += 1;
		}
	}
	bool Pet::live() const{
		return (m_healthLevel >= 0 && m_healthLevel <= 2);
	}
	std::ostream& Pet::payBalance(std::ostream& ostr) {
		ostr << ">> Balance of $" << m_totalAmount << " has been paid for " << m_petName << endl;
		m_totalAmount = 0.0;

		return ostr;
	}
	void Pet::reSpawn() {
		m_healthLevel = 1.0;
		m_currentAge = m_originAge;
		m_noOfClean = 0;
		m_noOfFeed = 0;
		m_noOfHug = 0;
		m_totalAmount += rBaseFee;
	}
	Pet& Pet::operator++(int) {
		if (live()) {
			m_currentAge += 1;
		}
		m_noOfClean = 0;
		m_noOfFeed = 0;
		m_noOfHug = 0;
		
		return *this;
	}
	Pet& Pet::operator=(const Pet& p) {
		char temp[21]{};
		strcpy(temp, p.m_petName);
		strcpy(m_petName, strcat(temp, "(C)"));
		m_currentAge = p.m_currentAge;
		m_originAge = p.m_originAge;
		m_noOfFeed = p.m_noOfFeed;
		m_noOfHug = p.m_noOfHug;
		m_noOfClean = p.m_noOfClean;
		m_totalAmount = 0;
		m_healthLevel = p.m_healthLevel;

		return *this;
	}
	std::ostream& Pet::display(std::ostream& ostr) const {
		ostr << "   Name: " << m_petName << "; ";
		ostr << m_currentAge << " days old" << endl;
		ostr << "   Feeds, Cleans, Hugs: ";
		ostr << m_noOfFeed << ", " << m_noOfClean << ", " << m_noOfHug << endl;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "   Charges: $" << m_totalAmount << endl;
		ostr << "   Health : " << m_healthLevel;
		if (m_healthLevel == 1.0) {
			ostr << " (Ideal)";
		}
		else if (m_healthLevel > 1.0 && m_healthLevel <= 2.0) {
			ostr << " (Over Nurtured)";
		}
		else if(m_healthLevel < 1.0 && m_healthLevel >= 0.0){
			ostr << " (Under Nurtured)";
		}
		else {
			ostr << " (PERISHED)";
		}
		ostr << endl;

		return ostr;
	}
	// helper function
	std::ostream& operator<<(std::ostream& ostr, const Pet& p) {
		ostr << "** Generic Pet **" << endl;
		p.display(ostr);

		return ostr;
	}
}

