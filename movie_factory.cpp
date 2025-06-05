#include "movie_factory.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

unordered_map<char, MovieFactory::Creator> &MovieFactory::getRegistry() {
  static unordered_map<char, Creator> registry;
  return registry;
}

void MovieFactory::registerGenre(char genre, Creator creator) {
  getRegistry()[genre] = creator;
}

Movie *MovieFactory::createMovie(char genre, const string &dataLine) {
  auto it = getRegistry().find(genre);
  if (it != getRegistry().end()) {
    return it->second(dataLine);
  }
  cerr << "Unknown movie type: " << genre << ", discarding line: " << dataLine
       << endl;
  return nullptr;
}
