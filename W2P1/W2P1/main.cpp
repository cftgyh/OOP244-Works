/***********************************************************************
// OOP244 Workshop 2 p1: tester program
//
// File	main.cpp
// Version 1.0
// Date Fall 2022
// Author  Yosef Ashibani
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

// Please don't change this file
// This file is to test your full program

#include<iostream>
#include "Package.h"

using namespace std;
using namespace sdds;
const bool APP_OS_WINDOWS = true;

int main() {
    
    loadTraces();
    cout << "Records were retrieved successfully" << endl;

    grouptTraces();
    cout << "Data records were grouped by the user id successfully" << endl;

    cout<< "User id, timeinhours, Fctime, Fwifitime, Package Name" << endl
        << "....................................................." << endl;

    display();
    cout << "\nData was successfully printed" << endl;
    
    deallocateMemory();
    cout << "Dynamically allocated memory was successfully deallocated"<<endl;
    return 0;
}



/* Sample data file
*
User id, timeinhours, Fctime, Fwifitime,  Package Name
-------  -----------  ------  ---------  -------------------
  2	    0.030551111   1989	    107995	 com.android.chrome
  8	    6.151203056   16928911  5215420	 com.android.chrome
  8	    6.151203056   16928911  5215420	 com.android.chrome
  1       1.065473889   3777966   57740	 com.android.mms
  8	    0.040814444   146932    0	     com.android.mms
  3	    0.270954722   0	        975437	 com.android.phone
  1	    0.010256389   13826	    23097	 com.android.settings
  2	    0.001665556   0	        5996	 com.android.settings
  3	    0.008332778   0	        29998	 com.baidu.baidulife


*/


/* Sample execution

Records were retrieved successfully
Data records were grouped by the user id successfully
User id, timeinhours, Fctime, Fwifitime, Package Name
.....................................................
0, 1.49325, 369926, 5005762, com.tencent.mm
0, 1.35947, 172756, 4721320, com.tencent.mm
0, 1.66986, 1221, 6010276, com.UCMobile
5, 1.60287, 5722288, 48042, com.sina.weibo
5, 1.92426, 260011, 6667309, com.tencent.mm
5, 1.47877, 2089902, 3233672, com.UCMobile
9, 1.02618, 288007, 3406229, com.digiplex.game
9, 1.23554, 59991, 4387945, com.tencent.mm
9, 12.9425, 2190642, 44402341, com.tencent.mm
9, 1.21251, 2544077, 1820967, com.tencent.qqmusic
.....................................................

Data was successfully printed
Dynamically allocated memory was successfully deallocated

*/


