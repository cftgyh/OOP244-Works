/***********************************************************************
// OOP244 Workshop 10:
// File	Displayable.h
// Version 1.0
// Date	Winter of 2023
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Data            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#ifndef SICT_DISPLAYABLE_H_
#define SICT_DISPLAYABLE_H_
namespace sict {
    class Displayable {
    public:
        virtual std::ostream& display(std::ostream& os)const = 0;
    };

    std::ostream& operator<<(std::ostream& os, const Displayable& D);
}

#endif
