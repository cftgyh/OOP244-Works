/***********************************************************************
// Workshop 1 p2: File header file
//
// File  File.h
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
holding file related functions' header.
*/
#pragma once
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds
{
	bool loadStudentData(const char* studentFile, struct GPA stdInfo[]);
	void sortStudentData(struct GPA stdInfo[]);
}
#endif // !SDDS_FILE_H