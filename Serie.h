#ifndef _SERIE_H
#define _SERIE_H

#include "Video.h"
#include "Episode.h"
#include <vector>
using namespace std;

class Episode;

class Serie : public Video {
private:
  vector<Episode*> episodes;
public:
  Serie(int, string, string, int);
  ~Serie();
  void agregarEpisodio(Episode* episodio);
  vector<Episode*>& getEpisodes();
  void showInfo();
  int getID();
  string getName();

};

#endif //_SERIE_H
