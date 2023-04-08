/***********************************************************************
// OOP244 Workshop 10:
// File	Displayable.cpp
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
#include "Displayable.h"
namespace sict {
    std::ostream& operator<<(std::ostream& os, const Displayable& D) {
        return D.display(os);
    }
}
