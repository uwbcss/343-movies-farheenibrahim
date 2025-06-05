#ifndef INVENTORY_H
#define INVENTORY_H

#include "command.h"

class Inventory : public Command {
public:
  Inventory() = default;
  void execute(StoreManager &store) override;
  void display() const override;
  Command *clone() const override;
};

#endif
