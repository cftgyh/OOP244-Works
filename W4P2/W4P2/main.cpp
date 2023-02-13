/***********************************************************************
// OOP244 Workshop 4 Part2: Constructor, Destructor and the current object
// File main.cpp
// Version 1.0
// Date	2023/01
// Author Fardad Soleimanloo
// Description
// Tests NameTag module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
using namespace std;
#include "NameTag.h"
using namespace sdds;

int main() {
    // below 5 initializations are const type, so constructor must be const too
    NameTag nt[6] = {                                   // total 6 members in the array
       "A very very very long name to be cut short!!!", // one argument constructor
       {"Fred Soley", 12345} ,       // two argument constructor with good data
       {nullptr, 23456},    // two argument constructor with bad name
       {"Bad number", 1234},  // two argument constructor with bad number
       {"Bad number", 123456}  // two argument constructor with bad number
       // default constructor (sixth element)
    };

    int i;
    for (i = 0; i < 6; i++) {
        nt[i].print();
        cout << endl;
    }
    nt[1].read().print();
    nt[3].read().print();
    nt[5].read().print();
    return 0;
}