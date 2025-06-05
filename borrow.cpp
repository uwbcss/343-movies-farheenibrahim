// // #include "borrow.h"
// // #include "command_factory.h"
// // #include "classic.h"
// // #include "comedy.h"
// // #include "customer.h"
// // #include "drama.h"
// // #include "store_manager.h"
// // #include <iostream>
// // #include <sstream>
// // using namespace std;

// // Borrow::Borrow(istream &stream) : movie(nullptr) {
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
// //     movie = new Comedy(1, "", title.substr(1), year);
// //   } else if (genre == 'D') {
// //     string director;
// //     string title;
// //     getline(stream, director, ',');
// //     getline(stream, title, ',');
// //     movie =
// //         new Drama(1, director, title.substr(1), 0); // Year not used for
// //         lookup
// //   } else if (genre == 'C') {
// //     int month;
// //     int year;
// //     string actorFirst;
// //     string actorLast;
// //     stream >> month >> year >> actorFirst >> actorLast;
// //     movie = new Classic(1, "", "", month, year, actorFirst + " " +
// //     actorLast);
// //   } else {
// //     cout << "ERROR: Unknown genre type: " << genre << endl;
// //   }
// // }

// // Borrow::~Borrow() { delete movie; }

// // void Borrow::execute(StoreManager &store) {
// //   if (!movie) {
// //     return;
// //   }
// //   Movie *actual = store.getInventory().find(movie->getGenre(), movie);
// //   if (actual != nullptr && actual->decreaseStock()) {
// //     Customer *customer = store.getCustomer(customerID);
// //     if (customer != nullptr) {
// //       customer->addToHistory(this->clone());
// //     } else {
// //       cout << "Borrow failed: Invalid customer ID " << customerID << endl;
// //     }
// //   } else {
// //     cout << "Borrow failed: Movie not available or not found." << endl;
// //   }
// // }

// // void Borrow::display() const {
// //   cout << "Borrow command for customer " << customerID << endl;
// //   if (movie !=nullptr) {
// //     movie->display();
// //   }
// // }

// // Command *Borrow::clone() const {
// //   stringstream ss;
// //   ss << customerID << " D " << movie->getGenre() << " ";

// //   if (movie->getGenre() == 'F') {
// //     ss << movie->getTitle() << ", " << movie->getYear();
// //   } else if (movie->getGenre() == 'D') {
// //     ss << movie->getDirector() << ", " << movie->getTitle();
// //   } else if (movie->getGenre() == 'C') {
// //     Classic *c = dynamic_cast<Classic *>(movie);
// //     if (c != nullptr) {
// //       ss << c->getMonth() << " " << c->getYear() << " " << c->getActor();
// //     }
// //   }

// //   return new Borrow(ss);

// // }

// #include "borrow.h"
// #include "classic.h"
// #include "comedy.h"
// #include "customer.h"
// #include "drama.h"
// #include "store_manager.h"
// #include "command_factory.h"
// #include <iostream>
// #include <sstream>
// using namespace std;

// Borrow::Borrow(istream &stream) : movie(nullptr) {
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
//             cout << "Borrow failed: Missing or malformed Comedy title." <<
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

// Borrow::~Borrow() {
//     delete movie;
// }

// void Borrow::execute(StoreManager &store) {
//     if (!movie) return;

//     Movie *actual = store.getInventory().find(movie->getGenre(), movie);
//     if (actual && actual->decreaseStock()) {
//         Customer *customer = store.getCustomer(customerID);
//         if (customer) {
//             customer->addToHistory(this->clone());
//         } else {
//             cout << "Borrow failed: Invalid customer ID " << customerID <<
//             endl;
//         }
//     } else {
//         cout << "Borrow failed: Movie not available or not found." << endl;
//     }
// }

// void Borrow::display() const {
//     cout << "Borrow command for customer " << customerID << endl;
//     if (movie) movie->display();
// }

// Command *Borrow::clone() const {
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
//     return new Borrow(ss);
// }

// // Self-registration
// namespace {
//     bool registered = []() {
//         CommandFactory::registerType('B', [](istream &s) { return new
//         Borrow(s); }); return true;
//     }();
// }

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
Borrow::Borrow(istream &stream) : movie(nullptr) {
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
Borrow::~Borrow() { delete movie; }
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
void Borrow::display() const {
  cout << "Borrow command for customer " << customerID << endl;
  if (movie != nullptr) {
    movie->display();
  }
}
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
namespace {
bool registered = []() {
  CommandFactory::registerType('B', [](istream &s) { return new Borrow(s); });
  return true;
}();
} // namespace
