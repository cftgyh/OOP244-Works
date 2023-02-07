/***********************************************************************
// OOP244 Workshop 3 p2:  Store header file
//
// File Store.h
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
#include "Toys.h"
#ifndef SDDS_STORE_H
#define SDDS_STORE_H
#define MAX_NUM_TOYS 10	// The maximum number of toys that could be added.
#define MAX_SNAME 31	// The maximum length of a store name 

namespace sdds {
	class Store {
		char m_sName[MAX_SNAME];// Store name, up to MAX_SNAME size
		int m_noOfToys;//No of toys;
		int m_addToys;//no of toys added
		Toys m_toy[MAX_NUM_TOYS];// statically array of toys with size MAX_NUM_TOYS
	
	public:
		void setStore(const char* sName, int no);
		void setToys(const char* tname, int sku, double price, int age);
		void display()const;
		void find(int sku);
		void setEmpty();
	};
}
#endif // !SDDS_STORE_H

