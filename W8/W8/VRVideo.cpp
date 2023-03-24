/***********************************************************************
// OOP244 Workshop w8 p1:  VRVideo cpp file
//
// File VRVideo.cpp
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
#include <cstring>
#include "VRVideo.h"

using namespace std;

namespace sdds {
	VRVideo::VRVideo(): Video()
	{
		m_equipment = nullptr;
	}
	VRVideo::VRVideo(int length,const char* string): Video(length)
	{
		if (length >= 0 && string != nullptr) {
			m_equipment = new char[strlen(string) + 1];
			strcpy(m_equipment, string);
		}
		else {
			m_equipment = nullptr;
		}
	}
	VRVideo::~VRVideo()
	{
		delete[] m_equipment;
		m_equipment = nullptr;
	}
	void VRVideo::load(std::istream& istr)
	{
		char temp[100];
		Video::load(istr);
		istr.getline(temp,100);
		delete[] m_equipment;
		m_equipment = nullptr;
		if (Video::get() >= 0 && temp!= nullptr) {
			m_equipment = new char[strlen(temp) + 1];
			strcpy(m_equipment, temp);
		}
		else {
			m_equipment = nullptr;
		}
	}
	std::ostream& VRVideo::play(std::ostream& ostr) const
	{
		if (Video::get() > 0 && m_equipment != nullptr) {
			ostr << "VRVideo requires " << m_equipment << endl;
			ostr << "Video Length = " << Video::get();
		}
		return ostr;
	}
}
