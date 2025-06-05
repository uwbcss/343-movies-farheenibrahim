// // #include "return.h"
// // #include "classic.h"
// // #include "comedy.h"
// // #include "customer.h"
// // #include "drama.h"
// // #include "store_manager.h"
// // #include <iostream>
// // #include <sstream>
// // using namespace std;

// // Return::Return(istream &stream) : movie(nullptr) {
// //   char mediaType;
// //   char genre;
// //   stream >> customerID >> mediaType >> genre;

// //   if (mediaType != 'D') {
// //     cout << "ERROR: Unsupported media type: " << mediaType << endl;
// //     return;
// //   }

// //   if (genre == 'F') {
// //     string title;
// //     getline(stream, title, ',');
// //     int year;
// //     stream >> year;
// //     movie = new Comedy(1, "", title.substr(1),
// //                        year); // title.substr(1) removes leading space
// //   } else if (genre == 'D') {
// //     string director, title;
// //     getline(stream, director, ',');
// //     getline(stream, title, ',');
// //     movie = new Drama(1, director, title.substr(1), 0);
// //   } else if (genre == 'C') {
// //     int month, year;
// //     string actorFirst, actorLast;
// //     stream >> month >> year >> actorFirst >> actorLast;
// //     movie = new Classic(1, "", "", month, year, actorFirst + " " +
// //     actorLast);
// //   } else {
// //     cout << "ERROR: Unknown genre type: " << genre << endl;
// //   }
// // }

// // Return::~Return() { delete movie; }

// // void Return::execute(StoreManager &store) {
// //   if (!movie) {
// //     return;
// //   }
// //   Movie *actual = store.getInventory().find(movie->getGenre(), movie);
// //   if (!actual) {
// //     cout << "Return failed: Movie not found in inventory." << endl;
// //     return;
// //   }

// //   actual->increaseStock();

// //   Customer *customer = store.getCustomer(customerID);
// //   if (customer) {
// //     customer->addToHistory(this->clone());
// //   } else {
// //     cout << "Return failed: Invalid customer ID " << customerID << endl;
// //   }
// // }

// // void Return::display() const {
// //   cout << "Return command for customer " << customerID << endl;
// //   if (movie)
// //     movie->display();
// // }

// // Command *Return::clone() const {
// //   // Serialize internal state back to a stream
// //   stringstream ss;
// //   ss << customerID << " D " << movie->getGenre() << " ";

// //   // Serialize movie details based on genre
// //   if (movie->getGenre() == 'F') {
// //     ss << movie->getTitle() << ", " << movie->getYear();
// //   } else if (movie->getGenre() == 'D') {
// //     ss << movie->getDirector() << ", " << movie->getTitle();
// //   } else if (movie->getGenre() == 'C') {
// //     const Classic *c = dynamic_cast<const Classic *>(movie);
// //     if (c) {
// //       ss << c->getMonth() << " " << c->getYear() << " " << c->getActor();
// //     }
// //   }

// //   return new Return(ss); // Construct a new Return from the serialized
// stream
// // }

// #include "return.h"
// #include "classic.h"
// #include "comedy.h"
// #include "command_factory.h"
// #include "customer.h"
// #include "drama.h"
// #include "store_manager.h"
// #include <iostream>
// #include <sstream>
// using namespace std;

// Return::Return(istream &stream) : movie(nullptr) {
//     char mediaType, genre;
//     stream >> customerID >> mediaType >> genre;

//     if (mediaType != 'D') {
//         cout << "ERROR: Unsupported media type: " << mediaType << endl;
//         return;
//     }

// #ifdef INCLUDE_COMEDY
//     if (genre == 'F') {
//         string title;
//         getline(stream, title, ',');
//         int year;
//         stream >> year;

