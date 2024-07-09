// Episodio.h
#ifndef _EPISODE_H
#define _EPISODE_H
#include <iostream>
using namespace std;
#include <string>
#include "Serie.h"

class Episode {
private:
    int ID_Serie;
    string ID_Episode;
    string name;
    double duration;
    int rating;
    int number_Season;


public:
    Episode(int, string, string, double, int, int);
    int getIDserie();
    string getIDepisode();
    string getName();
    double getDuration();
    int getRating();
    int getNumber_Season();
    void showInfoEpisode();

    ~Episode();


};

#endif //_EPISODE_H