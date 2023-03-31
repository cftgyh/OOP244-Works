/***********************************************************************
// OOP244 Workshop 9:
// File  nameTeste.cpp
// Version 1.0
// Date  Winter of 2023
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream>
#include "Person.h"
using namespace std;
using namespace sdds;
Person readName(ifstream& ifstr) {
    Person fP;
    ifstr >> fP;
    return fP;
}

int main() {
    Person P;
    ifstream file("names.txt");
    cout << "Empty name: >" << P << "<" << endl;
    cout << "Enter the following" << endl << "Homer,Jay,Simpson<ENTER>" << endl;
    cout << "Enter Comma separated name: ";
    cin >> P;
    cout << "Name: " << P << endl;
    cout << "Enter the following" << endl << "Homer,,Simpson<ENTER>" << endl;
    cout << "Enter Comma separated name: ";
    cin >> P;
    cout << "Name: " << P << endl;
    cout << "Contents of the file: " << endl;
    while (file) {
        P = readName(file);
        if (file) cout << P << endl;
    }
    return 0;
}