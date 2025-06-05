#include "movie_hashtable.h"
#include <iostream>

using namespace std;
// Helper function to map genre character to table index.
// 'F' (Comedy) → 0, 'D' (Drama) → 1, 'C' (Classic) → 2.
// Returns -1 for invalid genres.
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
// Destructor: cleans up all dynamically allocated Movie objects
// Iterates through each genre's vector and deletes each Movie pointer.
MovieHashTable::~MovieHashTable() {
  for (int i = 0; i < 3; ++i) {
    for (Movie *m : table[i]) {
      delete m; // avoid duplicates by deleting the new pointer
    }
  }
}

// Inserts a movie into the correct genre vector based on genre code.
// Prevents duplicate movies by checking with equals() before inserting.
// Deletes the passed-in pointer if it's a duplicate.
void MovieHashTable::insert(Movie *m) {
  int idx = genreIndex(m->getGenre());
  if (idx == -1) {
    return;
  }

  auto &vec = table[idx];
  for (Movie *existing : vec) {
    if (existing->equals(*m)) {
      delete m; // don't insert duplicates
      return;
    }
  }
  vec.push_back(m);
}
// Returns the vector of movies for a given genre.
// Throws an exception if the genre is invalid.
vector<Movie *> &MovieHashTable::getCategory(char genre) {
  int idx = genreIndex(genre);
  if (idx == -1) {
    throw invalid_argument("Invalid genre");
  }
  return table[idx];
}
// Finds and returns a pointer to a Movie object that matches the given key.
// Uses the equals() method to compare.
// Returns nullptr if not found or if genre is invalid.
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
