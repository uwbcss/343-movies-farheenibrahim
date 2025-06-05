// #ifndef BORROW_H
// #define BORROW_H

// #include "command.h"
// #include <string>
// using namespace std;

// class Movie;

// class Borrow : public Command {
// private:
//   Movie *movie;
//   int customerID;

// public:
//   explicit Borrow(istream &stream);
//   ~Borrow();
//   void execute(StoreManager &store) override;
//   void display() const override;
//   Command *clone() const override;
// };

// #endif

#ifndef BORROW_H
#define BORROW_H

#include "command.h"
#include <iostream> // Needed for std::istream

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
