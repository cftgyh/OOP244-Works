#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef SDDS_FILE_H
#define SDDS_FILE_H //#define NAMESPACE_HEADERFILENAME_H

namespace sdds
{
    bool openFile(const char filename[]);
    void closeFile();
    bool readTitle(char title[]);
    bool readYear(int* year);
    bool readMovieRating(char rating[]);
    bool readDuration(int* duration);
    bool readGenres(char genres[][11]);
    bool readConsumerRating(float* rating);
    void flushkeys();
    bool yes();
}


#endif // !SDDS_FILE_H
