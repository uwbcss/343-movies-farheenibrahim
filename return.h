#ifndef RETURN_H
#define RETURN_H

#include "command.h"
#include "movie.h"
#include <string>
using namespace std;

class Return : public Command {
private:
  Movie *movie;
  int customerID;

public:
  explicit Return(istream &stream); // parses from input
  ~Return();                        // cleans up dynamic memory
  void execute(StoreManager &store) override;
  void display() const override;
  Command *clone() const override;
};

#endif
