#pragma once
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds
{
	bool loadStudentData(const char* studentFile, struct GPA stdInfo[]);
	void sortStudentData(struct GPA stdInfo[]);
}
#endif // !SDDS_FILE_H