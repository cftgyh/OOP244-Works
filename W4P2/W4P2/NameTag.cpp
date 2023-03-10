/***********************************************************************
// OOP244 Workshop w4 p2:  NameTag cpp file
//
// File NameTag.cpp
// Version 1.0
// Date  02/11/2023
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
#include "NameTag.h"

using namespace std;
namespace sdds {
	NameTag::NameTag(const char* name) {
		m_name = nullptr;
		set(name, 0);
	}
	NameTag::NameTag(const char* name, unsigned int eNumber) {
		m_name = nullptr;
		set(name, eNumber);
	}
	NameTag::NameTag() {
		setEmpty();
	}
	NameTag::~NameTag() {
		deallocate();
	}
	void NameTag::deallocate() {
		delete[] m_name;
		m_name = nullptr;
	}
	void NameTag::setEmpty() {
		m_name = nullptr;
		m_extensionNum = 0;
	}
	void NameTag::set(const char* name, unsigned int eNumber) { // const use with pointer (pointer can change the value)
		deallocate(); //put new memory, so ready for store new memory

		if ((name != nullptr && 
			(eNumber == 0 || (eNumber >= 10000 && eNumber <= 99999)))) {
			int length = strlen(name);
			m_name = new char[length + 1];
			strcpy(m_name, name);
			if (length > 40) {
				m_name[40] = '\0';
			}
			m_extensionNum = eNumber;
		}
	}
	void NameTag::print() {

		int width = 0;
		if (m_name == nullptr || 
			(m_extensionNum!=0 && 
			(m_extensionNum < 10000 || m_extensionNum > 99999))){
			cout << "EMPTY NAMETAG!" << endl;
		}
		else {
			if (strlen(m_name) <= 20) {
				width = 20;
			}
			else if (strlen(m_name) > 20) {
				width = 40;
			}
			cout.setf(ios::left);
			cout << "+";
			cout.width(static_cast<std::streamsize>(width) + 3);
			cout.fill('-');
			cout.unsetf(ios::left);
			cout << "+" << endl;

			cout.setf(ios::left);
			cout << "| ";
			cout.width(width);
			cout.fill(' ');
			cout << ' ';
			cout << " |" << endl;

			cout << "| ";
			cout.width(width);
			cout << m_name;
			cout << " |" << endl;

			cout << "| ";
			cout.width(width);
			cout.fill(' ');
			cout << ' ';
			cout << " |" << endl;

			cout << "| ";
			cout << "Extension: ";
			cout.width(static_cast<std::streamsize>(width) - 11);
			if (m_extensionNum == 0) {
				cout << "N/A";
			}
			else {
				cout << m_extensionNum;
			}
			cout << " |" << endl;

			cout << "| ";
			cout.width(width);
			cout.fill(' ');
			cout << ' ';
			cout << " |" << endl;

			cout << "+";
			cout.width(static_cast<std::streamsize>(width) + 3);
			cout.fill('-');
			cout.unsetf(ios::left);
			cout << "+" << endl;
		}
	}
	NameTag& NameTag::read() {
		deallocate(); //m_name will be covered by read data, so must be deleted before read, otherwise memory leak

		char name[41]{};
		char yn;
		int extension = 0, noValid = 1;
		cout << "Please enter the name: ";
		cin.get(name, 41);
		cin.ignore(10000,'\n');
		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
		cin.get(yn);
		cin.ignore(10000, '\n');

		while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N') {
			cout << "Only (Y) or (N) are acceptable, try again: ";
			cin.get(yn);
			cin.ignore(10000, '\n');
		}

		if (yn == 'y' || yn == 'Y') {
			cout << "Please enter a 5 digit phone extension: ";
			do {
				cin >> extension;	
				if (cin.fail()) {
					cout << "Bad integer value, try again: ";
					cin.clear();	// clear cin.fail() flag
				}
				else {
					noValid = (extension < 10000 || extension > 99999);
					if (noValid) {
						cout << "Invalid value [10000<=value<=99999]: ";
					}
				}
				cin.ignore(10000, '\n');
			} while (cin.fail() || noValid);
			set(name, extension);
		}
		else {
			set(name, 0);
		}
		return *this;
	}
}
