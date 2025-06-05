// #ifndef MOVIE_FACTORY_H
// #define MOVIE_FACTORY_H

// #include "movie.h"
// #include <string>

// class MovieFactory {
// public:
//   static Movie *createMovie(char genre, const std::string &dataLine);
// };

// #endif

#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

#include "movie.h"
#include <functional>
#include <string>
#include <unordered_map>

class MovieFactory {
public:
  using Creator = std::function<Movie *(const std::string &)>;
  static Movie *createMovie(char genre, const std::string &dataLine);
  static void registerGenre(char genre, Creator creator);

private:
  static std::unordered_map<char, Creator> &getRegistry();
};

#endif
