// #include "comedy.h"
// #include <iostream>
// using namespace std;

// Comedy::Comedy(int stock, string director, string title, int year)
//     : Movie(stock, director, title, year) {}

// void Comedy::display() const {
//   cout << getTitle() << ", " << getYear() << ", " << getDirector() << " ("
//        << getStock() << ") - Comedy" << endl;
// }

// bool Comedy::equals(const Movie &other) const {
//   const Comedy *c = dynamic_cast<const Comedy *>(&other);
//   return c && title == c->title && year == c->year;
// }

// bool Comedy::lessThan(const Movie &other) const {
//   const Comedy *c = dynamic_cast<const Comedy *>(&other);
//   if (!c)
//     return false;
//   if (title != c->title)
//     return title < c->title;
//   return year < c->year;
// }

// char Comedy::getGenre() const { return 'F'; }

// Movie *Comedy::clone() const { return new Comedy(*this); }

// int Comedy::getYear() const { return year; }

// string Comedy::getTitle() const { return title; }

#include "comedy.h"
#include "movie_factory.h"
#include <iostream>
#include <sstream>

using namespace std;

Comedy::Comedy(int stock, const std::string &director, const std::string &title,
               int year)
    : Movie(stock, director, title, year) {}

void Comedy::display() const {
  cout << title << ", " << year << ", " << director << " (" << stock
       << ") - Comedy" << endl;
}

bool Comedy::equals(const Movie &other) const {
  const Comedy *c = dynamic_cast<const Comedy *>(&other);
  return c != nullptr && title == c->title && year == c->year;
}

bool Comedy::lessThan(const Movie &other) const {
  const Comedy *c = dynamic_cast<const Comedy *>(&other);
  if (c == nullptr) {
    return false;
  }

  if (title != c->title) {
    return title < c->title;
  }
  return year < c->year;
}

char Comedy::getGenre() const { return 'F'; }

Movie *Comedy::clone() const { return new Comedy(*this); }

int Comedy::getYear() const { return year; }

std::string Comedy::getTitle() const { return title; }

// Self-registration
namespace {
bool registered = []() {
  MovieFactory::registerGenre('F', [](const string &line) -> Movie * {
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

    return new Comedy(stock, director.substr(1), title.substr(1), year);
  });
  return true;
}();
} // namespace
