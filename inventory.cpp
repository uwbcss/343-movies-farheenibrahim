#include "inventory.h"
#include "command_factory.h"
#include "store_manager.h"
#include <iostream>

using namespace std;
// Executes the Inventory command:
// Iterates over all movie genres ('F' = Comedy, 'D' = Drama, 'C' = Classic),
// retrieves the list of movies in each genre from the store's inventory,
// and displays each movie using its polymorphic display() method.
void Inventory::execute(StoreManager &store) {
  for (char genre : {'F', 'D', 'C'}) {
    for (Movie *m : store.getInventory().getCategory(genre)) {
      m->display();
    }
  }
}

// Displays a simple message identifying this as an Inventory command.
// This is used when displaying the command itself in customer history.
void Inventory::display() const { cout << "Inventory command\n"; }

// Creates a deep copy of this Inventory command.
// Used when storing this command in a customer’s transaction history.
Command *Inventory::clone() const { return new Inventory(*this); }

// Self-registration
namespace {
bool registered = []() {
  CommandFactory::registerType('I', [](istream &) { return new Inventory(); });
  return true;
}();
} // namespace
