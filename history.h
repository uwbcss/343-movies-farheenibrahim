#ifndef HISTORY_H
#define HISTORY_H

#include "command.h"
#include <string>
using namespace std;

class History : public Command {
private:
  int customerID;

public:
  // Constructor: parses input stream to initialize the customer ID
  explicit History(istream &stream);
  void execute(StoreManager &store) override;
  void display() const override;
  // Creates and returns a polymorphic copy of this History command object
  Command *clone() const override;
};

#endif
