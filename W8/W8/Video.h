/***********************************************************************
// OOP244 Workshop w8 p1:  Video header file
//
// File Video.h
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
#ifndef SDDS_VIDEO_H
#define SDDS_VIDEO_H
#include "Media.h"

namespace sdds {
	class Video: public Media
	{
		int m_length{};
	protected:
		int get()const;
	public:
		Video();
		Video(int length);
		void load(std::istream& istr);
		virtual std::ostream& play(std::ostream& ostr)const = 0;
		
		Video(const Video& V) = delete;
		Video& operator=(const Video& V) = delete;
	};
}
#endif // !SDDS_VIDEO_H



