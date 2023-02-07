/***********************************************************************
// OOP244 Workshop 3 p2:  Toys cpp file
//
// File Toys.cpp
// Version 1.0
// Date  02/05/2023
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
#include <iomanip>
#include <cstring>
#include "Toys.h"
#include "Store.h"

using namespace std;
namespace sdds{
	void Toys::addToys(const char* tname, int sku, double price, int age) {
		if (tname != nullptr) 
		{
			if (strlen(tname) <= MAX_TNAME && sku >= 10000000 && sku <= 99999999) {
				strcpy(m_tname, tname);
				m_sku = sku;
				m_price = price;
				m_age = age;
			}
		}
	}

	void Toys::isSale(bool sale) {
		m_onSale = sale;
	}
	void Toys::calSale() {
		m_price *= 0.8;
	}
	void Toys::display()const {
		if (m_tname[0] == '\0') {
			cout << "Invalid Toy" << endl;
		}
		else {
			cout.setf(ios::left);
			cout.width(15);
			cout << m_tname;
			cout.unsetf(ios::left);

			cout.width(10);
			cout << m_sku;
			cout.width(6);
			cout << m_age;
			cout.width(12);
			cout << fixed << setprecision(2) << m_price;
			if (m_onSale) {
				cout.width(10);
				cout << "On Sale" << ' ' << endl;
			}
			else {
				cout.fill(' ');
				cout.width(8);
				cout << ' ' << endl;
			}
		}
		
	}
	int Toys::getSku() const{
		return m_sku;
	}
	bool Toys::isOnSale() const{
		return m_onSale;
	}
}

