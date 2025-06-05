#include "classic.h"
#include "movie_factory.h"
#include <iostream>
#include <sstream>

using namespace std;
// Constructor: Initializes a Classic movie with given stock, director, title,
// month, year, and actor
Classic::Classic(int stock, const std::string &director,
                 const std::string &title, int month, int year,
                 const std::string &actor)
    : Movie(stock, director, title, year), month(month), actor(actor) {}
// Displays the movie's detailed information for inventory/history
void Classic::display() const {
  cout << year << " " << month << ", " << actor << ", " << director << ", "
       << title << " (" << stock << ") - Classics" << endl;
}
// Compares this Classic to another movie for equality based on year, month, and
// actor
bool Classic::equals(const Movie &other) const {
  const Classic *c = dynamic_cast<const Classic *>(&other);
  return c != nullptr && year == c->year && month == c->month &&
         actor == c->actor;
}
// Comparison operator: Determines sort order based on year, then month, then
// actor
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
// Returns the genre character code for Classic
char Classic::getGenre() const { return 'C'; }
// Clones this Classic movie object
Movie *Classic::clone() const { return new Classic(*this); }
// Accessor for month (used in clone or comparisons)
int Classic::getMonth() const { return month; }
// Accessor for actor (used in clone or comparisons)
string Classic::getActor() const { return actor; }

// Static self-registration block to register Classic genre with MovieFactory
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

    // Parse attributes from the formatted input line
    ss >> stock;
    ss.ignore();
    std::getline(ss, director, ',');
    std::getline(ss, title, ',');
    ss >> actorFirst >> actorLast >> month >> year;
    // Return dynamically allocated Classic object
    return new Classic(stock, director.substr(1), title.substr(1), month, year,
                       actorFirst + " " + actorLast);
  });
  return true;
}();
} // namespace
