// #include "movie_factory.h"
// #include "classic.h"
// #include "comedy.h"
// #include "drama.h"
// #include <iostream>
// #include <sstream>
// #include <vector>

// using namespace std;

// // Helper to trim whitespace
// string trim(const string &str) {
//   size_t first = str.find_first_not_of(" ");
//   size_t last = str.find_last_not_of(" ");
//   return str.substr(first, (last - first + 1));
// }

// // Helper to split line by delimiter
// vector<string> split(const string &str, char delimiter) {
//   vector<string> tokens;
//   string token;
//   istringstream stream(str);
//   while (getline(stream, token, delimiter)) {
//     tokens.push_back(trim(token));
//   }
//   return tokens;
// }

// Movie *MovieFactory::createMovie(char genre, const string &dataLine) {
//   vector<string> tokens = split(dataLine, ',');

//   try {
//     if (genre == 'F') {
//       // Format: F, Stock, Director, Title, Year
//       int stock = stoi(tokens[0]);
//       string director = tokens[1];
//       string title = tokens[2];
//       int year = stoi(tokens[3]);
//       return new Comedy(stock, director, title, year);

//     } else if (genre == 'D') {
//       // Format: D, Stock, Director, Title, Year
//       int stock = stoi(tokens[0]);
//       string director = tokens[1];
//       string title = tokens[2];
//       int year = stoi(tokens[3]);
//       return new Drama(stock, director, title, year);

//     } else if (genre == 'C') {
//       // Format: C, Stock, Director, Title, Major Actor First Last, Month
//       Year int stock = stoi(tokens[0]); string director = tokens[1]; string
//       title = tokens[2];

//       istringstream actorDate(tokens[3]);
//       string firstName, lastName;
//       int month, year;
//       actorDate >> firstName >> lastName >> month >> year;

//       string actor = firstName + " " + lastName;
//       return new Classic(stock, director, title, month, year, actor);
//     }
//   } catch (...) {
//     cerr << "Error parsing movie line: " << dataLine << endl;
//     return nullptr;
//   }

//   return nullptr;
// }

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
