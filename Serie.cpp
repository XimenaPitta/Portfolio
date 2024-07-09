#include "Serie.h"
#include <iostream>
using namespace std;


Serie::Serie(int r_id, string r_name, string r_genre, int r_rating):Video(r_id,r_name,r_genre,r_rating){}


void Serie::agregarEpisodio(Episode *episode){
  episodes.push_back(episode);
}

vector<Episode*>& Serie::getEpisodes(){
  return episodes;
}


void Serie::showInfo(){
  cout << "----------- SERIE -----------" << endl;
  cout << "ID: " << ID << endl;
  cout << "Name: " << name << endl;
  cout << "Genre: " << genre << endl;
  cout << "Rating: " << rating << endl;
}

int Serie::getID(){
  return ID;
}

string Serie::getName(){
  return name;
}

Serie::~Serie(){}
