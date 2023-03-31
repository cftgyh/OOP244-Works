/***********************************************************************
// OOP244 Workshop w9 p1:  Utils header file
//
// File Utils.h
// Version 1.0
// Date  03/28/2023
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
#ifndef SDDS_TOOLS_H
#define SDDS_TOOLS_H

namespace sdds {
	class Tools
	{
	public:
		size_t strlen(const char* str)const;
		char* strcpy(char* des, const char* src)const;
		char* strcpy(char* des, const char* src, int len)const;
		char* strcat(char* des, const char* src)const;
		int strcmp(const char* s1, const char* s2)const;
		char* aloCopy(size_t length, const char* src)const;
	};
	extern Tools U;
}
#endif // !SDDS_TOOLS_H
