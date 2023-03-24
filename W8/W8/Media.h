/***********************************************************************
// OOP244 Workshop w8 p1:  Media header file
//
// File Media.h
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
#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H
namespace sdds {
	class Media
	{
	public:
		virtual ~Media() {}; //virtual ~Media() = default;
		virtual void load(std::istream& istr) = 0;
		virtual std::ostream& play(std::ostream& ostr)const = 0;
	};
	std::istream& operator>>(std::istream& istr, Media& M);
	std::ostream& operator<<(std::ostream& ostr, const Media& M);
}
#endif // !SDDS_MEDIA_H



