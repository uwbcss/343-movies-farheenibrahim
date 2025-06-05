#include "classic.h"
#include "movie_factory.h"
#include <iostream>
#include <sstream>

using namespace std;

Classic::Classic(int stock, const std::string &director,
                 const std::string &title, int month, int year,
                 const std::string &actor)
    : Movie(stock, director, title, year), month(month), actor(actor) {}

void Classic::display() const {
  cout << year << " " << month << ", " << actor << ", " << director << ", "
       << title << " (" << stock << ") - Classics" << endl;
}

bool Classic::equals(const Movie &other) const {
  const Classic *c = dynamic_cast<const Classic *>(&other);
  return c != nullptr && year == c->year && month == c->month &&
         actor == c->actor;
}

bool Classic::lessThan(const Movie &other) const {
  const Classic *c = dynamic_cast<const Classic *>(&other);
  if (c == nullptr) {
    return false;
  }
  if (year != c->year) {
    return year < c->year;
  }
  if (month != c->month) {
    return month < c->month;
  }
  return actor < c->actor;
}

char Classic::getGenre() const { return 'C'; }

Movie *Classic::clone() const { return new Classic(*this); }

int Classic::getMonth() const { return month; }

string Classic::getActor() const { return actor; }

// Self-registration block
namespace {
bool registered = []() {
  MovieFactory::registerGenre('C', [](const std::string &line) -> Movie * {
    std::istringstream ss(line);
    int stock;
    int month;
    int year;
    std::string director;
    std::string title;
    std::string actorFirst;
    std::string actorLast;

    ss >> stock;
    ss.ignore();
    std::getline(ss, director, ',');
    std::getline(ss, title, ',');
    ss >> actorFirst >> actorLast >> month >> year;

    return new Classic(stock, director.substr(1), title.substr(1), month, year,
                       actorFirst + " " + actorLast);
  });
  return true;
}();
} // namespace
