/***********************************************************************
// Workshop 1 p2: UI header file
//
// File  UI.h
// Version 1.0
// Date  winter 2023
// Author:		Xinyu Zhang
// Student No#: 174538215
// Email:		xzhang399@myseneca.ca
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*
holding User interaction functions' header.
*/
#pragma once
#ifndef SDDS_UI_H
#define SDDS_UI_H

namespace sdds
{
	void displayStudentInfo(struct GPA stdInfo[]);
	void displayOneInfo(int i, int position, struct GPA g[]);
}
#endif // !SDDS_UI_H