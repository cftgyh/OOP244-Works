/***********************************************************************
// OOP244 Workshop w9 p1:  Contact cpp file
//
// File Contact.cpp
// Version 1.0
// Date  03/28/2023
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;

namespace sdds {
    Contact::Contact():Person()
    {
        m_address = nullptr;
        m_city = nullptr;
        m_province[0] = '\0';
        m_postCode[0] = '\0';
    }
    Contact::~Contact() // destructor doesn't need to deallo parents' memory
    {
        if (m_address) {
            delete[] m_address;
        }
        if (m_city) {
            delete[] m_city;
        }
        m_address = nullptr;
        m_city = nullptr;
    }
    bool Contact::valid() const
    {
        return m_address != nullptr;
    }
    // rule of three
    Contact::Contact(const Contact& C) // : Person(C)
    {
        m_address = nullptr;
        m_city = nullptr;
        m_province[0] = '\0';
        m_postCode[0] = '\0';
        operator=(C);
    }
    Contact& Contact::operator=(const Contact& C)
    {
        if (this != &C) {
            Person::operator=(C);
            strcpy(m_province, C.m_province);
            strcpy(m_postCode, C.m_postCode);
            if(m_address) delete[] m_address;
            if(m_city) delete[] m_city;
            if (C.m_address != nullptr) m_address = U.aloCopy(strlen(C.m_address), C.m_address);
            else m_address = nullptr;
            if (C.m_city != nullptr) m_city = U.aloCopy(strlen(C.m_city), C.m_city);
            else m_city = nullptr;
        }
        return *this;
    }
    std::istream& Contact::read(std::istream& istr)
    {
        char address[100]{};
        char city[100]{};
        char province[100]{};
        char postCode[100]{};
        m_address = nullptr;
        m_city = nullptr;
        m_province[0] = '\0';
        m_postCode[0] = '\0';

        Person::read(istr);
        istr.getline(address, 100, ',');// bad address ",North York,ON,M3J3M6"
        istr.getline(city, 100, ',');   // bad city "70 the pond road,,ON,M3J3M6"
        istr.getline(province,100,',');   // bad province "70 the pond road,North York,ONT,M3J3M6"
        istr >> postCode; // bad postcode "70 the pond road,North York,ON,M3J 3M6"
    
        if (!istr.fail()) {
            if (strlen(address) == 0 || strlen(city) == 0 || strlen(province) != 2 || strlen(postCode) != 6) {
                m_address = nullptr;
                cin.setstate(ios::failbit);
            }
            else {
                if (m_address) delete[] m_address;
                m_address = U.aloCopy(strlen(address), address);
                if (m_city) delete[] m_city;
                m_city = U.aloCopy(strlen(city), city);
                strcpy(m_province, province);
                strcpy(m_postCode, postCode);
            }
        }
        return istr;
    }
    std::ifstream& Contact::load(std::ifstream& ifst)
    {
        char address[100]{};
        char city[100]{};
        char province[100]{};
        char postCode[100]{};
        m_address = nullptr;
        m_city = nullptr;
        m_province[0] = '\0';
        m_postCode[0] = '\0';

        Person::load(ifst);
        ifst.getline(address, 100, ',');
        ifst.getline(city, 100, ',');  
        ifst.getline(province, 100, ',');   
        ifst >> postCode; 
        
        if (!ifst.fail()) {
            /*if (strlen(address) == 0 || strlen(city) == 0 || strlen(province) != 2 || strlen(postCode) != 6) {
                m_address = nullptr;
                cin.setstate(ios::failbit);
            }
            else {*/
                if (m_address) delete[] m_address;
                m_address = U.aloCopy(strlen(address), address);
                if (m_city) delete[] m_city;
                m_city = U.aloCopy(strlen(city), city);
                strcpy(m_province, province);
                strcpy(m_postCode, postCode);
            //}
        }
        return ifst;
    }
    std::ostream& Contact::display(std::ostream& ostr) const
    {
        if (m_address != nullptr) {
            Person::display(ostr);
            ostr << endl;
            ostr << m_address << endl;
            ostr << m_city << " " << m_province << endl;
            for (int i = 0; i < 3; i++) {
                ostr << m_postCode[i];
            }
            ostr << " ";
            for (int i = 3; i < 6; i++) {
                ostr << m_postCode[i];
            }
            ostr << endl;
        }
        return ostr;
    }
}