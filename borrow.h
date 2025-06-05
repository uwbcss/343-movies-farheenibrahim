#ifndef BORROW_H
#define BORROW_H

#include "command.h"
#include <iostream> 

class Movie;

class Borrow : public Command {
public:
  explicit Borrow(std::istream &stream);
  ~Borrow();

  void execute(StoreManager &store) override;
  void display() const override;
  Command *clone() const override;

private:
  int customerID;
  Movie *movie;
};

#endif
