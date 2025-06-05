#include "history.h"
#include "command_factory.h"
#include "store_manager.h"
#include <iostream>
#include <sstream>

using namespace std;
// Constructor: Parses the History command input
// Extracts the customer ID from the input stream
History::History(istream &stream) { stream >> customerID; }
// Executes the History command:
// - Looks up the customer in the store
// - If found, calls displayHistory() to show their transaction history
void History::execute(StoreManager &store) {
  Customer *customer = store.getCustomer(customerID);
  if (customer != nullptr) {
    customer->displayHistory();
  } else {
    cout << "History failed: Customer not found.\n";
  }
}
// Displays a simple message identifying this as a History command
// (More detailed history is handled inside Customer::displayHistory)
void History::display() const { cout << "History command\n"; }
// Clones the History command
// Used to store this command in customer history (deep copy)
Command *History::clone() const {
  stringstream ss;
  ss << customerID;
  return new History(ss);
}

// Self-registration block:
// Registers the History command ('H') with CommandFactory
// Allows dynamic creation of History commands via factory pattern
namespace {
bool registered = []() {
  CommandFactory::registerType('H', [](istream &s) { return new History(s); });
  return true;
}();
} // namespace
