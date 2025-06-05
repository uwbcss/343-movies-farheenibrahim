#include "comedy.h"
#include "movie_factory.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Constructor
Comedy::Comedy(int stock, const string &director, const string &title, int year)
    : Movie(stock, director, title, year) {}

// Display format
void Comedy::display() const {
  cout << title << ", " << year << ", " << director << " (" << stock
       << ") - Comedy" << endl;
}

// Equality comparison for sorting and matching
bool Comedy::equals(const Movie &other) const {
  const Comedy *c = dynamic_cast<const Comedy *>(&other);
  return c != nullptr && title == c->title && year == c->year;
}

// Ordering for BST/Hash
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

// Genre getter
char Comedy::getGenre() const { return 'F'; }

// Clone for copy
Movie *Comedy::clone() const { return new Comedy(*this); }

// Getters
int Comedy::getYear() const { return year; }

string Comedy::getTitle() const { return title; }

// ----------- Self-registration Lambda --------------
namespace {
bool registered = []() {
  MovieFactory::registerGenre('F', [](const string &line) -> Movie * {
    vector<string> tokens;
    string token;
    istringstream stream(line);
    while (getline(stream, token, ',')) {
      size_t start = token.find_first_not_of(' ');
      size_t end = token.find_last_not_of(' ');
      token = (start == string::npos || end == string::npos)
                  ? ""
                  : token.substr(start, end - start + 1);
      tokens.push_back(token);
    }

    if (tokens.size() < 4) {
      cerr << "Comedy parsing failed: " << line << endl;
      return nullptr;
    }

    try {
      int stock = stoi(tokens[0]);
      string director = tokens[1];
      string title = tokens[2];
      int year = stoi(tokens[3]);

      return new Comedy(stock, director, title, year);
    } catch (...) {
      cerr << "Comedy parse error: " << line << endl;
      return nullptr;
    }
  });
  return true;
}();
} // namespace
