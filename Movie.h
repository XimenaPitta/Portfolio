#ifndef _MOVIE_H
#define _MOVIE_H


#include <iostream>
using namespace std;
#include "Video.h"


class Movie : public Video {
public:
    Movie(int, string, double, string, int);
    void showInfo();
    ~Movie();

};


#endif //_MOVIE_H