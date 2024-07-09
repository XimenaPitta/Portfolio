#include "Video.h"
#include <iostream>
using namespace std;



Video::Video(int r_id, string r_name, double r_duration, string r_genre, int r_rating){
    ID = r_id;
    name = r_name;
    duration = r_duration;
    genre = r_genre;
    rating = r_rating;
}

Video::Video(int r_id, string r_name, string r_genre, int r_rating){
    ID = r_id;
    name = r_name;
    genre = r_genre;
    rating = r_rating;
}

int Video::getRating(){
    return rating;
}

void Video::setRating(int r_rating){
    rating = r_rating;
}

string Video::getGenre(){
    return genre;
}


void Video::showInfo(){}

Video::~Video(){}