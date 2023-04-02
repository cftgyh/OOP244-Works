/***********************************************************************
// OOP244 Workshop 9:
// File	Utils.h
// Version 1.0
// Date	Winter of 2023
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_TOOLS_H__
#define SDDS_TOOLS_H__
#include <iostream>
#include <fstream>
namespace sdds {
	int strLen(const char* str);
	void strCpy(char* des, const char* src);
	void strCat(char* des, const char* src);
	void delAlloCopy(char*& des, const char* src);
	char* dynRead(std::istream& istr, char delimeter = '\n');
}
#endif // !