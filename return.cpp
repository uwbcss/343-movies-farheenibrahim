#include "return.h"
#include "classic.h"
#include "comedy.h"
#include "command_factory.h"
#include "customer.h"
#include "drama.h"
#include "store_manager.h"

#include <iostream>
#include <sstream>
using namespace std;
// Constructor: Parses a Return command from the input stream
// Initializes the customerID and constructs the correct Movie object
// depending on the genre specified.
Return::Return(istream &stream) : movie(nullptr) {
  char mediaType;
  char genre;
  stream >> customerID >> mediaType >> genre;

  if (mediaType != 'D') {
    cout << "ERROR: Unsupported media type: " << mediaType << endl;
    return;
  }

#ifdef INCLUDE_COMEDY
  // Comedy: Format -> Title, Year, Director
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
    // Drama: Format -> Director, Title
    if (genre == 'D') {
      string director;
      string title;
      getline(stream, director, ',');
      getline(stream, title, ',');

      director.erase(0, director.find_first_not_of(" \t"));
      title.erase(0, title.find_first_not_of(" \t"));

      movie = new Drama(1, director, title, 0);
      // Classic: Format -> Month Year ActorFirst ActorLast
    } else if (genre == 'C') {
      int month;
      int year;
      string actorFirst;
      string actorLast;
      stream >> month >> year >> actorFirst >> actorLast;

      movie = new Classic(1, "", "", month, year, actorFirst + " " + actorLast);
    } else {
      // Invalid genre code
      cout << "ERROR: Unknown genre type: " << genre << endl;
    }
}
// Destructor: Deletes the dynamically allocated Movie object
Return::~Return() { delete movie; }
// Executes the return transaction:
// - Finds the matching movie in inventory
// - Increases its stock
// - Records the return in the customer's transaction history
void Return::execute(StoreManager &store) {
  if (movie == nullptr) {
    return;
  }

  Movie *actual = store.getInventory().find(movie->getGenre(), movie);
  if (actual == nullptr) {
    cout << "Return failed: Movie not found in inventory." << endl;
    return;
  }

  actual->increaseStock(); // Return the movie (increment stock)

  Customer *customer = store.getCustomer(customerID);
  if (customer != nullptr) {
    customer->addToHistory(this->clone()); // Record return in history
  } else {
    cout << "Return failed: Invalid customer ID " << customerID << endl;
  }
}
// Displays the return command in a human-readable format
void Return::display() const {
  cout << "Return command for customer " << customerID << endl;
  if (movie != nullptr) {
    movie->display();
  }
}
// Clones this command (deep copy) so it can be stored in history
Command *Return::clone() const {
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
  // Return a new instance based on serialized command format
  return new Return(ss);
}
// Self-registration block: registers 'R' Return command with the CommandFactory
namespace {
bool registered = []() {
  CommandFactory::registerType('R', [](istream &s) { return new Return(s); });
  return true;
}();
} // namespace
