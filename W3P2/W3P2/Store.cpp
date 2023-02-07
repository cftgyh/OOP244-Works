/***********************************************************************
// OOP244 Workshop 3 p2:  Store cpp file
//
// File Store.cpp
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
#include <cstring>
#include "Store.h"
#include "Toys.h"

using namespace std;
namespace sdds {
	void Store::setStore(const char* sName, int no) {
		setEmpty();
		if (sName != nullptr) 
			if (strlen(sName) <= MAX_SNAME) {
				strcpy(m_sName, sName);
			}
		if (no <= MAX_NUM_TOYS) {
			m_noOfToys = no;
		}
		else
		{
			m_noOfToys = 0;
		}
	}
	void Store::setToys(const char* tname, int sku, double price, int age) {
		if (m_addToys < MAX_NUM_TOYS && m_addToys < m_noOfToys)
		{
			m_toy[m_addToys].addToys(tname, sku, price, age);
			m_addToys++;
		}
	}
	void Store::display()const {
		if (m_sName[0] == '\0') {
			cout << "Invalid Store" << endl;
		}
		else {
			cout.fill('*');
			cout.width(60);
			cout << '*' << endl;

			cout << m_sName << endl;

			cout.width(60);
			cout << '*' << endl;

			cout << "list of the toys" << endl;

			cout.fill(' ');
			cout.width(30);
			cout << "SKU";
			cout.width(10);
			cout << "Age";
			cout.width(11);
			cout << "Price";
			cout.width(10);
			cout << "Sale" << endl;
			for (int i = 0; i < m_noOfToys; i++) {
				cout << "Toy[" << i + 1 << "] :";
				m_toy[i].display();
			}
		}
	}
	void Store::find(int sku) {
		for (int i = 0; i < m_noOfToys; i++) {
			if (sku == m_toy[i].getSku() && !m_toy[i].isOnSale()) {
				m_toy[i].isSale(true);
				m_toy[i].calSale();
			}
		}
	}
	void Store::setEmpty() {
		m_sName[0] = '\0';// Store name, up to MAX_SNAME size
		m_noOfToys = 0;//No of toys
		m_addToys = 0;//no of toys added
		for (int i = 0; i < m_addToys; i++) {
			m_toy[i] = {};
		}
	}
}
