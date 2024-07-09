#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include "Movie.h"
#include "Serie.h"
#include "Episode.h"
using namespace std;

int main() {

    // EXTRAER DATOS DE ARCHIVOS .TXT Y CONVERTIRLOS A OBJETOS
    // 1. Lectura de archivos .txt para películas (herencia video)
    ifstream file("Peliculas.txt");
    vector<Movie*> movies;
    map<string, vector<Movie*>> genreMap;
    map<double, vector<Movie*>> ratingMap;

    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return 1; // Return an error code
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        int id;
        string name, genre;
        //double duration, rating;
        double duration;
        int rating;

        // Resto del código para leer y crear objetos Movie...
        getline(ss, token, ',');
        id = stoi(token);

        getline(ss, name, ',');
        getline(ss, token, ',');
        //cout << "Token: " << token << endl; DURATION MOVIE CORRECTO!
        duration = stod(token);

        getline(ss, genre, ',');
        getline(ss, token, ',');
        // cout << "Token: " << token << endl; RATING MOVIE CORRECTO!
        rating = stoi (token);

        /*cout << "ID: " << id << ", Name: " << name << ", Duration: " << duration << ", Genre: " << genre << ", Rating: " << rating << endl;*/

        Movie* movie = new Movie(id, name, duration, genre, rating);
        movies.push_back(movie);

        genreMap[genre].push_back(movie);

        ratingMap[rating].push_back(movie);

    }

    file.close();


    // 2. Lectura de archivos .txt para serie (herencia video) y episodio (composición serie)
    ifstream seriesFile("Series.txt");
    ifstream episodesFile("Episodios.txt");

    vector<Serie*> series;
    map<string, vector<Serie*>> genreMapSerie;
    map<double, vector<Serie*>> ratingMapSerie;

    if (!seriesFile.is_open() || !episodesFile.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return 1; // Return an error code
    }

    string line2;
    while (getline(seriesFile, line2)) {
        stringstream ss(line2);
        string token;
        int id = 0;
        string name, genre;
        int rating;

        getline(ss, token, ',');
        id = stoi(token);


        getline(ss, name, ',');
        getline(ss, genre, ',');
        getline(ss, token, ',');
        rating = stoi(token);

        Serie* serie = new Serie(id, name, genre, rating);
        series.push_back(serie);

        genreMapSerie[genre].push_back(serie);
        ratingMapSerie[rating].push_back(serie);
    }

    seriesFile.close();

    // Leer y asignar episodios a las series
    while (getline(episodesFile, line2)) {
        stringstream ss(line2);
        string token;
        int idSerie, numSeason, rating;
        string idEpisode, name;
        double duration;
        //int rating;

        // Leer datos del episodio desde el archivo
        getline(ss, token, ',');
        idSerie = stoi(token);

        getline(ss, idEpisode, ',');
        getline(ss, name, ',');
        getline(ss, token, ',');
        duration = stod(token);
        /* PARA ATRAPAR ERRORES EN LÍNEAS DEL TEXTO!!!
          cout << "Token: " << token << endl;
          try { duration = stod(token);
               } catch (const std::invalid_argument& e) {
                   cout << "Error: Token no es un número entero válido." << endl;
               }*/


        getline(ss, token, ',');
        rating = stoi(token);

        getline(ss, token, ',');
        numSeason = stoi(token);

        Episode* episode = new Episode(idSerie, idEpisode, name, duration, rating, numSeason);

        for (Serie* serie : series) {
            if (serie->getID() == idSerie) {
                serie->agregarEpisodio(episode);
                break; // Una vez que se asigna el episodio, se sale del ciclo
            }
        }
    }

    episodesFile.close();

  
    // MENÚ INTERACTIVO
    bool salir = false;

  string nombreSerieBuscar;
  int rating_deseado_ep;
  int idSerieBuscar = 0;
  
    while (!salir) {
        int opcion;

        cout << "Bienvenido al sistema de clasificación de videos" << endl;
        cout << "1. Ver catálogo completo" << endl;
        cout << "2. Buscar películas y series con cierta calificación" << endl;
        cout << "3. Buscar películas y series con cierto género" << endl;
        cout << "4. Buscar episodios de una determinada serie con una calificación determinada" << endl;
        cout << "5. Salir" << endl;

        cout << "Ingrese una opción: ";
        cin >> opcion;
        cout << "" << endl;
      
switch (opcion) {
    case 1:
        // Mostrar catálogo completo
        cout << "Mostrando catálogo completo" << endl;

        for (Movie* movie : movies){
            movie->showInfo();
            cout << "" << endl;
            cout << "" << endl;
        }

        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;

        for (Serie* serie : series) {
            serie->showInfo();
            cout << "" << endl;
            cout << "" << endl;

            for (Episode* episodio : serie -> getEpisodes()){
                episodio->showInfoEpisode();
                cout << "" << endl;
            }

            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "" << endl;
        }

        break;

    case 2:
        // Buscar películas y series con cierta calificación
        int rating_deseado;
        cout << "Ingresa el rating (1-5) del video que deseas buscar: ";
        cin >> rating_deseado;

        if (rating_deseado < 1 || rating_deseado > 5) {
            cout << "Rating inválido. Debe estar entre 1 y 5." << endl;
        } else {
            cout << "Videos con rating " << rating_deseado << ":";
            for (Movie* movie : movies) {
                if (movie->getRating() == rating_deseado) {
                    movie->showInfo();
                }
            }
            for (Serie* serie : series) {
              if (serie->getRating() == rating_deseado) {
              serie->showInfo();
            }
        }
        }

        break;
    case 3:
        // Buscar películas y series con cierto género
        {
            string genero_deseado;
            cout << "---- Menú de géneros ----" << endl;
            cout << "Comedia" << endl;
            cout << "Drama" << endl;
            cout << "Misterio" << endl;
            cout << "Crimen" << endl;
            cout << "Terror" << endl;
            cout << "Romance" << endl;
            cout << "Por favor ingresa el género del video que deseas buscar: ";
            cin >> genero_deseado;

            cout << "Videos de género " << genero_deseado << ":";
            for (Movie* movie : movies) {
                if (movie->getGenre() == genero_deseado) {
                    movie->showInfo();
                }
            }

            for (Serie* serie : series) {
                if (serie->getGenre() == genero_deseado) {
                    serie->showInfo();
                }
            }
        }
        break;
    case 4:
        // Buscar episodios de una determinada serie con una calificación determinada
      cout << "Ingrese el nombre de la serie que desea buscar: ";
      cin.ignore(); // Limpiar el buffer del teclado antes de getline
      getline(cin, nombreSerieBuscar);
      cout << "Ingrese el rating deseado para los episodios (1-5): ";
      cin >> rating_deseado_ep;

      // ID de la serie por su nombre
      for (Serie* serie : series) {
          if (serie->getName() == nombreSerieBuscar) {
              idSerieBuscar = serie->getID();
              break;
          }
      }

      if (idSerieBuscar == 0) {
          cout << "No se encontró ninguna serie con el nombre '" << nombreSerieBuscar << "'." << endl;
      } else {
          // Buscar episodios de la serie con el ID encontrado
          for (Serie* serie : series) {
              if (serie->getID() == idSerieBuscar) {
                  cout << "Episodios de la serie '" << serie->getName() << "' con rating " << rating_deseado_ep << ":" << endl;
                  for (Episode* episodio : serie->getEpisodes()) {
                      if (episodio->getRating() == rating_deseado_ep) {
                          episodio->showInfoEpisode();
                      }
                  }
                  break;
              }
          }
      }


        break;
    case 5:
        // Salir
        cout << "Fin del sistema de clasificación de videos." << endl;
        salir = true;
        break;
    default:
        cout << "Opción inválida. Ingrese la opción nuevamente." << endl;
        break;
}
    }
    return 0;
}