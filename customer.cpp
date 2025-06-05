// #include "customer.h"
// #include "command.h"
// #include <iostream>

// using namespace std;

// Customer::Customer(int id, string first, string last)
//     : customerID(id), firstName(first), lastName(last) {}

// Customer::~Customer() {}

// void Customer::addToHistory(Command *cmd) { history.push_back(cmd); }

// void Customer::displayHistory() const {
//   cout << "History for " << firstName << " " << lastName << ":" << endl;
//   if (history.empty()) {
//     cout << "No history available." << endl;
//   } else {
//     for (const auto &cmd : history) {
//       cmd->display();
//     }
//   }
// }

// int Customer::getID() const { return customerID; }

// string Customer::getName() const { return firstName + " " + lastName; }

#include "customer.h"
#include "command.h"
#include <iostream>
using namespace std;

Customer::~Customer() {}

Customer::Customer(int id, string last, string first)
    : CustomerID(id), firstName(first), lastName(last) {}

void Customer::addToHistory(Command *cmd) { history.push_back(cmd); }

void Customer::displayHistory() const {
  cout << "==========================" << endl;
  cout << "History for " << CustomerID << " " << lastName << " " << firstName
       << ":" << endl;

  if (history.empty()) {
    cout << "No history for " << firstName << " " << lastName << endl;
  } else {
    for (const auto &cmd : history) {
      cmd->display();
    }
  }
}

int Customer::getID() const { return CustomerID; }

string Customer::getName() const { return firstName + " " + lastName; }

string Customer::getFirstName() const { return firstName; }

string Customer::getLastName() const { return lastName; }
