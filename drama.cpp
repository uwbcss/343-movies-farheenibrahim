#include "drama.h"
#include "movie_factory.h"
#include <iostream>
#include <sstream>

using namespace std;

Drama::Drama(int stock, const string &director, const string &title, int year)
    : Movie(stock, director, title, year) {}

void Drama::display() const {
  cout << director << ", " << title << ", " << year << " (" << stock
       << ") - Drama" << endl;
}

bool Drama::equals(const Movie &other) const {
  const Drama *d = dynamic_cast<const Drama *>(&other);
  if (d != nullptr) {
    return director == d->director && title == d->title;
  }
  return false;
}

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

char Drama::getGenre() const { return 'D'; }

Movie *Drama::clone() const { return new Drama(*this); }

// Self-registration
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

    return new Drama(stock, director.substr(1), title.substr(1), year);
  });
  return true;
}();
} // namespace
