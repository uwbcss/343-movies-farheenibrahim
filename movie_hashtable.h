#ifndef MOVIEHASHTABLE_H
#define MOVIEHASHTABLE_H

#include "movie.h"
#include <vector>

class MovieHashTable {
private:
  std::vector<Movie *> table[3]; // F = 0, D = 1, C = 2

  static int genreIndex(char genre);

public:
  void insert(Movie *m);
  std::vector<Movie *> &getCategory(char genre);
  Movie *find(char genre, Movie *key);
};

#endif
