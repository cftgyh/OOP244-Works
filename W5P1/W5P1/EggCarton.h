/***********************************************************************
// OOP244 Workshop w5 p1:  EggCarton header file
//
// File EggCarton.h
// Version 1.0
// Date  02/15/2023
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

#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H

namespace sdds {
	class EggCarton {
		const int RegularEggWieght = 50;
		const int JumboEggWieght = 75;
		int m_size;	// num of eggs can hold
		int m_numOfEggs; // num of eggs in the carton
		bool m_isJumbo; // if jumbo, value = true
		void setBroken();
		
	public:
		EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
		void set(int size = 6, int noOfEggs = 0, bool jumboSize = false);
		istream& read(istream& istr = cin);
		ostream& displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const;

		// Type Conversion Operator overloads
		operator bool() const;
		operator int() const;
		operator double() const;

		// Unary Operator overloads:
		EggCarton& operator--();
		EggCarton& operator++();
		EggCarton operator--(int);
		EggCarton operator++(int);

		// Binary Member Operators
		EggCarton& operator=(int value);
		EggCarton& operator=(EggCarton& right);
		EggCarton& operator+=(int value);
		EggCarton& operator+=(EggCarton& right);
		bool operator==(const EggCarton& right) const;

		// Query function
		int getSize() const;
		bool getJumbol() const;
	};

	// Helper Binary Operator Overload
	int operator+(int left, const EggCarton& right);
	ostream& operator<<(ostream& ostr, const EggCarton& right);
	istream& operator>>(istream& istr, EggCarton& right);
}

#endif // !SDDS_EGGCARTON_H




