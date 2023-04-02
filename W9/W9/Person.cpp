/***********************************************************************
// OOP244 Workshop 9:
// File	Person.cpp
// Version 1.0
// Date	Winter of 2023
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Tools.h"
#include "Person.h"

namespace sdds {
    Person::Person() {}
    Person::Person(const Person& copyFrom) {
        operator=(copyFrom);
    }
    Person& Person::operator=(const Person& RightOperand) {
        if (this != &RightOperand) {
            delAlloCopy(m_name, RightOperand.m_name);
            delAlloCopy(m_lastName, RightOperand.m_lastName);
            delAlloCopy(m_middleName, RightOperand.m_middleName);
        }
        return *this;
    }
    Person::~Person() {
        ~*this;
    }
    std::istream& Person::read(std::istream& istr) {
        ~*this;
        m_name = dynRead(istr, ',');
        m_middleName = dynRead(istr, ',');
        m_lastName = dynRead(istr);
        if (istr.fail()) ~*this;
        return istr;
    }
    std::ostream& Person::write(std::ostream& ostr) const {
        if (*this) {
            ostr << m_name;
            if (m_middleName && m_middleName[0]) {
                ostr << " " << m_middleName;
            }
            ostr << " " << m_lastName;
        }
        return ostr;
    }
    Person::operator bool() const {
        return m_name && m_name[0] && m_lastName && m_lastName[0];
    }

    void Person::operator~() {
        delete[] m_name;
        delete[] m_lastName;
        delete[] m_middleName;
        m_name = m_lastName = m_middleName = nullptr;
    }

    std::istream& operator>>(std::istream& leftOperand, Person& rightOperand) {
        return rightOperand.read(leftOperand);
    }

    std::ostream& operator<<(std::ostream& leftOperand, const Person& rightOperand) {
        return rightOperand.write(leftOperand);
    }

}
