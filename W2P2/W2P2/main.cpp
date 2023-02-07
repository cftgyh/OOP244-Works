/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  main.cpp
// Version 1.1
// Date   Fall 2022
// Author Yosef Ashibani
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Yosef Ashibani   23-01-24       reordered user's tweets report
/////////////////////////////////////////////////////////////////
***********************************************************************/

// Please don't change this file
// This file is to test your source code

#include <iostream>
#include "Customer.h"
using namespace std;
using namespace sdds;

int main() {
    bool Check = false;

    Customers c_rec;
    EmptyRecord(c_rec);

    CustomersRecord t_rec;
    EmptyRecord(t_rec);

    cout << "---------  Customers records entry ------------------" << endl;
    while (!Check) {
        cout << endl << "Enter customer information (to exit, press Enter): " << endl;
        if (read(c_rec)) {
            addCustomer(t_rec, c_rec);
        }
        else {
            Check = true;
        }
    }
    cout << "---------------------------------------------------------" << endl;
    cout << "                Users' tweets report                     " << endl;
    cout << " user name, likes, re-tweets, replies, share videos (y/n)" << endl;
    cout << "---------------------------------------------------------" << endl;

    display(t_rec);
    cout << "---------------------------------------------------------" << endl;
    cout << "            Report was successfully created                " << endl;

    delete[] t_rec.ptr_rec;
    cout << "Dynamically allocated memory was successfully deallocated" << endl;
    cout << "---------------------------------------------------------" << endl;

}



