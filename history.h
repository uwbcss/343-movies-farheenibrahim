#ifndef HISTORY_H
#define HISTORY_H

#include "command.h"
#include <string>
using namespace std;

class History : public Command {
private:
  int customerID;

public:
  explicit History(istream &stream);
  void execute(StoreManager &store) override;
  void display() const override;
  Command *clone() const override;
};

#endif
