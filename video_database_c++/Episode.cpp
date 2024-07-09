#include "Episode.h"

Episode::Episode(int r_idSerie, string r_idEp, string r_name, double r_duration, int r_rating, int r_numSeason){
    ID_Serie = r_idSerie;
    ID_Episode = r_idEp;
    name = r_name;
    duration = r_duration;
    rating = r_rating;
    number_Season = r_numSeason;
}


int Episode::getIDserie(){
  return ID_Serie;
}

string Episode::getIDepisode(){
  return ID_Episode;
}

string Episode::getName(){
  return name;
}

double Episode::getDuration(){
  return duration;
}

int Episode::getRating(){
  return rating;
}

int Episode::getNumber_Season(){
  return number_Season;
}

void Episode::showInfoEpisode(){
  cout << "----------- episodio -----------" << endl;
  cout << "Name: " << name << " | " << "Duration: " << duration << " | " << "Rating: " << rating << " | " << "Season: " << number_Season << endl;
  
}

Episode::~Episode(){}