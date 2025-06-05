#include "movie_hashtable.h"
#include <iostream>
using namespace std;

int MovieHashTable::genreIndex(char genre) {
  switch (genre) {
  case 'F':
    return 0;
  case 'D':
    return 1;
  case 'C':
    return 2;
  default:
    return -1;
  }
}

void MovieHashTable::insert(Movie *m) {
  int idx = genreIndex(m->getGenre());
  if (idx == -1) {
    return;
  }

  auto &vec = table[idx];
  for (Movie *existing : vec) {
    if (existing->equals(*m)) {
      delete m;
      return;
    }
  }
  vec.push_back(m);
}

vector<Movie *> &MovieHashTable::getCategory(char genre) {
  int idx = genreIndex(genre);
  if (idx == -1) {
    throw invalid_argument("Invalid genre");
  }
  return table[idx];
}

Movie *MovieHashTable::find(char genre, Movie *key) {
  int idx = genreIndex(genre);
  if (idx == -1) {
    return nullptr;
  }

  for (Movie *m : table[idx]) {
    if (m->equals(*key)) {
      return m;
    }
  }
  return nullptr;
}
