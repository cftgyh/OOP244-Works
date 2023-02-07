/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File main.cpp
// Version 1.0
// Date	2022/10/28
// Author Nargis Khan
// Description
// Tests Store module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include<iostream>
#include<cstring>
#include"Store.h"
using namespace std;
using namespace sdds;

int main() {

	Store s;
	cout << "Printing invalid list of Toys" << endl;
	s.setStore("****Children`s Dream store****", 2);
	s.setToys(nullptr, 20304576, 12.50, 2); //SKU should be 8 digit, price and age
	s.setToys("Car", 203045, 11.50, 12);
	s.display();


	cout << endl << "Printing valid list of Toys" << endl;
	s.setStore("****Children`s Dream store****", 6);
	s.setToys("Racing Car", 11223344, 40.99, 8);
	s.setToys("Teddy Bear", 33772346, 25.99, 6); //onsale
	s.setToys("Airplane", 44453466, 60.99, 16);
	s.setToys("Doll", 55887896, 45.99, 5);
	s.setToys("Drone", 99221388, 90.99, 18);//onsale
	s.setToys("Lego", 88224596, 65.99, 10);//onsale
	s.display();

	cout << endl << "Searching for toys and printing the list with sale price" << endl;
	s.find(33772346);//Teddy Bear
	s.find(99221388);//drone
	s.find(88224596); //lego
	s.display();

}
