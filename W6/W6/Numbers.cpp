/***********************************************************************
// OOP244 Workshop w6 p1:  Numbers cpp file
//
// File Numbers.cpp
// Version 1.0
// Date  03/05/2023
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
#include <fstream>
#include <cstring>
#include <string>
#include "Numbers.h"
using namespace std;

namespace sdds
{
	// private functions
	void Numbers::sort(double* array, unsigned int size) {
		if (array) {
			for (unsigned int i = 1; i < size; i++) {
				double max = array[i];
				int j = i - 1;
				while (j >= 0 && array[j] > max) {
					array[j + 1] = array[j];
					j--;
				}
				array[j + 1] = max;
			}
		}
	}
	// directly count lines in file
	unsigned int Numbers::countLines() const {
		int lineCount{};
		string str;
		ifstream f(m_fileName);
		if (f.is_open()) {
			while (getline(f, str)) {
				lineCount++;
			}
		}
		f.close();
		return lineCount;
	}
	void Numbers::setEmpty() {
		m_collection = nullptr;
		strcpy(m_fileName, "");
		m_collectionSize = 0;
		m_originalFlag = false;
		m_addFlag = false;
	}
	bool Numbers::load() {
		bool success = false;
		unsigned int noOfLines = countLines();
		unsigned int count{};
		double temp{};
		delete[] m_collection;
		m_collection = nullptr;
		if (noOfLines > 0) {
			m_collection = new double[noOfLines];
			ifstream f(m_fileName);
			if (f.is_open()) {
				while (count < noOfLines && f >> temp) {
					m_collection[count] = temp;
					count++;
				}
				success = true;
			}
			f.close();
			if (noOfLines == count) {
				m_collectionSize = noOfLines;
				m_originalFlag = true;
			}
			else {
				delete[] m_collection; //leak?
				setEmpty();
			}
		}
		return success;
	}
	void Numbers::save() {
		if (m_originalFlag && m_addFlag) {
			ofstream f(m_fileName);
			if (f.is_open()) {
				for (unsigned int i = 0; i < m_collectionSize; i++) {
					f.setf(ios::fixed);
					f.precision(2);
					f << m_collection[i] << endl;
				}
			}
		}
	}
	double Numbers::max() const {
		double largest = m_collection[m_collectionSize - 1];
		for (unsigned int i = m_collectionSize - 2; i > 0; i--) {
			if (m_collection[i] > largest) {
				largest = m_collection[i];
			}
		}
		return largest;
	}
	double Numbers::min() const {
		double minimum = m_collection[0];
		for (unsigned int i = 1; i < m_collectionSize; i++) {
			if (m_collection[i] < minimum) {
				minimum = m_collection[i];
			}
		}
		return minimum;
	}
	double Numbers::average() const {
		double total{};
		for (unsigned int i = 0; i < m_collectionSize; i++) {
			total += m_collection[i];
		}
		return total / m_collectionSize;
	}

	// public functions
	Numbers::Numbers(const char* cString) {
		setEmpty();
		strcpy(m_fileName, cString);
		load();
	}
	Numbers::Numbers() {
		setEmpty();
	}
	Numbers::~Numbers() {
		save();
		delete[] m_collection;
	}
	// copy constructor
	Numbers::Numbers(const Numbers& source) {
		m_collection = nullptr;
		*this = source;
	}
	// copy assignment operator
	Numbers& Numbers::operator=(const Numbers& source) {
		if (this != &source) {
			save();
			delete[] m_collection;
			setEmpty();
			if (source) {
				m_originalFlag = false;
				m_collection = new double[source.m_collectionSize];
				for (unsigned int i = 0; i < source.m_collectionSize; i++) {
					m_collection[i] = source.m_collection[i];
				}
				m_collectionSize = source.m_collectionSize;
				strcpy(m_fileName, source.m_fileName);
			}
		}
		return *this;
	}
	Numbers::operator bool() const {
		return m_collection != nullptr;
	}
	void Numbers::sort() {
		sort(m_collection, m_collectionSize);
	}
	Numbers& Numbers::operator+=(double value) {
		if (*this) {
			double* temp = nullptr;
			temp = new double[m_collectionSize + 1];
			for (unsigned int i = 0; i < m_collectionSize; i++) {
				temp[i] = m_collection[i];
			}
			temp[m_collectionSize] = value;
			delete[] m_collection;
			m_collection = nullptr;
			m_collection = temp;
			m_collectionSize += 1;
			m_addFlag = true;
		}
		return *this;
	}
	ostream& Numbers::display(ostream& ostr) const {
		if (m_collection == nullptr) {
			ostr << "Empty list";
		}
		else {
			ostr.setf(ios::fixed);
			ostr.precision(2);
			if (!m_originalFlag) ostr << "Copy of ";
			ostr << m_fileName << endl;
			for (unsigned int i = 0; i < m_collectionSize - 1; i++) {
				ostr << m_collection[i] << ", ";
			}
			ostr << m_collection[m_collectionSize - 1] << endl;
			ostr.fill('-');
			ostr.width(76);
			ostr << '-' << endl;
			ostr << "Total of " << m_collectionSize << " number(s), "
				<< "Largest: " << max() << ", "
				<< "Smallest: " << min() << ", "
				<< "Average: " << average() << endl;
			ostr.fill('=');
			ostr.width(76);
			ostr << '=';
		}
		return ostr;
	}
	// helper functions
	ostream& operator<<(ostream& ostr, const Numbers& right) {
		return right.display(ostr);
	}
	istream& operator>>(istream& istr, Numbers& right) {
		double temp{};
		istr >> temp;
		right += temp;
		return istr;
	}
}