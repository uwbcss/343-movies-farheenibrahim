#include "drama.h"
#include "movie_factory.h"
#include <iostream>
#include <sstream>

using namespace std;
// Constructor: Initializes a Drama object with stock, director, title, and year
Drama::Drama(int stock, const string &director, const string &title, int year)
    : Movie(stock, director, title, year) {}

// Displays drama movie details in a formatted line
void Drama::display() const {
  cout << director << ", " << title << ", " << year << " (" << stock
       << ") - Drama" << endl;
}
// Compares this Drama with another Movie to check for equality
// Returns true if the other movie is also Drama and has the same director and title
bool Drama::equals(const Movie &other) const {
  const Drama *d = dynamic_cast<const Drama *>(&other);
  if (d != nullptr) {
    return director == d->director && title == d->title;
  }
  return false;
}
// Defines sorting behavior: compares director first, then title
// Used when storing or ordering dramas in inventory
bool Drama::lessThan(const Movie &other) const {
  const Drama *d = dynamic_cast<const Drama *>(&other);
  if (d == nullptr) {
    return false;
  }
  if (director != d->director) {
    return director < d->director;
  }
  return title < d->title;
}
// Returns the genre code for Drama movies
char Drama::getGenre() const { return 'D'; }

// Creates a deep copy of this Drama object
// Used when storing transactions in customer history
Movie *Drama::clone() const { return new Drama(*this); }

// Self-registration
// Automatically registers the Drama genre type ('D') with MovieFactory
// Allows MovieFactory to create Drama objects based on input line format
namespace {
bool registered = []() {
  MovieFactory::registerGenre('D', [](const string &line) -> Movie * {
    istringstream ss(line);
    int stock;
    int year;
    string director;
    string title;

    ss >> stock;
    ss.ignore();
    getline(ss, director, ',');
    getline(ss, title, ',');
    ss >> year;
    // Trim leading spaces from fields and create Drama instance
    return new Drama(stock, director.substr(1), title.substr(1), year);
  });
  return true;
}();
} // namespace
