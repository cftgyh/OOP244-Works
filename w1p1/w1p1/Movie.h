#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H //#define NAMESPACE_HEADERFILENAME_H

struct Movie {
    char m_title[128];
    int m_year;
    char m_rating[6];
    int m_duration;
    char m_genres[10][11];
    float m_consumerRating;
};
namespace sdds
{
    bool loadMovies();
    bool hasGenre(const Movie* mvp, const char genre[]);
    void displayMovie(const Movie* mvp);
    void displayMoviesWithGenre(const char genre[]);
}

#endif