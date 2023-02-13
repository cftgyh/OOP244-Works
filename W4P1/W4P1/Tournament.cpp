/***********************************************************************
// OOP244 Workshop 4 p1 : Tournament cpp file
//
// File Tournament.cpp
// Version 1.0
// Date  02/07/2023
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
#include "Tournament.h"
#include "SoccerTeam.h"
using namespace sdds;

using namespace std;
namespace sdds {
	Tournament::Tournament() {
		setEmpty();
	}
	Tournament::Tournament(const char* name, int noOfteam, SoccerTeam* soccer) {
		setTournament(name, noOfteam, soccer);
	}
	Tournament::~Tournament(){
		delete[] m_soccer;
		setEmpty();
	}
	void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer){
		if (name != nullptr && name[0] != '\0' && noOfteam > 0 && soccer->isEmpty())
		{
			m_num = noOfteam;
			m_soccer = new SoccerTeam[noOfteam];

			for (int i = 0; i < noOfteam; i++) {
				m_soccer[i] = soccer[i];
			}
		}
		else
		{
			setEmpty();
		}
	}
	void Tournament::setEmpty() {
		m_name = nullptr;
		m_soccer = nullptr;
		m_num = 0;
	}
	bool Tournament::isEmpty()const {
		return m_name != nullptr 
			&& m_soccer != nullptr
			&& m_num > 0;
	}

	Tournament& Tournament::match(const SoccerTeam* ls) {

		for (int i = 0; i < m_num; i++) {
			if (m_soccer[i].m_noFouls < m_soccer[i+1].m_noFouls) {
				m_soccer[i+1].m_noFouls *= 2;
				m_soccer[i+1].m_fines *= 1.2;
				m_soccer[i].m_golas += 1;
			}
			if (m_soccer[i+1].m_noFouls > MAX_FOUL) {
				m_soccer[i+1].m_noFouls = -1;
			}
		}
		return *this;
	}
	 
	std::ostream& Tournament::display()const {
		;
	}
}