//         if (!title.empty()) {
//             title.erase(0, title.find_first_not_of(" \t"));
//             movie = new Comedy(1, "", title, year);
//         } else {
//             cout << "Return failed: Missing or malformed Comedy title." <<
//             endl;
//         }
//     } else
// #endif
//     if (genre == 'D') {
//         string director, title;
//         getline(stream, director, ',');
//         getline(stream, title, ',');

//         if (!director.empty()) director.erase(0, director.find_first_not_of("
//         \t")); if (!title.empty()) title.erase(0, title.find_first_not_of("
//         \t"));

//         movie = new Drama(1, director, title, 0);
//     } else if (genre == 'C') {
//         int month, year;
//         string actorFirst, actorLast;
//         stream >> month >> year >> actorFirst >> actorLast;

//         movie = new Classic(1, "", "", month, year, actorFirst + " " +
//         actorLast);
//     } else {
//         cout << "ERROR: Unknown genre type: " << genre << endl;
//     }
// }

// Return::~Return() {
//     delete movie;
// }

// void Return::execute(StoreManager &store) {
//     if (!movie) return;

//     Movie *actual = store.getInventory().find(movie->getGenre(), movie);
//     if (!actual) {
//         cout << "Return failed: Movie not found in inventory." << endl;
//         return;
//     }

//     actual->increaseStock();

//     Customer *customer = store.getCustomer(customerID);
//     if (customer) {
//         customer->addToHistory(this->clone());
//     } else {
//         cout << "Return failed: Invalid customer ID " << customerID << endl;
//     }
// }

// void Return::display() const {
//     cout << "Return command for customer " << customerID << endl;
//     if (movie) movie->display();
// }

// Command *Return::clone() const {
//     stringstream ss;
//     ss << customerID << " D " << movie->getGenre() << " ";
//     if (movie->getGenre() == 'F') {
//         ss << movie->getTitle() << ", " << movie->getYear();
//     } else if (movie->getGenre() == 'D') {
//         ss << movie->getDirector() << ", " << movie->getTitle();
//     } else if (movie->getGenre() == 'C') {
//         const Classic *c = dynamic_cast<const Classic *>(movie);
//         if (c) ss << c->getMonth() << " " << c->getYear() << " " <<
//         c->getActor();
//     }
//     return new Return(ss);
// }

// // Self-registration
// namespace {
//     bool registered = []() {
//         CommandFactory::registerType('R', [](istream &s) { return new
//         Return(s); }); return true;
//     }();
// }

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

Return::Return(istream &stream) : movie(nullptr) {
  char mediaType;
  char genre;
  stream >> customerID >> mediaType >> genre;

  if (mediaType != 'D') {
    cout << "ERROR: Unsupported media type: " << mediaType << endl;
    return;
  }

#ifdef INCLUDE_COMEDY
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
      if (genre == 'D') {
    string director;
    string title;
    getline(stream, director, ',');
    getline(stream, title, ',');

    director.erase(0, director.find_first_not_of(" \t"));
    title.erase(0, title.find_first_not_of(" \t"));

    movie = new Drama(1, director, title, 0);
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

Return::~Return() { delete movie; }

void Return::execute(StoreManager &store) {
  if (movie == nullptr) {
    return;
  }

  Movie *actual = store.getInventory().find(movie->getGenre(), movie);
  if (actual == nullptr) {
    cout << "Return failed: Movie not found in inventory." << endl;
    return;
  }

  actual->increaseStock();

  Customer *customer = store.getCustomer(customerID);
  if (customer != nullptr) {
    customer->addToHistory(this->clone());
  } else {
    cout << "Return failed: Invalid customer ID " << customerID << endl;
  }
}

void Return::display() const {
  cout << "Return command for customer " << customerID << endl;
  if (movie != nullptr) {
    movie->display();
  }
}

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
  return new Return(ss);
}

namespace {
bool registered = []() {
  CommandFactory::registerType('R', [](istream &s) { return new Return(s); });
  return true;
}();
} // namespace
