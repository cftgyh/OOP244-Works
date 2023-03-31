/***********************************************************************
// OOP244 Workshop 9:
// File	main.cpp
// Version 1.0
// Data	Winter of 2023
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Data            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <fstream>
#include "Contact.h"

using namespace std;
using namespace sdds;
Contact readContact(ifstream& ifstr) {
    Contact fC;
    ifstr >> fC;
    return fC;
}

int main() {
    Contact C;
    ifstream file("contacts.txt");
    cout << "Empty Contact: >" << C << "<" << endl;
    cout << "Copy and paste the following data entries..." << endl;
    cout << "Enter the following (Correct Data Entry):" << endl
        << "Homer,Jay,Simpson" << endl
        << "70 the pond road,North York,ON,M3J3M6" << endl << endl;
    cout << "Name and address" << endl << "> ";
    cin >> C;
    if (cin)
        cout << "OK!" << endl;
    else {
        cout << "Data entry implemented incorrectly" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "Contact:" << endl << C << endl << endl;
    //---------------------------------------
    cout << "Enter the following (With Bad Province):" << endl
        << "Homer,Jay,Simpson" << endl
        << "70 the pond road,North York,ONT,M3J3M6" << endl << endl;
    cout << "Name and address" << endl << "> ";
    cin >> C;
    if (cin)
        cout << "Data entry implemented incorrectly" << endl;
    else {
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "Empty Contact: >" << C << "<" << endl << endl;
    //---------------------------------------
    cout << "Enter the following (With Bad Postal Code):" << endl
        << "Homer,Jay,Simpson" << endl
        << "70 the pond road,North York,ON,M3J 3M6" << endl << endl;
    cout << "Name and address" << endl << "> ";
    cin >> C;
    if (!cin) {
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "Empty Contact: >" << C << "<" << endl << endl;
    //---------------------------------------
    cout << "Enter the following (With Bad City):" << endl
        << "Homer,Jay,Simpson" << endl
        << "70 the pond road,,ON,M3J3M6" << endl << endl;
    cout << "Name and address" << endl << "> ";
    cin >> C;
    if (!cin) {
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "Empty Contact: >" << C << "<" << endl << endl;
    //---------------------------------------
    cout << "Enter the following (With Bad Street Address):" << endl
        << "Homer,Jay,Simpson" << endl
        << ",North York,ON,M3J3M6" << endl << endl;
    cout << "Name and address" << endl << "> ";
    cin >> C;
    if (!cin) {
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "Empty Contact: >" << C << "<" << endl << endl;
    cout << "Name and addresses in file: " << endl;

    while (file) {
        C = readContact(file);
        if (file) cout << C << endl;
    }
    return 0;
}