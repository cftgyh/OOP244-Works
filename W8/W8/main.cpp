/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	main.cpp
// Version 1.0
// Date	   fall, 2022
// Author	Moona Kanwal
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2023-03-19      Revision, correction
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Media.h"
#include "Video.h"
#include "VRVideo.h"
#include "Animation.h"
using namespace sdds;
using namespace std;
int main() {
    int i;
    // Media* N = new VRVideo(3, "Good");
    Media* BadVideos[4] = { new VRVideo(-1,"bad one"), new VRVideo(100, nullptr), new Animation(-1, 2), new Animation(100, 4) };
    Media* M[2] = { new VRVideo(200,"Head set"), new Animation(100,3) };
    cout << "Nothing should be printed between these two lines" << endl;
    cout << "------------------------------------" << endl;
    for (i = 0; i < 4; cout << *BadVideos[i++]);
    cout << "------------------------------------" << endl;
    for (i = 0; i < 4; delete BadVideos[i++]);
    cout << "Valid Videos: " << endl;
    cout << "------------------------------------" << endl;
    for (i = 0; i < 2; cout << *M[i++] << endl);
    cout << "------------------------------------" << endl;
    cout << "Enter the following:\n>120,Oculus Quest 2\n>";
    cin >> *M[0];
    cout << "The following outputs should be the same" << endl;
    cout << "The correct output:" << endl;
    cout << "VRVideo requires Oculus Quest 2\nVideo Length = 120" << endl;
    cout << "Your output:" << endl;
    cout << *M[0] << endl;
    cout << "Enter the following:\n>500,3\n>";
    cin >> *M[1];
    cout << "The following outputs should be the same" << endl;
    cout << "The correct output:" << endl;
    cout << "Animation is in 3-D\nVideo length = 500" << endl;
    cout << "Your output:" << endl;
    cout << *M[1] << endl;
    delete M[0];
    delete M[1];
    return 0;
}