#include "Movie.h"

Movie::Movie(int r_id, string r_name, double r_duration, string r_genre,int r_rating) : Video(r_id, r_name, r_duration, r_genre,r_rating){}


void Movie::showInfo(){
    cout << "----------- MOVIE -----------" << endl;
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Duration: " << duration << endl;
    cout << "Genre: " << genre << endl;
    cout << "Rating: " << rating << endl;
}

Movie::~Movie(){}
