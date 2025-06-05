// #include "history.h"
// #include "store_manager.h"
// #include "borrow.h"
// #include "command_factory.h"

// #include <iostream>
// #include <sstream>
// using namespace std;
// History::History(istream &stream) { stream >> customerID; }

// void History::execute(StoreManager &store) {
//   Customer *customer = store.getCustomer(customerID);
//   if (customer) {
//     customer->displayHistory();
//   } else {
//     cout << "History failed: Customer not found.\n";
//   }
// }

// void History::display() const { cout << "History command\n"; }

// Command *History::clone() const {
//   stringstream ss;
//   ss << customerID;
//   return new History(ss);
// }

// //add new
// namespace {
//   bool registered = []() {
//     CommandFactory::registerType('H', [](istream &s) { return new History(s);
//     }); return true;
//   }();
// }

#include "history.h"
#include "command_factory.h"
#include "store_manager.h"
#include <iostream>
#include <sstream>

using namespace std;

History::History(istream &stream) { stream >> customerID; }

void History::execute(StoreManager &store) {
  Customer *customer = store.getCustomer(customerID);
  if (customer != nullptr) {
    customer->displayHistory();
  } else {
    cout << "History failed: Customer not found.\n";
  }
}

void History::display() const { cout << "History command\n"; }

Command *History::clone() const {
  stringstream ss;
  ss << customerID;
  return new History(ss);
}

// Self-registration
namespace {
bool registered = []() {
  CommandFactory::registerType('H', [](istream &s) { return new History(s); });
  return true;
}();
} // namespace
