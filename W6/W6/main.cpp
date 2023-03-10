/***********************************************************************
// OOP244 Workshop 6 Part1: Classes with Resource
// File main.cpp
// Version 1.0
// Date	2023/02
// Author Fardad Soleimanloo
// Description
// Tests Numbers module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <fstream>
#include "Numbers.h"
using namespace sdds;
using namespace std;
int testNo = 1;

void pause(const char* prompt = nullptr);
void startTest(const char* desc = nullptr);
void endTest();
void resetFile(const char* fname);
void displayFile(const char* fname, bool removeNewline = true);
void displayList(Numbers N);
void test1();
void test2();
void test3();

int main() {
    resetFile("numbers.txt");
    test1();
    displayFile("numbers.txt");
    endTest();
    test2();
    displayFile("numbers.txt");
    endTest();
    test3();
    displayFile("numbers.txt");
    endTest();
    displayFile("add.txt");
    displayFile("output.txt", false);
    return 0;
}

void test1() {
    startTest("Testing One arg. constructor, operator<<,sort() and save()");
    Numbers N("numbers.txt");
    cout << N << endl;
    N.sort();
    cout << "Sorted " << N << endl;
}

void test2() {
    startTest("Testing Validation, Load, copy assignment and save\n"
        "and also using copy constructor");
    Numbers N("numbers.txt");
    Numbers M(N);
    Numbers L("badFileFormat.txt");
    Numbers BAD("BadFileName.txt");
    cout << "N:" << endl << N << endl
        << "M:" << endl << M << endl
        << "L:" << endl << L << endl
        << "Bad:" << endl << BAD << endl;
    cout << "displayList(N):" << endl;
    displayList(N);
    pause(">>>operator+= and copy assignment<<<");
    M += 1000;
    L = M;
    N = L;
    cout << "N:" << endl << N << endl
        << "M:" << endl << M << endl
        << "L:" << endl << L << endl;
    pause(">>>Copying an empty object<<<");
    Numbers NB(BAD);
    M = BAD;
    cout << "NB:" << endl << NB << endl
        << "M:" << endl << M << endl;
}

void test3() {
    startTest("In this test we use your insertion and extraction operators to do\n"
        "File IO. This makes sure your implementation is done correctly\n"
        "using the reference of istream and ostream and NOT cin and cout");
    ifstream addnum("add.txt");
    ofstream output("output.txt");
    Numbers N("numbers.txt");
    addnum >> N;
    addnum >> N;
    addnum >> N;
    N.sort();
    cout << "Sorted " << N << endl;
    output << N << endl;
}

void pause(const char* prompt) {
    prompt&& cout << prompt << endl;
    cout << "Press enter to continue...";
    cin.ignore(10000, '\n');
    cout << endl;
}
void startTest(const char* desc) {
    cout << testNo << ">" << endl << "Test";
    for (int i = 0; i < 36; i++) cout << "." << testNo;
    desc&& cout << endl << desc << endl;
    for (int i = 0; i < 38; i++) cout << "..";
    cout << endl;
}
void endTest() {
    cout << "End Test";
    for (int i = 0; i < 28; i++) cout << "^" << testNo;
    cout << endl;
    testNo++;
    pause();
}

void resetFile(const char* fname) {
    ofstream f(fname);
    f.setf(ios::fixed);
    f.precision(2);
    f << 6.2 << endl << 12.2 << endl << 3.2 << endl << 34.1 << endl << 1.3 << endl << 40.1 << endl << -1.5 << endl;
}
void displayFile(const char* fname, bool removeNewline) {
    ifstream f(fname);
    char ch;
    cout << endl << "Content of \"" << fname << "\"" << endl
        << "****************************************************************************" << endl;
    while (f.get(ch)) {
        if (ch == '\n' && removeNewline)
            cout << "<\\n>";
        else {
            cout << ch;
        }
    }
    cout << endl << "****************************************************************************" << endl;
}
void displayList(Numbers N) {
    cout << N << endl;
}