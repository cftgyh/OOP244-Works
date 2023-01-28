/*
OOP244 Workshop 2 p1: Tools.cpp file

Name: Xinyu Zhang
Email: xzhang399@myseneca.ca
Student ID: 174538215
Date: 2023-01-25
I have done all the coding by myself and
only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Tools.h"
#include "Package.h"

FILE* fp;

namespace sdds {
    int openFile_r(const char filename[]) 
    { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }

    int noOfTraces() 
    {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }

    // To Do: read functions (4 overloaded read functions)
  
    // read char type 
    int read(char& dayOfWeek) {
        return fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &dayOfWeek) == 1;
    }

    // read int type
    int read(int& value) {
        return fscanf(fp, "%d,", &value) == 1;
    }

    // read double type
    int read(double& timeInHours) {
        return fscanf(fp, "%lf,", &timeInHours) == 1;
    }

    // read char* type
    int read(char* pName) {
        return fscanf(fp, "%60[^\n]\n", pName) == 1;
    }

    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }
    
    void strCpy(char* str1, const char* str2) { // Fully provided 
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }
}