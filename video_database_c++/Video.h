#ifndef _VIDEO_H
#define _VIDEO_H

#include <iostream>
using namespace std;

class Video {
protected:
    int ID;
    string name;
    double duration;
    string genre;
    int rating;
public:
    //Video();
    Video(int, string, double, string, int);
    Video(int, string, string, int);
    virtual void showInfo() = 0;
    int getRating();
    void setRating(int);
    string getGenre();
    virtual ~Video();
};

#endif //_VIDEO_H
