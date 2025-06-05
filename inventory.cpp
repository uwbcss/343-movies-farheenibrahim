//

#include "inventory.h"
#include "command_factory.h"
#include "store_manager.h"
#include <iostream>

using namespace std;

// Inventory::Inventory() = default;

void Inventory::execute(StoreManager &store) {
  for (char genre : {'F', 'D', 'C'}) {
    for (Movie *m : store.getInventory().getCategory(genre)) {
      m->display();
    }
  }
}

void Inventory::display() const { cout << "Inventory command\n"; }

Command *Inventory::clone() const { return new Inventory(*this); }

// Self-registration
namespace {
bool registered = []() {
  CommandFactory::registerType('I', [](istream &) { return new Inventory(); });
  return true;
}();
} // namespace
