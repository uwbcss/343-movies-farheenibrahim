#ifndef MOVIE_HASHTABLE_H
#define MOVIE_HASHTABLE_H

#include "movie.h"
#include <stdexcept>
#include <vector>

class MovieHashTable {
public:
  MovieHashTable() = default;
  ~MovieHashTable();

  void insert(Movie *m);
  Movie *find(char genre, Movie *key);
  std::vector<Movie *> &getCategory(char genre);

private:
  static int genreIndex(char genre);
  std::vector<Movie *>
      table[3]; 
};

#endif 
