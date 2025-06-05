#ifndef INVENTORY_H
#define INVENTORY_H

#include "command.h"

class Inventory : public Command {
public:
  Inventory() = default;
  // Executes the command: displays the entire movie inventory from StoreManager
  void execute(StoreManager &store) override;
  // Displays info about this Inventory command (for debugging or logging)
  void display() const override;
  Command *clone() const override;
};

#endif
