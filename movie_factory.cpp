#include "movie_factory.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
// Returns a reference to the static registry that maps genre characters
// (e.g., 'F' for Comedy, 'D' for Drama, 'C' for Classic) to Creator functions.
// The registry is initialized once and shared across the program.
unordered_map<char, MovieFactory::Creator> &MovieFactory::getRegistry() {
  static unordered_map<char, Creator> registry;
  return registry;
}
// Registers a Creator function for a specific genre code.
// This is typically called inside the anonymous namespace in each genre class
// (e.g., Drama, Comedy).
void MovieFactory::registerGenre(char genre, Creator creator) {
  getRegistry()[genre] = creator;
}

// Creates a Movie object by looking up the appropriate factory function
// based on the genre character and calling it with the dataLine string.
// If the genre is not registered, prints an error and returns nullptr.
Movie *MovieFactory::createMovie(char genre, const string &dataLine) {
  auto it = getRegistry().find(genre);
  if (it != getRegistry().end()) {
    return it->second(dataLine);
  }
  // Invalid or unregistered genre: notify and discard
  cerr << "Unknown movie type: " << genre << ", discarding line: " << dataLine
       << endl;
  return nullptr;
}
