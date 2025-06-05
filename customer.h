// #ifndef CUSTOMER_H
// #define CUSTOMER_H

// #include <string>
// #include <vector>

// class Command;

// class Customer {
// public:
//   Customer(int id, std::string first, std::string last);
//   ~Customer();

//   void addToHistory(Command *cmd);
//   void displayHistory() const;

//   int getID() const;
//   std::string getName() const;

// private:
//   int customerID;
//   std::string firstName;
//   std::string lastName;
//   std::vector<Command *> history;
// };

// #endif

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
using namespace std;

class Command;

class Customer {
public:
  Customer(int id, string last, string first);
  ~Customer();

  void addToHistory(Command *cmd);
  void displayHistory() const;

  int getID() const;
  string getName() const;
  string getFirstName() const; // NEW
  string getLastName() const;  // NEW

private:
  int CustomerID;
  string firstName;
  string lastName;
  vector<Command *> history;
};

#endif
