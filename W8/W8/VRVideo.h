/***********************************************************************
// OOP244 Workshop w8 p1:  VRVideo header file
//
// File VRVideo.h
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
#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H
#include "Video.h"

namespace sdds {
	class VRVideo: public Video {
		char* m_equipment{};
	public:
		VRVideo();
		VRVideo(int length, const char* string);
		~VRVideo();

		void load(std::istream& istr);
		std::ostream& play(std::ostream& ostr)const;
	};
}
#endif // !SDDS_VRVIDEO_H



