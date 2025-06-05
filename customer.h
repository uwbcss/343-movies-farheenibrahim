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
