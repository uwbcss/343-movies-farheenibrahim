#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

#include "movie.h"
#include <functional>
#include <string>
#include <unordered_map>

class MovieFactory {
public:
  using Creator = std::function<Movie *(const std::string &)>;
  // Creates a Movie object of the specified genre using the provided data line
  // Calls the appropriate registered Creator function based on genre
  static Movie *createMovie(char genre, const std::string &dataLine);
  // Registers a Creator function for a specific genre character
  // Enables dynamic creation of Movie objects without if/else chains
  static void registerGenre(char genre, Creator creator);

private:
  // Returns a reference to the static registry map that stores genre -> Creator
  // mappings
  static std::unordered_map<char, Creator> &getRegistry();
};

#endif
