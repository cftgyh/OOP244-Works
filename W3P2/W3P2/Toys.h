/***********************************************************************
// OOP244 Workshop 3 p2:  Toys header file
//
// File Toys.h
// Version 1.0
// Date  02/05/2023
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

#ifndef SDDS_TOYS_H
#define SDDS_TOYS_H
#define MAX_TNAME 31 // The maximum length of a Toy name 

namespace sdds {
	class Toys {
		char m_tname[MAX_TNAME] = { 0 };// toy name, up to MAX_TNAME size
		int m_sku = 0; //SKU number, maximum 8 digits long
		double m_price = 0.0;//toy price
		int m_age = 0;//toy according to age group
		bool m_onSale = false;// keep track, if toys are on sale or not
	
	public:
		void addToys(const char* tname, int sku, double price, int age);
		void isSale(bool sale);
		void calSale();
		void display()const;
		int getSku()const;
		bool isOnSale()const;
	};
}
#endif // !SDDS_TOYS_H


