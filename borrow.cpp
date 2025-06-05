#include "borrow.h"
#include "classic.h"
#include "comedy.h"
#include "command_factory.h"
#include "customer.h"
#include "drama.h"
#include "store_manager.h"
#include <iostream>
#include <sstream>
using namespace std;
// Constructor: Parses a Borrow command from the given input stream.
// Initializes a movie object based on genre and sorting keys.
Borrow::Borrow(istream &stream) : movie(nullptr) {
  char mediaType;
  char genre;
  stream >> customerID >> mediaType >> genre;
  // Check if media type is supported (currently only 'D' for DVD)
  if (mediaType != 'D') {
    cout << "ERROR: Unsupported media type: " << mediaType << endl;
    return;
  }
#ifdef INCLUDE_COMEDY
  // Parse Comedy: title, year, then director
  if (genre == 'F') {
    string title;
    string director;
    getline(stream, title, ',');
    int year;
    stream >> year;
    title.erase(0, title.find_first_not_of(" \t"));
    getline(stream, director, ',');
    director.erase(0, director.find_first_not_of(" \t"));
    movie = new Comedy(1, director, title, year);
  } else
#endif
    // Parse Drama: director, title
    if (genre == 'D') {
      string director;
      string title;
      getline(stream, director, ',');
      getline(stream, title, ',');
      director.erase(0, director.find_first_not_of(" \t"));
      title.erase(0, title.find_first_not_of(" \t"));
      movie =
          new Drama(1, director, title, 0); // year not needed for comparison
    } else if (genre == 'C') {
      int month;
      int year;
      string actorFirst;
      string actorLast;
      stream >> month >> year >> actorFirst >> actorLast;
      movie = new Classic(1, "", "", month, year, actorFirst + " " + actorLast);
    } else {
      cout << "ERROR: Unknown genre type: " << genre << endl;
    }
}
// Destructor: Frees dynamically allocated movie pointer
Borrow::~Borrow() { delete movie; }
// Executes the Borrow command:
// Finds the movie in inventory, decrements stock if available,
// and adds the transaction to the customer's history.
void Borrow::execute(StoreManager &store) {
  if (movie == nullptr) {
    return;
  }
  Movie *actual = store.getInventory().find(movie->getGenre(), movie);
  if (actual != nullptr && actual->decreaseStock()) {
    Customer *customer = store.getCustomer(customerID);
    if (customer != nullptr) {
      customer->addToHistory(this->clone());
    } else {
      cout << "Borrow failed: Invalid customer ID " << customerID << endl;
    }
  } else {
    cout << "Borrow failed: Movie not available or not found." << endl;
  }
}
// Displays the borrow command and associated movie details
void Borrow::display() const {
  cout << "Borrow command for customer " << customerID << endl;
  if (movie != nullptr) {
    movie->display();
  }
}
// Creates a deep copy (clone) of this Borrow command.
// Used when adding to customer history.
Command *Borrow::clone() const {
  stringstream ss;
  ss << customerID << " D " << movie->getGenre() << " ";
  if (movie->getGenre() == 'F') {
    ss << movie->getTitle() << ", " << movie->getYear() << ", "
       << movie->getDirector();
  } else if (movie->getGenre() == 'D') {
    ss << movie->getDirector() << ", " << movie->getTitle();
  } else if (movie->getGenre() == 'C') {
    const Classic *c = dynamic_cast<const Classic *>(movie);
    if (c != nullptr) {
      ss << c->getMonth() << " " << c->getYear() << " " << c->getActor();
    }
  }
  return new Borrow(ss);
}
// Static registration of the Borrow command in the CommandFactory
namespace {
bool registered = []() {
  CommandFactory::registerType('B', [](istream &s) { return new Borrow(s); });
  return true;
}();
} // namespace
