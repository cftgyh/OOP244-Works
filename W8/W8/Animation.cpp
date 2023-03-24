/***********************************************************************
// OOP244 Workshop w8 p1:  Animation cpp file
//
// File Animation.cpp
// Version 1.0
// Date  03/22/2023
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
#include "Animation.h"
using namespace std;

namespace sdds {
	Animation::Animation(): Video()
	{
		m_dimension = 0;
	}
	Animation::Animation(int length, int dimension): Video(length)
	{
		if (dimension == 2 || dimension == 3) {
			m_dimension = dimension;
		}
		else {
			m_dimension = 0;
		}
	}
	void Animation::load(std::istream& istr)
	{
		int temp{};
		Video::load(istr);
		istr >> temp;
		istr.ignore(10000, '\n');
		if (temp == 2 || temp == 3) {
			m_dimension = temp;
		}
		else {
			m_dimension = 0;
		}
	}
	std::ostream& Animation::play(std::ostream& ostr) const
	{
		if (Video::get() > 0 && m_dimension != 0) {
			ostr << "Animation is in " << m_dimension << "-D" << endl;
			ostr << "Video Length = " << Video::get();
		}
		return ostr;
	}
}
